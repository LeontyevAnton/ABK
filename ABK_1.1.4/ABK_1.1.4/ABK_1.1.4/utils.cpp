#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32
	#include <windows.h>
	#include <conio.h>
	#pragma warning(disable : 4996)
	#pragma comment (lib, "user32.lib")
#else
	#include <unistd.h>
	#include <termios.h>
	#include <fcntl.h>
#endif
#include "utils.h"

char LOGFILENAME[] = "~.log";

CLog LogEntity;

CLog::CLog()
{
	init();
}

void CLog::init()
{
	f=fopen(LOGFILENAME,"at");
	if(!f)
	{
		char st[100];
		sprintf(st,"Проблемы с файлом %s",LOGFILENAME);
		printf(st);
	}
	time_t now;
	now=time(&now);
	fprintf(f,"\n%s\n",ctime(&now));
}

void CLog::log(char *msg)
{
	if(f)
	{
		fprintf(f,msg);
		fflush(f);
	}
}

// Вывод в файл
void LogOut( char* msg,...)
{
	va_list vargs;

	va_start(vargs, msg);  
	char buff[50000];
	vsprintf(buff, msg, vargs );
	va_end(vargs);
	LogEntity.log(buff);
}

// Очистка лог-файла
void clear_log_file()
{
	fclose(LogEntity.f);
	LogEntity.f=fopen(LOGFILENAME,"wt");
	fclose(LogEntity.f);
	LogEntity.init();
}

// Вывод в файл и на экран
void print_(int write_to_console, int write_to_file, const char* msg,...)
{
	if(write_to_file==0 && write_to_console==0)
		return;
	char buff[50000], buffOem[50000];
	va_list vargs;

	va_start(vargs, msg);
	vsprintf(buff, msg, vargs );
	va_end(vargs);
	if(write_to_console) 
	{
#ifdef _WIN32
 		CharToOemA(buff,buffOem);
		printf(buffOem);
#else
		printf(buff); fflush(stdout);
#endif
	}
	if(write_to_file) LogEntity.log(buff);
}

// Вывод в файл и на экран в цвете
void cprint_(int write_to_console, int write_to_file, MP_COLOR color, const char* msg,...)
{
	if(write_to_file==0 && write_to_console==0)
		return;
	set_color(color);
	char buff[50000], buffOem[50000];
	va_list vargs;

	va_start(vargs, msg);  
	vsprintf(buff, msg, vargs );
	va_end(vargs);
	if(write_to_console) 
	{
#ifdef _WIN32
		CharToOemA(buff,buffOem);
		printf(buffOem);
#else
		printf(buff); fflush(stdout);
#endif
	}
	if(write_to_file) LogEntity.log(buff);
	clr_color();
}

// Вывод в файл и на экран
void print(const char* msg,...)
{
	char buff[50000], buffOem[50000];
	va_list vargs;

	va_start(vargs, msg);
	vsprintf(buff, msg, vargs );
	va_end(vargs);
#ifdef _WIN32
	CharToOemA(buff,buffOem);
	printf(buffOem);
#else
	printf(buff); fflush(stdout);
#endif
	LogEntity.log(buff);
}

// Вывод в файл и на экран в цвете
void cprint(MP_COLOR color, const char* msg,...)
{
	set_color(color);
	char buff[50000], buffOem[50000];
	va_list vargs;

	va_start(vargs, msg);  
	vsprintf(buff, msg, vargs );
	va_end(vargs);
#ifdef _WIN32
	CharToOemA(buff,buffOem);
	printf(buffOem);
#else
	printf(buff); fflush(stdout);
#endif
	LogEntity.log(buff);
	clr_color();
}

// Вывод в файл и на экран со временем
void printt(const char* msg,...)
{
	char _buff[50000], buff[50000], buffOem[50000];
	va_list vargs;

	time_t now;
	time(&now);
	struct tm* ti=localtime(&now);

	va_start(vargs, msg);
	vsprintf(_buff, msg, vargs );
	va_end(vargs);
	sprintf(buff,"%02d:%02d:%02d %s",ti->tm_hour,ti->tm_min,ti->tm_sec,_buff);
#ifdef _WIN32
	CharToOemA(buff,buffOem);
	printf(buffOem);
#else
	printf(buff); fflush(stdout);
#endif
	LogEntity.log(buff);
}

