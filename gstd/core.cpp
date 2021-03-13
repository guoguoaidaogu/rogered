#include <iostream>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;

namespace gstd
{
	void gDelay(int ms)
	{
		static clock_t oldtime = 0;
		while (clock() - ms < oldtime)
			Sleep(1);
		oldtime = clock();
	}
}
