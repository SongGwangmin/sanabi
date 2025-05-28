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

		player.rt.top = map.bottom - ymiddle;
		player.rt.bottom = player.rt.top + 80;
		player.rt.left = xmiddle;
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


		hPen = CreatePen(PS_DASHDOT, 2, RGB(255, 0, 0));
		oldPen = (HPEN)SelectObject(mDC, hPen);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
		FillRect(mDC, &rect, hBrush);
		//BitBlt(hDC, 0, 0, xtri * 3, ytri * 3, hMemDC, 0, 0, SRCCOPY);
		//BitBlt(hDC, xtri, 0, xtri, ytri, hMemDC, xtri, 0, SRCCOPY);
		// 15 - width, 15 - height, 16 - sprites space(width and height)

		//StretchBlt(mDC, 0, 0, 150, 150, hMemDC, 0, 0, 15, 15, SRCCOPY);
		int carmerax = player.rt.left + 40;
		int carmeray = player.rt.top + 40;

		int pp = carmerax - map.left + xmiddle;
		int pq = carmeray - map.top + ymiddle;

		int qq = map.left - carmerax;
		int qr = map.top - carmeray;

		TransparentBlt(mDC, map.left - carmerax, map.top - carmeray, bmp.bmWidth, bmp.bmHeight, mapDC, 0, 0, bmp.bmWidth, bmp.bmHeight, RGB(0, 255, 255));
		
		int spritesxpos = 0;
		int spritesypos = 0;

		
		//spritesxpos = 0;
		TransparentBlt(mDC, carmerax - player.rt.left + xmiddle, carmeray - player.rt.top +  ymiddle, 80, 80, playerDC, spritesxpos, spritesypos, 80, 80, RGB(255, 255, 255));

		TransparentBlt(mDC, mx - 64, my - 64, 128, 128, cursorDC, spritesxpos, spritesypos, 128, 128, RGB(255, 255, 255));

		
		BitBlt(hDC, 0, 0, rect.right, rect.bottom, mDC, 0, 0, SRCCOPY);


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
			player.rt.top -= 10;
			player.rt.bottom -= 10;
		}

		if (wParam == 's') {
			player.rt.top += 10;
			player.rt.bottom += 10;
		}

		if (wParam == 'a') {
			player.rt.left -= 10;
			player.rt.right -= 10;
		}

		if (wParam == 'd') {
			player.rt.left += 10;
			player.rt.right += 10;
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
	case WM_LBUTTONDOWN:
	{
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

	}
	break;
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, 0);

		break;
	case WM_TIMER:
	{
		
	}
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