#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
#include "gstdlib.cpp"

using namespace std;
//using namespace gstd;

namespace gConEng
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE), hIn = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD buf;
	
	void gotoxy(COORD pos)
	{
		SetConsoleCursorPosition(hOut, pos);
	}
	
	void editCursor(bool isVisible)
	{
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(hOut, &CursorInfo);
		CursorInfo.bVisible = isVisible;
		SetConsoleCursorInfo(hOut, &CursorInfo);
	}
	
	COORD coord(int x, int y)
	{
		return (COORD){x, y};
	}
	
	class SimpleText
	{
		public:
			COORD s, e;
			string text;
			int output(COORD posS = s, COORD posE = e)
			{
				int l = text.size();
				for (int i = 0; i < l; i++)
				{
					if (i + posS.Y >= posE.Y) 
						return i;
					gotoxy(coord(posS.X, posS.Y + i));
					printf("%c", text[i]);
				}
			}
	};
}
