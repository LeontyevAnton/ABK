#ifndef _AK_
#define _AK_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define _PRINT_VIA_LOG_
#define slashn print("\n")

#ifdef _WIN32
	#include <windows.h>
	#include <conio.h>
	#include <io.h>

	#pragma warning (disable:4996)

	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint;
	typedef unsigned int uint32;
	typedef unsigned __int64 uint64;
#else
	#include <sys/time.h>
	#include <unistd.h>

	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;
#endif


union ui32 {
	uint8	b[4]; 
	uint16	s[2]; 
	uint32	w; 
};
union ui64 {
	uint8	b[8]; 
	uint16	s[4]; 
	uint32	w[2]; 
	uint64	q; 
};
union ui128 {
	uint8	b[16];
	uint16	s[8];
	uint32	w[4];
	uint64	q[2]; 
};
union ui256 {
	uint8	b[32];
	uint16	s[16];
	uint32	w[8];
	uint64	q[4]; 
};
union ui512 {
	uint8	b[64];
	uint16	s[32];
	uint32	w[16];
	uint64	q[8]; 
};


// Цвета для set_color
enum MP_COLOR
{
	C_YELLOW,
	C_RED,
	C_GREEN,
	C_BLUE,
	C_AQUA,
	C_OFF
};

// Если нажата клавиша = возвращает ее код. Иначе 255
extern char con_in();
extern void set_color( int clr ); // Установить цвет печати консоли (MP_COLOR)
extern void clr_color(  );	// Восстановить ЧБ цвет печати

extern char LOGFILENAME[];
void clear_log_file(); // Очистка лог-файла
void print_(int write_to_console, int write_to_file, const char* msg,...); // Вывод в лог и на консоль
void cprint_(int write_to_console, int write_to_file, MP_COLOR color, const char* msg,...); // Вывод в файл и на экран  в цвете
void print(const char* msg,...);
void cprint(MP_COLOR clr,const char* msg,...);
void printt(const char* msg,...);
void cprintt(MP_COLOR clr,const char* msg,...);
void print_str(int write_to_console, int write_to_file, const char* msg);
// Необходимы для Linux
void recovery_con_in();
void prepare_con_in();

class CLog
{
public:
	FILE *f;
	CLog();
	virtual ~CLog(){ if(f) {fprintf(f,"\n--------------------------------------\n"); fclose(f);} }
	void init();
	void log(char *msg);
};
void LogOut( char* msg,...);

uint16 SwapWord(uint16 a);
uint32 SwapDWord(uint32 a);
uint64 SwapQWord(uint64 a);
uint32 SwapDBits(uint32 a);
uint64 SwapQBits(uint64 a);

double get_time(double initial_time=0);
void pause_ms(uint32 milliSeconds);
void show_time(double time_in_sec);

unsigned int Float2Int(float flNumber);
float Int2Float(unsigned int intNumber);
uint32 GetRandomValue32();
uint32 GetRandomValue32(uint32 min_value32,uint32 max_value32);
uint64 GetRandomValue64();
uint64 GetRandomValue64(uint64 min_value64,uint64 max_value64);
void GetRandomValues8(char* values8,int count);
void GetRandomValues8(unsigned char* values8,int count);

#ifdef _WIN32
int CompareFilesFast(char* f1,char* f2);
#endif
int GetFileSize(FILE* fileHandle);
int CompareFilesByLines(char* f1,char* f2);

#endif
