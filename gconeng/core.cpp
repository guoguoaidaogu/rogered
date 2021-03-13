#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
//#include "../gstd/core.cpp"

using namespace std;
//using namespace gstd;

namespace gConEng
{
	namespace gConEngCore
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
		
		class SimpleText
		{
			public:
				string text;
				int output(COORD posS, COORD posE)
				{
					int l = text.size();
					for (int i = 0; i < l; i++)
					{
						if (i + posS.X >= posE.X) 
							return i;
						gotoxy((COORD){posS.X + i, posS.Y});
						printf("%c", text[i]);
					}
				}
		};
	}
}
