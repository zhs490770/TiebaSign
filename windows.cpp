#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
	char syscom[] = "php.exe D:\\GZOI\\server\\DebugTest\\tba\\exectbs.php > D:\\GZOI\\server\\DebugTest\\tba\\log.txt";
	struct tm *newtime;
	char tmpbuf[128];
	time_t lt1;
	int ly = 0, lm = 0, ld = 0, lh, lmin, ls;
	int isrun = 0;
	system(syscom);
	while (1)
	{
		time(&lt1);
		newtime = localtime(&lt1);
		strftime(tmpbuf, 128, "%Y", newtime);
		int year = atoi(tmpbuf);
		strftime(tmpbuf, 128, "%d", newtime);
		int day=atoi(tmpbuf);
		strftime(tmpbuf, 128, "%m", newtime);
		int month = atoi(tmpbuf);
		strftime(tmpbuf, 128, "%H", newtime);
		int hour = atoi(tmpbuf);
		strftime(tmpbuf, 128, "%M", newtime);
		int min = atoi(tmpbuf);
		strftime(tmpbuf, 128, "%S", newtime);
		int sec = atoi(tmpbuf);
		if (isrun)
		{
			if (day != ld)
			{
				system(syscom);
			}
			else if (hour == 5 && lh != 5)
			{
				system(syscom);
			}
			else if (hour == 14 && lh != 14)
			{
				system(syscom);
			}
		}
		isrun = 1;
		ly = year,lm = month,ld = day,lmin = min,lh = hour,ls = sec;
		Sleep(1000);
	}
	return 0;
}