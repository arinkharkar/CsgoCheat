#include <windows.h>
#include "data.h"
void DrawLine(float StartX, float StartY, float EndX, float EndY) {
	int a, b = 0;
	HPEN hOPen;
	HPEN hNPen = CreatePen(PS_SOLID, 1, 0x0000FF /*red*/);
	hOPen = (HPEN)SelectObject(moduledata.hdc, hNPen);
	MoveToEx(moduledata.hdc, (int)StartX, (int)StartY, NULL); //start of line
	a = LineTo(moduledata.hdc, (int)EndX, (int)EndY); //end of line
	DeleteObject(SelectObject(moduledata.hdc, hOPen));
}

void DrawBox(int x, int y, int height, int width) {
	int topY = y + height;
	int bottomY = y - height;
	int leftX = x + width;
	int rightX = x - width;

	DrawLine(leftX, bottomY, leftX, topY);
	DrawLine(rightX, bottomY, rightX, topY);
	DrawLine(rightX, bottomY, leftX, bottomY);
	DrawLine(rightX, topY, leftX, topY);
}

void DrawChars(int x, int y, const char* text) {
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = x + strlen(text) * 50;
	rect.bottom = y - 50;
	DrawTextA(moduledata.hdc, text, -1, &rect, DT_CENTER);
}