// Вывод в файл и на экран в цвете со временем
void cprintt(MP_COLOR color, const char* msg,...)
{
	set_color(color);
	char _buff[50000], buff[50000], buffOem[50000];
	va_list vargs;

	time_t now;
	time(&now);
	struct tm* ti=localtime(&now);

	va_start(vargs, msg);  
	vsprintf(_buff, msg, vargs );
	va_end(vargs);
	sprintf(buff,"%02d:%02d:%02d %s",ti->tm_hour,ti->tm_min,ti->tm_sec,_buff);
#ifdef _WIN32
	CharToOemA(buff,buffOem);
	printf(buffOem);
#else
	printf(buff); fflush(stdout);
#endif
	LogEntity.log(buff);
	clr_color();
}

// Вывод в файл и на экран
void print_str(int write_to_console, int write_to_file, const char* msg)
{
	if(write_to_file==0 && write_to_console==0)
		return;
	char buff[50000], buffOem[50000];
	sprintf(buff,"%s",msg);
	if(write_to_console) 
	{
#ifdef _WIN32
		CharToOemA(buff,buffOem);
		printf(buffOem);
#else
		printf(buff); fflush(stdout);
#endif
	}
	if(write_to_file) LogEntity.log(buff);
}

#ifdef _WIN32
HANDLE hstdout;
void set_hstdout()
{
	static int fst = 1;
	if(fst)
	{
		fst=0;
		hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	}
}
#else
char BLACK[]=		"\e[30m";
char MAROON[]=		"\e[31m";
char GREEN[]=		"\e[32m";
char OLIVE[]=		"\e[33m";
char NAVY[]=		"\e[34m";
char PURPLE[]=		"\e[35m";
char TEAL[]=		"\e[36m";
char SILVER[]=		"\e[37m";

char GRAY[]=		"\e[30m\e[1m";
char RED[]=		"\e[31m\e[1m";
char LIME[]=		"\e[32m\e[1m";
char YELLOW[]=		"\e[33m\e[1m";
char BLUE[]=		"\e[34m\e[1m";
char FUCHSIA[]=		"\e[35m\e[1m";
char AQUA[]=		"\e[36m\e[1m";
char WHITE[]=		"\e[37m\e[1m";

char OFF[]=		"\e[0m";
char BOLD[]=		"\e[1m";
char NORM[]=		"\e[2m";
char ITAL[]=		"\e[3m";
char UNDER[]=		"\e[4m";
char BLINK[]=		"\e[5m";
char RAP_BLINK[]=	"\e[6m";
char REVERS[]=		"\e[7m";
char INVIS[]=		"\e[8m";
#endif

#ifndef _WIN32
static	struct termios tio;
static	tcflag_t old_lf;
static	long old_fl;
#endif

void recovery_con_in()
{
#ifndef _WIN32
	tcgetattr(0, &tio);
	tio.c_lflag = old_lf;
	tcsetattr(0, TCSANOW, &tio);
	fcntl(0, F_SETFL, old_fl);
#endif
}
void prepare_con_in()
{
#ifndef _WIN32
	old_fl = (long) fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, O_NONBLOCK);
	tcgetattr(0, &tio);
	old_lf = tio.c_lflag;
	tio.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &tio);
#endif
}
char con_in()
{
#ifdef _WIN32
	set_hstdout();
	if(!_kbhit()) return (char)0xFF;
	return _getch();
#else
// 	struct termios tio;
// 	tcflag_t old_lf;
// 	long old_fl;
	
	//Init
	{
// 		old_fl = (long) fcntl(0, F_GETFL);
// 		fcntl(0, F_SETFL, O_NONBLOCK);
// 		tcgetattr(0, &tio);
// 		old_lf = tio.c_lflag;
// 		tio.c_lflag &= ~(ICANON | ECHO);
// 		tcsetattr(0, TCSANOW, &tio);
	}
	char ch = fgetc(stdin);
	// Restore	
	{
// 		tcgetattr(0, &tio);
// 		tio.c_lflag = old_lf;
// 		tcsetattr(0, TCSANOW, &tio);
// 		fcntl(0, F_SETFL, old_fl);
	}
	return ch;
#endif
}

void set_color(int color)
{
	#ifdef _WIN32
	{
		char clr ;
		set_hstdout();
		switch(color)
		{
		case C_YELLOW: clr = 0xE; break;
		case C_RED:    clr = 0xC; break;
		case C_GREEN:  clr = 0xA; break;
		case C_BLUE:   clr = 0x9; break;
		case C_AQUA:   clr = 0xB; break;
		case C_OFF:    
		default: clr = 7;
		}
		SetConsoleTextAttribute( hstdout, clr);
	}
	#else

		char *pClr;
		switch(color)
		{
		case C_YELLOW: pClr = YELLOW; break;
		case C_RED:    pClr = RED; break;
		case C_GREEN:  pClr = GREEN; break;
		case C_BLUE:   pClr = BLUE; break;
		case C_AQUA:	   pClr = AQUA; break;
		case C_OFF:    
		default: pClr = OFF;
		}
		printf(pClr);
	#endif
}
void clr_color()
{
	#ifdef _WIN32
		SetConsoleTextAttribute( hstdout, 7);
	#else
		printf(OFF);
	#endif
}

