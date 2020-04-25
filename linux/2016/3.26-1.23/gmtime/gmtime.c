#include <stdio.h>
#include <time.h>

int main()
{
	//获取当前时间
	time_t timep;
	time(&timep);

	//获取格林尼治时间
	struct tm *ptm;
	ptm=gmtime(&timep);

	printf("%d-%d-%d\n",ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
	printf("%d-%d-%d\n",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
	printf("%d-%d\n",ptm->tm_yday,ptm->tm_wday);

	return 0;
}
