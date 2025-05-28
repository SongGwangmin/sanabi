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
#pragma comment (lib, "msimg32.lib")



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
	HDC hDC,mDC, mapDC, playerDC, cursorDC, bgDC;
	static HBITMAP hBitmap, mapbitmap, playerbitmap, cursorbitmap, bgbitmap;
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

	static int prelativex;
	static int prelativey;
	static int carmerax;
	static int carmeray;

	switch (iMessage) {
	case WM_CREATE:
	{
		GetClientRect(hWnd, &rect);

		srand(time(NULL));

		mapbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		playerbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));;
		cursorbitmap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));;
		//hBitmap2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		xmiddle = rect.right / 2;
		ymiddle = rect.bottom / 2;
		GetObject(mapbitmap, sizeof(BITMAP), &bmp);

		map.left = 0;
		map.right = bmp.bmWidth;
		map.bottom = bmp.bmHeight;
		map.top = 0;


		px = xmiddle;
		py = map.bottom - ymiddle;


		player.rt.top = py - 40;
		player.rt.bottom = player.rt.top + 80;
		player.rt.left = px - 40;
		player.rt.right = player.rt.left + 80;
	}
	break;
	case WM_PAINT:
	{

		hDC = BeginPaint(hWnd, &ps);
		mDC = CreateCompatibleDC(hDC);
		hBitmap = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);

		(HBITMAP)SelectObject(mDC, hBitmap);


		playerDC = CreateCompatibleDC(mDC);
		cursorDC = CreateCompatibleDC(mDC);
		bgDC = CreateCompatibleDC(mDC);
		mapDC = CreateCompatibleDC(mDC);

		(HBITMAP)SelectObject(playerDC, playerbitmap);
		(HBITMAP)SelectObject(cursorDC, cursorbitmap);
		(HBITMAP)SelectObject(mapDC, mapbitmap);


		hPen = CreatePen(PS_DOT, 1, RGB(0, 255, 255));
		oldPen = (HPEN)SelectObject(hDC, hPen);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
		FillRect(mDC, &rect, hBrush);
		//BitBlt(hDC, 0, 0, xtri * 3, ytri * 3, hMemDC, 0, 0, SRCCOPY);
		//BitBlt(hDC, xtri, 0, xtri, ytri, hMemDC, xtri, 0, SRCCOPY);
		// 15 - width, 15 - height, 16 - sprites space(width and height)

		//StretchBlt(mDC, 0, 0, 150, 150, hMemDC, 0, 0, 15, 15, SRCCOPY);

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
		if (carmeray + ymiddle > bmp.bmHeight) {
			carmeray -= carmeray + ymiddle - bmp.bmHeight;
		}

		

		TransparentBlt(mDC, map.left - carmerax + xmiddle, map.top - carmeray + ymiddle, bmp.bmWidth, bmp.bmHeight, mapDC, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(0, 255, 255));
		
		int spritesxpos = 0;
		int spritesypos = 0;

		
		//spritesxpos = 0;

		prelativex = px - carmerax + xmiddle;
		prelativey = py - carmeray + ymiddle;


		TransparentBlt(mDC, px - carmerax - 40 + xmiddle, py - carmeray - 40 + ymiddle, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, RGB(255, 255, 255));

		if (wireon) {
			mx = anchorx - carmerax + xmiddle;
			my = anchory - carmeray + ymiddle;
		}

		TransparentBlt(mDC, mx - 64, my - 64, 128, 128, cursorDC, spritesxpos, spritesypos, 128, 128, RGB(255, 255, 255));

		
		
		/*POINT P[2] = { {prelativex, prelativey},{mx, my} };
		Polygon(mDC, P, 2);*/

		BitBlt(hDC, 0, 0, rect.right, rect.bottom, mDC, 0, 0, SRCCOPY);
		MoveToEx(hDC, prelativex, prelativey, NULL);
		LineTo(hDC, mx, my);

		SelectObject(mDC, oldPen);
		DeleteObject(hPen);
		SelectObject(mDC, oldBrush);
		DeleteObject(hBrush);

		DeleteDC(mDC);
		DeleteDC(playerDC);
		DeleteDC(cursorDC);
		DeleteDC(mapDC);

		EndPaint(hWnd, &ps);
		break;

	}			 break;
	case WM_CHAR:
		hDC = GetDC(hWnd);

		
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
			px -= 10;
		}

		if (wParam == 'd') {
			px += 10;
		}

		InvalidateRect(hWnd, NULL, 0);
		ReleaseDC(hWnd, hDC);
		break;

	case WM_KEYDOWN:
	{


	}
	InvalidateRect(hWnd, NULL, 0);
	break;

	case WM_KEYUP:
		hDC = GetDC(hWnd);
		
		//InvalidateRect(hWnd, NULL, 0);
		ReleaseDC(hWnd, hDC);
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
			if (direction == 1) {
				radian -= 0.1;
			}
			else if (direction == -1) {
				radian += 0.1;
			}

			px = anchorx - cos(radian) * length;
			py = anchory - sin(radian) * length;
			break;
		case 2:
			if (length > 0) {
				length -= 20;
			}
			player.x1 = mx - cos(radian) * length;
			player.y1 = my - sin(radian) * length;
			break;
		}
	}
	InvalidateRect(hWnd, NULL, 0);
	break;
	case WM_LBUTTONDOWN:
		wireon = 1;
		SetTimer(hWnd, 1, 10, NULL);

		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		

		radian = atan2(my - prelativex, mx - prelativey);
		//length = sqrt(((mx - player.x1) * (mx - player.x1)) + ((my - player.y1) * (my - player.y1)));
		length = hypot(mx - prelativex, my - prelativey);
		anchorx = mx;
		anchory = my;


		anchorx -= xmiddle;
		anchory -= ymiddle;
		anchorx += carmerax;
		anchory += carmeray;

		if (anchorx > px) {
			direction = 1; // 반시계

		}
		else {
			direction = -1;
		}


		InvalidateRect(hWnd, NULL, 0);
		break;
	
	break;
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, 0);

		break;
	case WM_LBUTTONUP:
		wireon = 0;
		KillTimer(hWnd, 1);
		InvalidateRect(hWnd, NULL, 0);
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