uint16 SwapWord(uint16 a)
{
	return (((a & 0xFF) << 8) | ((a & 0xFF00) >> 8));
}

uint32 SwapDWord(uint32 a)
{
	return ((a & 0xFF) << 24) | ((a & 0xFF00) << 8) | ((a & 0xFF0000) >> 8) | ((a & 0xFF000000) >> 24);
}

uint64 SwapQWord(uint64 a)
{
	return ((a & 0xFF) << 56) | ((a & 0xFF00) << 40) | ((a & 0xFF0000) << 24) | ((a & 0xFF000000) << 8) |
		((a & 0xFF00000000ll) >> 8) | ((a & 0xFF0000000000ll) >> 24) | ((a & 0xFF000000000000ll) >> 40) | ((a & 0xFF00000000000000ll) >> 56);
}

uint32 SwapDBits(uint32 a)
{
	uint32 b=0;
	for(int i=0;i<32;i++)
		b|=((a>>(31-i))&1)<<i;
	return b;
}

uint64 SwapQBits(uint64 a)
{
	uint64 b=0;
	for(int i=0;i<64;i++)
		b|=((a>>(63-i))&1)<<i;
	return b;
}

double get_time(double initial_time)
{
#ifdef _WIN32
	uint64 freq,current_time;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
	return ((double)(current_time))/freq-initial_time;
#else
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return ((tv.tv_sec+(tv.tv_usec*1.0E-6))-initial_time);
#endif
}

void pause_ms(uint32 milliSeconds)
{
#ifdef _WIN32
	Sleep(milliSeconds);
#else
	usleep(milliSeconds*1000);
#endif
}

void show_time(double time_in_sec)
{
	char buf[256]; buf[0]=0;
	int d=((int)(time_in_sec/(3600*24)));
	int h=((int)(time_in_sec/3600))%24;
	int m=((int)(time_in_sec/60))%60;
	int s=((int)time_in_sec%60);
	//sprintf(buf,"%d days %d hrs %d mins %d secs (%f s.)",d,h,m,s);
	
	if(d) sprintf(buf,"%d days ",d);
	if(h) sprintf(buf,"%s%d hrs ",buf,h);
	if(m) sprintf(buf,"%s%d mins ",buf,m);
	if(s) sprintf(buf,"%s%d secs ",buf,s);
	if(d||h||m||s) sprintf(buf,"%s(%f s.)",buf,time_in_sec);
	else sprintf(buf,"%f s.",time_in_sec);
	print("%s\n",buf);
}

unsigned int Float2Int(float flNumber)
{
	return *(unsigned int*)(&flNumber);
}

float Int2Float(unsigned int intNumber)
{
	return *(float*)(&intNumber);
}

