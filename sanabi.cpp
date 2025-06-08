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

#define bossstart 10
#define lockon 11
#define ready 12
#define fire 13
#define reload 15

#define shake 20

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
	HDC hDC,mDC, mapDC, playerDC, cursorDC, bgDC, ptempDC, reverseDC, bossDC;
	static HBITMAP hBitmap, mapbitmap, playerbitmap, cursorbitmap, bgbitmap, ptempbitmap, reversebitmap, bossbitmap;
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
	
	//stage plags
	static int resetx;
	static int resety;
	static int camera_plag = 0;

	//boss
	static RECT boss;
	static int bossx;
	static int bossy;
	static POINT bosspos[7];
	static int razoron;
	static double razor_radian;
	static int lockdowntimer;
	static int relativebossx;
	static int relativebossy;
	static int bossanitimer;
	static int launcherx;
	static int launchery;
	static int launchertimer;
	static int launcherdirection;
	static int bosspaze;
	static int readyspeed;
	static int loadspeed;

	//shake
	static int shaketimer;
	static int shakex;

	switch (iMessage) {
	case WM_CREATE:
	{
		shakex = 0;
		GetClientRect(hWnd, &rect);
		init_blocks();
		srand(time(NULL));

		mapbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		playerbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		cursorbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		bgbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		bossbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
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

		resetx = px;
		resety = py;

		player.rt.top = py - 40;
		player.rt.bottom = player.rt.top + 80;
		player.rt.left = px - 40;
		player.rt.right = player.rt.left + 80;

		bosspos[0].x = 85;
		bosspos[0].y = 481 - 30;
		bosspos[1].x = 85;
		bosspos[1].y = 836 - 30;
		bosspos[2].x = 635;
		bosspos[2].y = 832 - 30;

		bosspos[3].x = 1932;
		bosspos[3].y = 481 - 30;
		bosspos[4].x = 1932;
		bosspos[4].y = 836 - 30;
		bosspos[5].x = 1376;
		bosspos[5].y = 832 - 30;

		bosspos[6].x = 1014;
		bosspos[6].y = 390 - 30;

		bossx = bosspos[5].x;
		bossy = bosspos[5].y;

		boss.left = bossx - 30;
		boss.right = bossx + 30;
		boss.top = bossy - 30;
		boss.bottom = bossy + 30;

		relativebossx = bossx - carmerax + xmiddle;
		relativebossy = bossy - carmeray + ymiddle;

		SetTimer(hWnd, animationtimer, 100, NULL);
		SetTimer(hWnd, gravitytimer, 27, NULL);

		readyspeed = 2000;
		loadspeed = 1500;
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
		bossDC = CreateCompatibleDC(mDC);


		HBITMAP oldBitmap, oldBgBitmap, oldPlayerBitmap, oldCursorBitmap, oldMapBitmap, oldptempBitmap, oldreverseBitmap, oldbossBitmap;

		// mDC에 hBitmap 선택
		oldBitmap = (HBITMAP)SelectObject(mDC, hBitmap);
		oldptempBitmap = (HBITMAP)SelectObject(ptempDC, ptempbitmap);
		oldreverseBitmap = (HBITMAP)SelectObject(reverseDC, reversebitmap);
		// 각 DC에 비트맵 선택
		oldPlayerBitmap = (HBITMAP)SelectObject(playerDC, playerbitmap);
		oldCursorBitmap = (HBITMAP)SelectObject(cursorDC, cursorbitmap);
		oldMapBitmap = (HBITMAP)SelectObject(mapDC, mapbitmap);
		oldBgBitmap = (HBITMAP)SelectObject(bgDC, bgbitmap);
		oldbossBitmap = (HBITMAP)SelectObject(bossDC, bossbitmap);


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

		if (camera_plag == 0) {
			if (carmerax < xmiddle) {
				carmerax = xmiddle;
			}
			if (carmeray + ymiddle > bmp.bmHeight) { // 보스맵 바닥 y좌표 1331
				carmeray -= carmeray + ymiddle - bmp.bmHeight;
			}
		}
		else if (camera_plag == 1) {
			if (carmerax + xmiddle > bmp.bmWidth) {
				carmerax -= carmerax + xmiddle - bmp.bmWidth;
			}
			if (carmerax < 7761 + xmiddle) {
				carmerax = 7761 + xmiddle;
			}
		}
		else {
			if (carmerax < xmiddle) {
				carmerax = xmiddle;
			}
			if (carmerax + xmiddle > 2023) { // 보스맵 바닥 y좌표 1331
				carmerax -= carmerax + xmiddle - 2023;
			}
			if (carmeray < ymiddle) {
				carmeray = ymiddle;
			}
			if (carmeray + ymiddle > 1331) { // 보스맵 바닥 y좌표 1331
				carmeray -= carmeray + ymiddle - 1331;
			}
		}
		
		carmerax += shakex;
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
				for (int i = 0; i < 149; ++i) {
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

				if (PtInRect(&boss, anchorp)) {
					anchorinblock = 2;
					anchorx = bossx;
					anchory = bossy;
					chk = 1;
				}
				if (chk) {
					break;
				}
			}
		}
		/*anchorp.x = px;
		anchorp.y = py;*/

		if (camera_plag == 2) {
			relativebossx = bossx - carmerax + xmiddle;
			relativebossy = bossy - carmeray + ymiddle;
			if (px > bossx) { // boss have to gaze right
				StretchBlt(reverseDC, 80, 0, 80, 80, bossDC, bossanitimer * 80, 0, 80, 80, SRCCOPY);
			}
			else {
				StretchBlt(reverseDC, 80, 0, 80, 80, bossDC, bossanitimer * 80 + 80, 0, -80, 80, SRCCOPY);
			}
			TransparentBlt(mDC, relativebossx - 40, relativebossy - 40, 80, 80, reverseDC, 80, 0, 80, 80, RGB(255, 255, 255));
		}

		if (launchertimer != 0) {
			FillRect(ptempDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
			int relativelauncherx = launcherx - carmerax + xmiddle;
			int relativelaunchery = launchery - carmeray + ymiddle;
			StretchBlt(reverseDC, 240, 240, 80, 80, bossDC, 240, 240, 80, 80, SRCCOPY);
			/*if (launcherdirection == -1) { // boss have to gaze right
				//StretchBlt(reverseDC, 160, 0, 80, 80, bossDC, 240, 240, 80, 80, SRCCOPY);
			}
			else {
				//StretchBlt(reverseDC, 160, 0, 80, 80, bossDC, 240 + 80, 240, -80, 80, SRCCOPY);
				StretchBlt(reverseDC, 240, 240, 80, 80, bossDC, 240 + 80, 240, -80, 80, SRCCOPY);
			}*/

			POINT outPts[3];
			double cosA = cos(razor_radian);
			double sinA = sin(razor_radian);
			int hw = 40;
			int hh = 40;


			outPts[0].x = static_cast<LONG>(3 * 80 + 40 + (-hw * cosA - (-hh) * sinA));
			outPts[0].y = static_cast<LONG>(3 * 80 + 40 + (-hw * sinA + (-hh) * cosA));

			// 오른쪽 위
			outPts[1].x = static_cast<LONG>(3 * 80 + 40 + (hw * cosA - (-hh) * sinA));
			outPts[1].y = static_cast<LONG>(3 * 80 + 40 + (hw * sinA + (-hh) * cosA));

			// 왼쪽 아래
			outPts[2].x = static_cast<LONG>(3 * 80 + 40 + (-hw * cosA - hh * sinA));
			outPts[2].y = static_cast<LONG>(3 * 80 + 40 + (-hw * sinA + hh * cosA));

			PlgBlt(ptempDC, outPts, reverseDC, 240, 240, 80, 80, NULL, 0, 0);
			
			TransparentBlt(mDC, relativelauncherx - 40, relativelaunchery - 40, 80, 80, ptempDC, 240, 240, 80, 80, RGB(255, 255, 255));
		}
		

		mx = anchorx - carmerax + xmiddle;
		my = anchory - carmeray + ymiddle;

		if (anchorinblock == 1) {
			TransparentBlt(mDC, mx - 64, my - 64, 128, 128, cursorDC, 0, 0, 128, 128, RGB(255, 255, 255));
		}
		else if (anchorinblock == 2) {
			TransparentBlt(mDC, mx - 64, my - 64, 128, 128, cursorDC, 128, 0, 128, 128, RGB(255, 255, 255));
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
		LineTo(hDC, prelativex, prelativey - 15);
		LineTo(hDC, prelativex + 15, prelativey + 15);
		LineTo(hDC, prelativex - 15, prelativey + 15);

		//wsprintf(temp, L"x = %d y = %d", anchorx, anchory);
		//TextOut(hDC, xmiddle, ymiddle, temp, lstrlen(temp));

		if (razoron) {
			SelectObject(hDC, oldPen);
			DeleteObject(hPen);

			hPen = CreatePen(PS_DOT, 2, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(hDC, hPen);
			MoveToEx(hDC, relativebossx, relativebossy, NULL);

			int razordestx = relativebossx - cos(razor_radian) * 1500;
			int razordesty = relativebossy - sin(razor_radian) * 1500;

			LineTo(hDC, razordestx, razordesty);
		}

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
		SelectObject(bossDC, oldbossBitmap);

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
		DeleteDC(bossDC);



		EndPaint(hWnd, &ps);
		break;

	}			 break;
	case WM_CHAR:
	{
		hDC = GetDC(hWnd);

		if (wParam == 'p') {
			px = 10008;
			py = 3102;
		}

		if (wParam == 'q') {

			PostQuitMessage(0);
		}

		if (wParam == 'w') {
			int iscolide = 0;

			int grasscolide = 0;
			int headcolide = 0;
			RECT coliderect;

			for (int i = 0; i < 149; ++i) {
				if (IntersectRect(&coliderect, &hitbox, &blocks[i].rt)) {


					iscolide = 1;
				}
			}

			if (iscolide) {
				py -= 10;
			}
		}

		if (wParam == 's') {
			py += 10;
		}

		if (wParam == 'a') {
			pdirection = -1;

			if (!wireon) {
				int iscolide = 0;

				int grasscolide = 0;
				RECT coliderect;


				int g = 0;

				for (int i = 0; i < 149; ++i) {
					if (IntersectRect(&coliderect, &hitbox, &blocks[i].rt)) {

						if (coliderect.bottom - coliderect.top > 10 && coliderect.left == hitbox.left) {
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
			else {
				int iscolide = 0;
				direction = -1;
				int grasscolide = 0;
				int headcolide = 0;
				RECT coliderect;
				RECT temphitbox;
				/*
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
				}*/

				py = anchory - sin(radian - 0.1) * length;
				px = anchorx - cos(radian - 0.1) * length;

			}
		}

		if (wParam == 'd') {
			pdirection = 1;

			if (!wireon) {
				int iscolide = 0;

				int grasscolide = 0;
				RECT coliderect[2];


				int g = 0;

				for (int i = 0; i < 149; ++i) {
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
			else {
				int iscolide = 0;
				direction = 1;
				int grasscolide = 0;
				int headcolide = 0;
				RECT coliderect;
				RECT temphitbox;
				/*
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
				}*/

				py = anchory - sin(radian + 0.1) * length;
				px = anchorx - cos(radian + 0.1) * length;

			}
		}

		InvalidateRect(hWnd, NULL, 0);
		ReleaseDC(hWnd, hDC);
	}
		break;

	case WM_KEYUP:
	{
		if (wParam == 'D') {
			
			if (!wireon) {
				anistate = 0;
				anitimer = 0;
				maxanistate = 8;
			}
		}
		if (wParam == 'A') {

			if (!wireon) {
				anistate = 0;
				anitimer = 0;
				maxanistate = 8;
			}
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

			for (int i = 0; i < 149; ++i) {
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
			bossanitimer++;
			bossanitimer %= 8;

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
			
			for (int i = 0; i < 149; ++i) {
				if (IntersectRect(&coliderect, &hitbox, &blocks[i].rt)) {
					
					if (coliderect.right - coliderect.left > 10 && coliderect.bottom == hitbox.bottom) {

						grasscolide = 1;
					}
					
					if (coliderect.right - coliderect.left > 10 && coliderect.top == hitbox.top) {
						jumptimer = 30;
					}

					if (blocks[i].lava_plag == TRUE) {
						px = resetx;
						py = resety;
						wireon = 0;
						KillTimer(hWnd, 1);
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


			//주인공의 좌표에 따라 카메라와 resetxy갱신
			if (camera_plag == 0) {
				if (px > 6115) {
					resetx = 5772;
					resety = 5936;
				}
				if (px > 8000) {
					resetx = 9000;
					resety = 4900;
					camera_plag = 1;
				}

			}
			else if (camera_plag == 1) {
				if (px < 7762 && py < 3270) {
					resetx = xmiddle;
					resety = ymiddle;
					px = xmiddle;
					py = ymiddle;
					wireon = 0;
					KillTimer(hWnd, 1);
					camera_plag = 2;
					SetTimer(hWnd, bossstart, 1503, NULL);
				}
			}
			if (py > 8000) {
				px = resetx;
				py = resety;
			}
		}
			break;
		case bossstart:
		{
			SetTimer(hWnd, lockon, 16, NULL);
			razoron = 1;
			lockdowntimer = 0;
			KillTimer(hWnd, bossstart);
		}
			break;
		case lockon:
		{
			lockdowntimer += 16;
			razor_radian = atan2(bossy - py, bossx - px);
			if (lockdowntimer > readyspeed) {
				SetTimer(hWnd, ready, loadspeed, NULL);
				KillTimer(hWnd, lockon);
			}
		}
			break;
		case ready:
		{
			razoron = 0;
			lockdowntimer = 0;
			launcherx = bossx;
			launchery = bossy;
			launchertimer = 0;

			if (px > bossx) {
				launcherdirection = 1;
			}
			else {
				launcherdirection = -1;
			}
			
			SetTimer(hWnd, fire, 23, NULL);
			KillTimer(hWnd, ready);
		}
			break;
		case fire: 
		{
			launchertimer += 20;

			launcherx = bossx - cos(razor_radian) * launchertimer;
			launchery = bossy - sin(razor_radian) * launchertimer;

			int ck = 0;

			if (launcherx < 0 - 40) {
				ck = 1;
			}
			if (launcherx > 2023 + 40) {
				ck = 1;
			}
			if (launchery < 0 - 40) {
				ck = 1;
			}
			if (launchery > 1331 + 40) {
				ck = 1;
			}

			/*RECT thitbox;

			thitbox.left = hitbox.left - 80;
			thitbox.right = hitbox.right + 80;
			thitbox.top = hitbox.top - 80;
			thitbox.bottom = hitbox.bottom + 80;*/
			//if (hypot()) {
			if (hypot(px - launcherx, py - launchery) < 70) {
				wireon = 0;

				shakex = 5;
				KillTimer(hWnd, 1);
				SetTimer(hWnd, shake, 50, NULL);
			}

			if (ck) {
				if (bosspaze == 1) {
					int rnad = rand() % 6;
					while (bossx == bosspos[rnad].x && bossy == bosspos[rnad].y) {
						rnad = rand() % 6;
					}

					bossx = bosspos[rnad].x;
					bossy = bosspos[rnad].y;
					boss.left = bossx - 30;
					boss.right = bossx + 30;
					boss.top = bossy - 30;
					boss.bottom = bossy + 30;
				}
				launchertimer = 0;
				razoron = 1;
				SetTimer(hWnd, lockon, 16, NULL);
				KillTimer(hWnd, fire);
			}
		}
			break;
		case shake:
		{
			++shaketimer;
			shakex *= -1;
			if (shaketimer > 10) {
				shaketimer = 0;
				shakex = 0;
				KillTimer(hWnd, shake);
			}
		}
			break;
		case reload:
		{
			SetTimer(hWnd, lockon, 16, NULL);
			razoron = 1;
			lockdowntimer = 0;
			KillTimer(hWnd, reload);
		}
			break;
		}
	}
	InvalidateRect(hWnd, NULL, 0);
	break;
	case WM_LBUTTONDOWN:

		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		
		if (anchorinblock == 1 && !wireon) {
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
		else if (anchorinblock == 2 && !wireon) {
			px = bossx;
			py = bossy - 30;

			int rnad = rand() % 6;
			switch (bosspaze) {
			case 0:
			{
				while (bossx == bosspos[rnad].x && bossy == bosspos[rnad].y) {
					rnad = rand() % 6;
				}
				bossx = bosspos[rnad].x;
				bossy = bosspos[rnad].y;
				boss.left = bossx - 30;
				boss.right = bossx + 30;
				boss.top = bossy - 30;
				boss.bottom = bossy + 30;

				KillTimer(hWnd, lockon);
				KillTimer(hWnd, ready);
				KillTimer(hWnd, fire);
				KillTimer(hWnd, reload);

				lockdowntimer = 0;
				launchertimer = 0;
				SetTimer(hWnd, reload, 1500, NULL);
				launcherx = -80;
				launchery = -80;
				bosspaze = 1;
			}
				break;
			case 1:
			{
				rnad = 6;
				
				bossx = bosspos[rnad].x;
				bossy = bosspos[rnad].y;
				boss.left = bossx - 30;
				boss.right = bossx + 30;
				boss.top = bossy - 30;
				boss.bottom = bossy + 30;
				KillTimer(hWnd, lockon);
				KillTimer(hWnd, ready);
				KillTimer(hWnd, fire);
				KillTimer(hWnd, reload);

				lockdowntimer = 0;
				launchertimer = 0;
				SetTimer(hWnd, reload, 1500, NULL);
				launcherx = -80;
				launchery = -80;

				readyspeed = 1000;
				loadspeed = 500;
				bosspaze = 2;
			}
				break;
			case 2:
			{

				bossx = 8000;
				bossy = 8000;
				launcherx = -80;
				launchery = -80;
				KillTimer(hWnd, lockon);
				KillTimer(hWnd, ready);
				KillTimer(hWnd, fire);
				KillTimer(hWnd, reload);
			}
				break;
			}


			

			
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


