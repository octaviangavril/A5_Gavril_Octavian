#include "Canvas.h"
#include <stdio.h>
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			this->c[i][j] = 32;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y) )>= ray * (ray-1) && ((i - x) * (i - x) + (j - y) * (j - y) )<= ray * (ray+1))
				this->c[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->c[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if (((i >= top && i <= bottom) && (j == left || j == right)) || ((i == top || i == bottom) && (j >= left && j <= right)))
				this->c[i][j] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			if ((i >= top && i <= bottom) && (j >= left && j <= right))
				this->c[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->c[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		this->c[x][y] = ch;
		if (D > 0)
		{
			y++;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			printf("%c", this->c[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			this->c[i][j] = 32;
}