uint32 GetRandomValue32()
{
	return (((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|(uint8)rand());
}

uint32 GetRandomValue32(uint32 min_value32,uint32 max_value32)
{
	uint32 value32,max_v32=max_value32-min_value32;
	value32=(((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|(uint8)rand());
	value32>>=((uint8)rand()%63);
	if(max_value32)	value32%=max_v32;
	return value32+min_value32;
}

uint64 GetRandomValue64()
{
	uint64 value64;
	value64=(((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|(uint8)rand());
	value64<<=32;
	value64|=(((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|((uint8)rand()))&0xffffffff;
	return value64;
}

uint64 GetRandomValue64(uint64 min_value64,uint64 max_value64)
{
	uint64 value64,max_v64=max_value64-min_value64;
	value64=(((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|(uint8)rand());
	value64<<=32;
	value64|=(((uint8)rand()<<24)|((uint8)rand()<<16)|((uint8)rand()<<8)|((uint8)rand()))&0xffffffff;
	value64>>=((uint8)rand()%63);
	if(max_value64)	value64%=max_v64;
	return value64+min_value64;
}

void GetRandomValues8(char* values8,int count)
{
	for(int i=0;i<count;i++)
		values8[i]=(char)rand();
}

void GetRandomValues8(unsigned char* values8,int count)
{
	for(int i=0;i<count;i++)
		values8[i]=(unsigned char)rand();
}

#ifdef _WIN32
int CompareFilesFast(char* f1,char* f2)
{
	FILE *pf1,*pf2;
	pf1=fopen(f1,"rt");if(pf1==NULL){cprint(C_YELLOW,"File %s not found\n",f1);return 0;}
	pf2=fopen(f2,"rt");if(pf2==NULL){cprint(C_YELLOW,"File %s not found\n",f2);fclose(pf1);return 0;}
	fclose(pf1);
	fclose(pf2);
	/////////////////////////////////////////////////////////////
	HANDLE ResFile;
	HANDLE hMapFile;
	unsigned char *pSharedBuf1,*pSharedBuf2;
	ResFile=CreateFileA(f1,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(ResFile==INVALID_HANDLE_VALUE)	
		return 1;
	DWORD fileLength1=GetFileSize(ResFile,NULL);
	hMapFile=CreateFileMapping(ResFile,NULL,PAGE_READONLY,0,0,NULL);
	if(hMapFile==NULL) 
		return 1;
	CloseHandle(ResFile);
	pSharedBuf1=(unsigned char*)MapViewOfFile(hMapFile,FILE_MAP_READ,0,0,0);
	if(pSharedBuf1==NULL) 
		return 1;
	CloseHandle(hMapFile);

	ResFile=CreateFileA(f2,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(ResFile==INVALID_HANDLE_VALUE)	
		return 1;
	DWORD fileLength2=GetFileSize(ResFile,NULL);
	hMapFile=CreateFileMapping(ResFile,NULL,PAGE_READONLY,0,0,NULL);
	if(hMapFile==NULL) 
		return 1;
	CloseHandle(ResFile);
	pSharedBuf2=(unsigned char*)MapViewOfFile(hMapFile,FILE_MAP_READ,0,0,0);
	if(pSharedBuf2==NULL) 
		return 2;
	CloseHandle(hMapFile);
	/////////////////////////////////////////////////////////////
	int files_are_equal=0;
	if(fileLength1==fileLength2)
	{
		files_are_equal=1;
		for(unsigned int i=0;i<fileLength1;i++)
		{
			if(pSharedBuf1[i]!=pSharedBuf2[i])
			{
				files_are_equal=0;
				break;
			}
		}
	}
	UnmapViewOfFile(pSharedBuf1);
	UnmapViewOfFile(pSharedBuf2);
	/////////////////////////////////////////////////////////////
	if(!files_are_equal){cprint(C_RED,"Compare files failed!\n");return 1;}
	cprint(C_GREEN,"Files are equal\n");return 0;
}
#endif

int GetFileSize(FILE* fileHandle)
{
	int fileSizeBytes;
#ifdef _WIN32
	fileSizeBytes=filelength(fileno(fileHandle));
#else
	// set file pointer to end of file
	fseek(fileHandle,0,SEEK_END);
	// get current pointer position in bytes (== file size in bytes)
	fileSizeBytes=ftell(fileHandle);
	// return pointer to begin of file (it's very IMPORTANT)
	fseek(fileHandle,0,SEEK_SET);
#endif
	return fileSizeBytes;
}
// #include <sys/stat.h>
// {
// 	struct stat file_stat;
// 	stat(fileName, &file_stat);
// 	return file_stat.st_size;
// }

int CompareFilesByLines(char* f1,char* f2)
{
	print("\nCompare files by lines:\n");
	FILE *fh1,*fh2;
	fh1=fopen(f1,"rt");
	if(!fh1)
	{
		cprint(C_YELLOW,"Open file error - %s\n",f1);
		return -1;
	}
	long fileLength1=GetFileSize(fh1);
	fh2=fopen(f2,"rt");
	if(!fh2)
	{
		cprint(C_YELLOW,"Open file error - %s\n",f2);
		return -1;
	}
	long fileLength2=GetFileSize(fh2);
	print("\tfile1 - %s, size - %d\n",f1,fileLength1);
	print("\tfile2 - %s, size - %d\n",f2,fileLength2);

	char buf1[256],buf2[256];
	int errors=0;
	int i=0;
	while(!feof(fh2))
	{
		buf1[0]=0;buf2[0]=0;
		fgets(buf1,256,fh1);
		fgets(buf2,256,fh2);
		if(buf1[0]==0)
			continue;
		if(buf2[0]==0)
			continue;
		if(strcmp(buf1,buf2))
		{
			errors++;
			if(errors==1) printf("\n");
			if(errors<=10)
			{
				print("line %d:\n",i);
				print("\tfile1=%s",buf1);
				print("\tfile2=%s",buf2);
				//print("");
			}
		}
		i++;
	}
	fclose(fh1);
	fclose(fh2);
	if(errors)
	{
		cprint(C_RED,"Number of errors=%d!\n",errors);
		return 1;
	}
	else
	{
		if(fileLength1!=fileLength2)
		{
			cprint(C_RED,"Files have different size!\n");
			return 1;
		}
		cprint(C_GREEN,"Files are equal\n");
	}
	return 0;
}