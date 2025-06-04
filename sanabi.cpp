#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> 
#include <tchar.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <list>
#include "Resource.h"
#include "pch.cpp"
#include "block.h"
#pragma comment (lib, "msimg32.lib")
#pragma comment(lib, "gdi32.lib")

#define animationtimer 3
#define gravitytimer 4

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"windows program 1";
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

HBITMAP hBitCha[6];
HBITMAP hBitCha2[6];
typedef enum Shape {
	rectangle,
	line,
	dia,
	pentagon,
	pie,
	circle
}SHAPE;

typedef struct merge {
	int x1, x2;
	int y1, y2;

	int anistate;
	int color;
	RECT rt;
}MERGE;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW,
		0, 0, 1024, 780, NULL, LoadMenu(hInstance, NULL), hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);



	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	//window program winpro help hard
	PAINTSTRUCT ps;
	HDC hDC,mDC, mapDC, playerDC, cursorDC, bgDC, ptempDC, reverseDC;
	static HBITMAP hBitmap, mapbitmap, playerbitmap, cursorbitmap, bgbitmap, ptempbitmap, reversebitmap;
	static BITMAP bmp;
	static TCHAR temp[100];
	HPEN hPen, oldPen, whitepen;
	HBRUSH hBrush, oldBrush;
	static RECT rect;
	static int xmiddle, ymiddle;
	static RECT map;
	static MERGE player;
	static int mx;
	static int my;
	static int px, py;
	static int anchorx, anchory;

	static int wireon;
	static int direction;
	static double radian;
	static double length;
	static int directiontemp;

	static RECT hitbox;
	static int inair;
	static int jumpend;
	static int jumptimer = 30;

	static int prelativex;
	static int prelativey;
	static int carmerax;
	static int carmeray;
	static int anchorinblock;

	static int pdirection = 1;
	static int anitimer = 0;
	static int maxanistate = 8;
	static int anistate = 0;
	

	switch (iMessage) {
	case WM_CREATE:
	{
		GetClientRect(hWnd, &rect);
		init_blocks();
		srand(time(NULL));

		mapbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		playerbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		cursorbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		bgbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		xmiddle = rect.right / 2;
		ymiddle = rect.bottom / 2;
		GetObject(mapbitmap, sizeof(BITMAP), &bmp);

		map.left = 0;
		map.right = bmp.bmWidth;
		map.bottom = bmp.bmHeight;
		map.top = 0;


		px = xmiddle;
		py = map.bottom - ymiddle;
		//py = ymiddle;

		player.rt.top = py - 40;
		player.rt.bottom = player.rt.top + 80;
		player.rt.left = px - 40;
		player.rt.right = player.rt.left + 80;

		SetTimer(hWnd, animationtimer, 100, NULL);
		SetTimer(hWnd, gravitytimer, 27, NULL);
	}
	break;
	case WM_PAINT:
	{
		GetClientRect(hWnd, &rect);
		hDC = BeginPaint(hWnd, &ps);
		mDC = CreateCompatibleDC(hDC);
		hBitmap = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
		ptempDC = CreateCompatibleDC(mDC);
		ptempbitmap = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
		reverseDC = CreateCompatibleDC(mDC);
		reversebitmap = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
		


		playerDC = CreateCompatibleDC(mDC);
		cursorDC = CreateCompatibleDC(mDC);
		bgDC = CreateCompatibleDC(mDC);
		mapDC = CreateCompatibleDC(mDC);


		HBITMAP oldBitmap, oldBgBitmap, oldPlayerBitmap, oldCursorBitmap, oldMapBitmap, oldptempBitmap, oldreverseBitmap;

		// mDC에 hBitmap 선택
		oldBitmap = (HBITMAP)SelectObject(mDC, hBitmap);
		oldptempBitmap = (HBITMAP)SelectObject(ptempDC, ptempbitmap);
		oldreverseBitmap = (HBITMAP)SelectObject(reverseDC, reversebitmap);
		// 각 DC에 비트맵 선택
		oldPlayerBitmap = (HBITMAP)SelectObject(playerDC, playerbitmap);
		oldCursorBitmap = (HBITMAP)SelectObject(cursorDC, cursorbitmap);
		oldMapBitmap = (HBITMAP)SelectObject(mapDC, mapbitmap);
		oldBgBitmap = (HBITMAP)SelectObject(bgDC, bgbitmap);


		hPen = CreatePen(PS_DOT, 1, RGB(0, 255, 255));
		oldPen = (HPEN)SelectObject(hDC, hPen);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
		FillRect(mDC, &rect, hBrush);
		
		StretchBlt(mDC, 0, 0, rect.right, rect.bottom + 202, bgDC, 0, 0, 582, rect.bottom, SRCCOPY);

		player.rt.top = py - 40;
		player.rt.bottom = player.rt.top + 80;
		player.rt.left = px - 40;
		player.rt.right = player.rt.left + 80;
		/*
		int carmerax = player.rt.left + 40;
		int carmeray = player.rt.top + 40;*/


		carmerax = px;
		carmeray = py;

		if (carmerax < xmiddle) {
			carmerax = xmiddle;
		}
		if (carmeray + ymiddle > bmp.bmHeight) { // 보스맵 바닥 y좌표 1331
			carmeray -= carmeray + ymiddle - bmp.bmHeight;
		}


		/*anchorx = mx;
		anchory = my;


		anchorx -= xmiddle;
		anchory -= ymiddle;
		anchorx += carmerax;
		anchory += carmeray;*/

		TransparentBlt(mDC, map.left - carmerax + xmiddle, map.top - carmeray + ymiddle, bmp.bmWidth, bmp.bmHeight, mapDC, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(255, 255, 255));
		
		int spritesxpos = anitimer * 80;
		int spritesypos = anistate * 80;

		
		//spritesxpos = 0;

		prelativex = px - carmerax + xmiddle;
		prelativey = py - carmeray + ymiddle;


		//TransparentBlt(mDC, px - carmerax - 40 + xmiddle, py - carmeray - 40 + ymiddle, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, RGB(255, 255, 255));
		
		FillRect(reverseDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		if (pdirection == 1) {
			StretchBlt(reverseDC, 0, 0, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, SRCCOPY);
		}
		else {
			StretchBlt(reverseDC, 0, 0, 80, 80, playerDC, spritesxpos + 80, spritesypos, -80, 80, SRCCOPY);
		}
		if (wireon) {
			mx = anchorx - carmerax + xmiddle;
			my = anchory - carmeray + ymiddle;

			//TransparentBlt(tempDC, prelativex - 40, prelativey - 40, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, RGB(255, 255, 255));
			
			FillRect(ptempDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
			POINT outPts[3];
			double cosA = cos(radian + 1.57);
			double sinA = sin(radian + 1.57);
			int hw = 40;
			int hh = 40;


			outPts[0].x = static_cast<LONG>(spritesxpos + 40 + (-hw * cosA - (-hh) * sinA));
			outPts[0].y = static_cast<LONG>(spritesypos + 40 + (-hw * sinA + (-hh) * cosA));

			// 오른쪽 위
			outPts[1].x = static_cast<LONG>(spritesxpos + 40 + (hw * cosA - (-hh) * sinA));
			outPts[1].y = static_cast<LONG>(spritesypos + 40 + (hw * sinA + (-hh) * cosA));

			// 왼쪽 아래
			outPts[2].x = static_cast<LONG>(spritesxpos + 40 + (-hw * cosA - hh * sinA));
			outPts[2].y = static_cast<LONG>(spritesypos + 40 + (-hw * sinA + hh * cosA));

			//PlgBlt(mDC, outPts, tempDC, prelativex - 40, prelativey - 40, 80, 80, NULL, 0, 0);
			//StretchBlt(reverseDC, 0, 0, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, SRCCOPY);

			PlgBlt(ptempDC, outPts, reverseDC, 0, 0, 80, 80, NULL, 0, 0);
			
			TransparentBlt(mDC, prelativex - 40, prelativey - 40, 80, 80, ptempDC, spritesxpos, spritesypos, 80, 80, RGB(255, 255, 255));
		}
		else {
			TransparentBlt(mDC, prelativex - 40, prelativey - 40, 80, 80, reverseDC, 0, 0, 80, 80, RGB(255, 255, 255));
		}

		anchorinblock = 0;

		if (!wireon) {
			POINT anchorp = { anchorx, anchory };
			double imradian = atan2(anchory - py, anchorx - px);
			int wirelength;
			for (wirelength = 0; wirelength < 500; ++wirelength) {
				anchorp.x = px + cos(imradian) * wirelength;
				anchorp.y = py + sin(imradian) * wirelength;

				int chk = 0;
				for (int i = 0; i < 147; ++i) {
					if (PtInRect(&blocks[i].rt, anchorp)) {
						if (blocks[i].grass_plag == TRUE) {
							anchorinblock = 1;
						}
						anchorx = anchorp.x;
						anchory = anchorp.y;
						chk = 1;
						break;
					}
				}
				if (chk) {
					break;
				}
			}
		}
		/*anchorp.x = px;
		anchorp.y = py;*/

		

		

		mx = anchorx - carmerax + xmiddle;
		my = anchory - carmeray + ymiddle;

		if (anchorinblock) {
			TransparentBlt(mDC, mx - 64, my - 64, 128, 128, cursorDC, 0, 0, 128, 128, RGB(255, 255, 255));
		}
		else {
			TransparentBlt(mDC, mx - 32, my - 32, 64, 64, cursorDC, 128, 0, 128, 128, RGB(255, 255, 255));
		}
		
		
		/*POINT P[2] = { {prelativex, prelativey},{mx, my} };
		Polygon(mDC, P, 2);*/

		BitBlt(hDC, 0, 0, rect.right, rect.bottom, mDC, 0, 0, SRCCOPY);
		MoveToEx(hDC, prelativex, prelativey, NULL);
		LineTo(hDC, mx, my);

		MoveToEx(hDC, prelativex, prelativey, NULL);
		LineTo(hDC, prelativex, prelativey + 25);
		LineTo(hDC, prelativex + 15, prelativey + 15);
		LineTo(hDC, prelativex - 15, prelativey + 15);

		wsprintf(temp, L"x = %d y = %d", anchorx, anchory);
		TextOut(hDC, xmiddle, ymiddle, temp, lstrlen(temp));

		SelectObject(hDC, oldPen);
		DeleteObject(hPen);
		SelectObject(mDC, oldBrush);
		DeleteObject(hBrush);

		//plg하기위한 임시 dc
		
		//

		SelectObject(mDC, oldBitmap);
		SelectObject(playerDC, oldPlayerBitmap);
		SelectObject(cursorDC, oldCursorBitmap);
		SelectObject(mapDC, oldMapBitmap);
		SelectObject(bgDC, oldBgBitmap);
		SelectObject(ptempDC, oldptempBitmap);
		SelectObject(reverseDC, oldreverseBitmap);

		DeleteObject(hBitmap);
		DeleteObject(ptempbitmap);
		DeleteObject(reversebitmap);

		DeleteDC(mDC);
		DeleteDC(ptempDC);
		DeleteDC(reverseDC);
		DeleteDC(playerDC);
		DeleteDC(cursorDC);
		DeleteDC(mapDC);
		DeleteDC(bgDC);



		EndPaint(hWnd, &ps);
		break;

	}			 break;
	case WM_CHAR:
		hDC = GetDC(hWnd);

		if (wParam == 'p') {
			int ki = anchorx;
			int vv = anchory;
		}

		if (wParam == 'q') {
			PostQuitMessage(0);
		}

		if (wParam == 'w') {
			py -= 10;
		}

		if (wParam == 's') {
			py += 10;
		}
		
		if (wParam == 'a') {
			pdirection = -1;

			int iscolide = 0;

			int grasscolide = 0;
			RECT coliderect[2];


			int g = 0;

			for (int i = 0; i < 147; ++i) {
				if (IntersectRect(&coliderect[g], &hitbox, &blocks[i].rt)) {

					if (coliderect[g].bottom - coliderect[g].top > 10 && coliderect[g].left == hitbox.left) {
						iscolide = 1;
						++g;
					}


				}
			}
			if (!iscolide) {
				px -= 10;
			}


			if (anistate == 0) {
				anistate = 1;
				anitimer = 0;
				maxanistate = 10;
			}
		}

		if (wParam == 'd') {
			pdirection = 1;

			int iscolide = 0;

			int grasscolide = 0;
			RECT coliderect[2];
			

			int g = 0;

			for (int i = 0; i < 147; ++i) {
				if (IntersectRect(&coliderect[g], &hitbox, &blocks[i].rt)) {

					if (coliderect[g].bottom - coliderect[g].top > 10 && coliderect[g].right == hitbox.right) {
						iscolide = 1;
						++g;
					}


				}
			}
			if (!iscolide) {
				px += 10;
			}

			if (anistate == 0) {
				anistate = 1;
				anitimer = 0;
				maxanistate = 10;
			}
		}

		InvalidateRect(hWnd, NULL, 0);
		ReleaseDC(hWnd, hDC);
		break;

	case WM_KEYUP:
	{
		if (wParam == 'D') {
			
			anistate = 0;
			anitimer = 0;
			maxanistate = 8;
		}
		if (wParam == 'A') {

			anistate = 0;
			anitimer = 0;
			maxanistate = 8;
		}

	}
	InvalidateRect(hWnd, NULL, 0);
	break;

	case WM_KEYDOWN:
		if (wParam == VK_SPACE) {
			if (inair == 0) {
				jumptimer = 0;
			}
		}
		InvalidateRect(hWnd, NULL, 0);
		break;
	case WM_COMMAND:
	{

	}
	//InvalidateRect(hWnd, NULL, 0);
	break;
	case WM_TIMER:
	{
		switch (wParam) {
		case 1:
		{
			if (direction == 1) {
				radian -= 0.1;
			}
			else if (direction == -1) {
				radian += 0.1;
			}

			int iscolide = 0;

			int grasscolide = 0;
			int headcolide = 0;
			RECT coliderect;

			for (int i = 0; i < 147; ++i) {
				if (IntersectRect(&coliderect, &hitbox, &blocks[i].rt)) {
					if (coliderect.right - coliderect.left > 10 && coliderect.bottom == hitbox.bottom) {

						grasscolide = 1;
					}
					if (coliderect.right - coliderect.left > 10 && coliderect.top == hitbox.top) {

						headcolide = 1;
					}

					iscolide = 1;
				}
			}

			/*if (!grasscolide && iscolide) {
				if (direction == 1) {
					radian += 0.1;
				}
				else if (direction == -1) {
					radian -= 0.1;
				}
				py = anchory - sin(radian) * length;
				px = anchorx - cos(radian) * length;
			}
			else if (grasscolide && iscolide) {
				px = anchorx - cos(radian) * length;
				
			}
			else {
				py = anchory - sin(radian) * length;
				px = anchorx - cos(radian) * length;
			}*/
			if (iscolide) {
				if (direction == 1) {
					radian += 0.1;
				}
				else if (direction == -1) {
					radian -= 0.1;
				}
			}
			py = anchory - sin(radian) * length;
			px = anchorx - cos(radian) * length;

			if (headcolide) {
				wireon = 0;

				anistate = 0;
				anitimer = 0;
				maxanistate = 8;
				KillTimer(hWnd, 1);
			}
			
		}
			break;
		case 2:

			if (length > 15) {
				length -= 10;
			}
			px = anchorx - cos(radian) * length;
			py = anchory - sin(radian) * length;
			break;
		case animationtimer:
			anitimer++;
			anitimer %= maxanistate;

			break;
		case gravitytimer:
		{
			

			hitbox.left = px - 30;
			hitbox.right = px + 30;
			hitbox.top = py - 28;
			hitbox.bottom = py + 25;

			int iscolide = 0;

			int grasscolide = 0;
			RECT coliderect;
			
			for (int i = 0; i < 147; ++i) {
				if (IntersectRect(&coliderect, &hitbox, &blocks[i].rt)) {
					
					if (coliderect.right - coliderect.left > 10 && coliderect.bottom == hitbox.bottom) {

						grasscolide = 1;
					}
					
					if (coliderect.right - coliderect.left > 10 && coliderect.top == hitbox.top) {
						jumptimer = 30;
					}
				}
			}
			jumpend = 0;
			if (jumptimer < 25) {
				py -= 15;
				jumptimer++;
				jumpend = 1;
			}

			if (!grasscolide) {
				
				py += 5;
				inair = 1;

				if (jumpend) {
					if (!wireon) {
						if (anistate != 2) {
							anistate = 2;
							anitimer = 0;
							maxanistate = 6;
						}
					}
				}
				else {
					if (!wireon) {
						if (anistate != 3) {
							anistate = 3;
							anitimer = 0;
							maxanistate = 3;
						}
					}
				}
			}
			else {
				inair = 0;
				if (!wireon) {
					if (anistate >= 2) {
						anistate = 0;
						anitimer = 0;
						maxanistate = 8;
					}
				}
			}
		}
			break;
		}
	}
	InvalidateRect(hWnd, NULL, 0);
	break;
	case WM_LBUTTONDOWN:

		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		
		if (anchorinblock && !wireon) {
			wireon = 1;
			radian = atan2(my - prelativey, mx - prelativex);
			//length = sqrt(((mx - player.x1) * (mx - player.x1)) + ((my - player.y1) * (my - player.y1)));
			length = hypot(px - anchorx, py - anchory);
			/*anchorx = mx;
			anchory = my;


			anchorx -= xmiddle;
			anchory -= ymiddle;
			anchorx += carmerax;
			anchory += carmeray;*/

			anistate = 2;
			anitimer = 0;
			maxanistate = 6;

			if (anchorx > px) {
				direction = 1; // 반시계
				pdirection = 1;
			}
			else {
				direction = -1;
				pdirection = -1;
			}


			SetTimer(hWnd, 1, 25, NULL);
		}

		InvalidateRect(hWnd, NULL, 0);
		break;
	
	break;
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);


		if (!wireon) {
			anchorx = mx;
			anchory = my;


			anchorx -= xmiddle;
			anchory -= ymiddle;
			anchorx += carmerax;
			anchory += carmeray;
		}
		InvalidateRect(hWnd, NULL, 0);

		break;
	case WM_LBUTTONUP:
		wireon = 0;

		anistate = 0;
		anitimer = 0;
		maxanistate = 8;
		KillTimer(hWnd, 1);

		InvalidateRect(hWnd, NULL, 0);
		break;
	case WM_RBUTTONDOWN:
	{
		if (wireon) {
			directiontemp = direction;
			direction = 0;

			SetTimer(hWnd, 2, 1, NULL);
		}
	}
	break;
	case WM_RBUTTONUP:
	{
			direction = directiontemp;
			KillTimer(hWnd, 2);
		if (wireon) {
			//direction = 0;

		}
	}
	break;
	case WM_LBUTTONDBLCLK:
		InvalidateRect(hWnd, NULL, 0);
		break;

	case WM_DESTROY:
		DeleteObject(hBitmap);
		DeleteObject(playerbitmap);
		DeleteObject(cursorbitmap);
		DeleteObject(mapbitmap);
		PostQuitMessage(0);
		return 0;
	}





	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


