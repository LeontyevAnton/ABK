#include <direct.h>
#include "utils.h"
#include <iostream>
#include <bitset>
#include <fstream>
#include <regex>
#include <string>
#include <time.h>
#include <omp.h>

#define wordCount 32

using namespace std;
uint_fast32_t t = 0;
double mGlobal = 0;
long long int clickCounter = 0;
vector<char*>Cl;
int Size = 500;

struct SizeBit {
	uint_fast32_t sb1;
	uint_fast32_t sb2;
	uint_fast32_t sb3;
	uint_fast32_t sb4;
	uint_fast32_t sb5;
	uint_fast32_t sb6;
	uint_fast32_t sb7;
	uint_fast32_t sb8;
	uint_fast32_t sb9;
	uint_fast32_t sb10;
	uint_fast32_t sb11;
	uint_fast32_t sb12;
	uint_fast32_t sb13;
	uint_fast32_t sb14;
	uint_fast32_t sb15;
	uint_fast32_t sb16;
	uint_fast32_t sb17;
	uint_fast32_t sb18;
	uint_fast32_t sb19;
	uint_fast32_t sb20;
	uint_fast32_t sb21;
	uint_fast32_t sb22;
	uint_fast32_t sb23;
	uint_fast32_t sb24;
	uint_fast32_t sb25;
	uint_fast32_t sb26;
	uint_fast32_t sb27;
	uint_fast32_t sb28;
	uint_fast32_t sb29;
	uint_fast32_t sb30;
	uint_fast32_t sb31;
	uint_fast32_t sb32;
};


void matrixEntry(uint_fast32_t* A[], int Size, FILE* MatrixA) 
{
	for (uint_fast32_t i = 0; i < Size; i++)
	{
		for (uint_fast32_t j = 0; j < Size; j++)
		{
			fprintf(MatrixA, "%d ", A[i][j]);
		}
		fprintf(MatrixA, "\n");
	}
	fclose(MatrixA);
}

void lineHandler(uint_fast32_t *a,string line, smatch number) 
{
	int tempValue = 0;
	line = regex_replace(line, regex(" "), "");
	for (int j = 0; j < line.size();) {
		if (regex_search(line, number, regex("1"))) {
			tempValue = line.size() - number.position() - 1;
			if      (tempValue < 32 * 1 ) a[31] |= 1 << tempValue;
			else if (tempValue < 32 * 2 ) a[30] |= 1 << tempValue;
			else if (tempValue < 32 * 3 ) a[29] |= 1 << tempValue;
			else if (tempValue < 32 * 4 ) a[28] |= 1 << tempValue;
			else if (tempValue < 32 * 5 ) a[27] |= 1 << tempValue;
			else if (tempValue < 32 * 6 ) a[26] |= 1 << tempValue;
			else if (tempValue < 32 * 7 ) a[25] |= 1 << tempValue;
			else if (tempValue < 32 * 8 ) a[24] |= 1 << tempValue;
			else if (tempValue < 32 * 9 ) a[23] |= 1 << tempValue;
			else if (tempValue < 32 * 10) a[22] |= 1 << tempValue;
			else if (tempValue < 32 * 11) a[21] |= 1 << tempValue;
			else if (tempValue < 32 * 12) a[20] |= 1 << tempValue;
			else if (tempValue < 32 * 13) a[19] |= 1 << tempValue;
			else if (tempValue < 32 * 14) a[18] |= 1 << tempValue;
			else if (tempValue < 32 * 15) a[17] |= 1 << tempValue;
			else if (tempValue < 32 * 16) a[16] |= 1 << tempValue;
			else if (tempValue < 32 * 17) a[15] |= 1 << tempValue;
			else if (tempValue < 32 * 18) a[14] |= 1 << tempValue;
			else if (tempValue < 32 * 19) a[13] |= 1 << tempValue;
			else if (tempValue < 32 * 20) a[12] |= 1 << tempValue;
			else if (tempValue < 32 * 21) a[11] |= 1 << tempValue;
			else if (tempValue < 32 * 22) a[10] |= 1 << tempValue;
			else if (tempValue < 32 * 23) a[ 9] |= 1 << tempValue;
			else if (tempValue < 32 * 24) a[ 8] |= 1 << tempValue;
			else if (tempValue < 32 * 25) a[ 7] |= 1 << tempValue;
			else if (tempValue < 32 * 26) a[ 6] |= 1 << tempValue;
			else if (tempValue < 32 * 27) a[ 5] |= 1 << tempValue;
			else if (tempValue < 32 * 28) a[ 4] |= 1 << tempValue;
			else if (tempValue < 32 * 29) a[ 3] |= 1 << tempValue;
			else if (tempValue < 32 * 30) a[ 2] |= 1 << tempValue;
			else if (tempValue < 32 * 31) a[ 1] |= 1 << tempValue;
			else if (tempValue<= 32 * 32) a[ 0] |= 1 << tempValue;
			line = line.substr(number.position() + 1);
		}
		else
			line = line.substr(1);
	}
}

void printBuffer(uint_fast32_t* a,string name)
{
	char Buffer[wordCount][33];
	for (int i = 0; i < wordCount; i++)
		itoa(a[i], Buffer[i], 2);
	printf(name.c_str());
	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		printf("%032s ", Buffer[i]);
	printf("\n");
}

void dataReorganization(uint_fast32_t** a, uint_fast32_t** A)
{
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++)
			if (a[i][j] == 1) {
				if      (j <= 32 * 1 ) A[i][31] |= 1 << j;
				else if (j <= 32 * 2 ) A[i][30] |= 1 << j;
				else if (j <= 32 * 3 ) A[i][29] |= 1 << j;
				else if (j <= 32 * 4 ) A[i][28] |= 1 << j;
				else if (j <= 32 * 5 ) A[i][27] |= 1 << j;
				else if (j <= 32 * 6 ) A[i][26] |= 1 << j;
				else if (j <= 32 * 7 ) A[i][25] |= 1 << j;
				else if (j <= 32 * 8 ) A[i][24] |= 1 << j;
				else if (j <= 32 * 9 ) A[i][23] |= 1 << j;
				else if (j <= 32 * 10) A[i][22] |= 1 << j;
				else if (j <= 32 * 11) A[i][21] |= 1 << j;
				else if (j <= 32 * 12) A[i][20] |= 1 << j;
				else if (j <= 32 * 13) A[i][19] |= 1 << j;
				else if (j <= 32 * 14) A[i][18] |= 1 << j;
				else if (j <= 32 * 15) A[i][17] |= 1 << j;
				else if (j <= 32 * 16) A[i][16] |= 1 << j;
				else if (j <= 32 * 17) A[i][15] |= 1 << j;
				else if (j <= 32 * 18) A[i][14] |= 1 << j;
				else if (j <= 32 * 19) A[i][13] |= 1 << j;
				else if (j <= 32 * 20) A[i][12] |= 1 << j;
				else if (j <= 32 * 21) A[i][11] |= 1 << j;
				else if (j <= 32 * 22) A[i][10] |= 1 << j;
				else if (j <= 32 * 23) A[i][ 9] |= 1 << j;
				else if (j <= 32 * 24) A[i][ 8] |= 1 << j;
				else if (j <= 32 * 25) A[i][ 7] |= 1 << j;
				else if (j <= 32 * 26) A[i][ 6] |= 1 << j;
				else if (j <= 32 * 27) A[i][ 5] |= 1 << j;
				else if (j <= 32 * 28) A[i][ 4] |= 1 << j;
				else if (j <= 32 * 29) A[i][ 3] |= 1 << j;
				else if (j <= 32 * 30) A[i][ 2] |= 1 << j;
				else if (j <= 32 * 31) A[i][ 1] |= 1 << j;
				else if (j <= 32 * 32) A[i][ 0] |= 1 << j;
				
			}
	}
}

double testBit(int mode, int Size, uint_fast32_t* K, uint_fast32_t* M, uint_fast32_t* P, uint_fast32_t** a) 
{
	int sign = 0;
	char Buffer[wordCount][33];
	
	sign += (K[0] != 0)  || (K[1] != 0) || (K[2] != 0) || (K[3] != 0) || (K[4] != 0) || (K[5] != 0) || (K[6] != 0) || (K[7] != 0) || (K[8] != 0) || (K[9] != 0)||
		  (K[10] != 0) || (K[11] != 0) || (K[12] != 0) || (K[13] != 0) || (K[14] != 0) || (K[15] != 0) || (K[16] != 0) || (K[17] != 0) || (K[18] != 0) || (K[19] != 0) || 
		  (K[20] != 0) || (K[21] != 0) || (K[22] != 0) || (K[23] != 0) || (K[24] != 0) || (K[25] != 0) || (K[26] != 0) || (K[27] != 0) || (K[28] != 0) || (K[29] != 0) || 
		  (K[30] != 0) || (K[31] != 0);
	while (sign) {						// К пусто ?

		mGlobal++;
		int vIndex = 0;
		uint_fast32_t v[wordCount];
		for (int i = 0; i < wordCount; i++)
			v[i] = 0;

		bool test = 0;
		if (Size <= 1024) {
			for (int i = 0; i < Size; i++) {
				if      (i < 32 * 1 ) { test = (K[31] >> i) & 1u; if (test == 1) { vIndex = i; v[31] |= 1 << i; break; }}
				else if (i < 32 * 2 ) { test = (K[30] >> i) & 1u; if (test == 1) { vIndex = i; v[30] |= 1 << i;	break; }}
				else if (i < 32 * 3 ) { test = (K[29] >> i) & 1u; if (test == 1) { vIndex = i; v[29] |= 1 << i; break; }}
				else if (i < 32 * 4 ) {	test = (K[28] >> i) & 1u; if (test == 1) { vIndex = i; v[28] |= 1 << i; break; }}
				else if (i < 32 * 5 ) { test = (K[27] >> i) & 1u; if (test == 1) { vIndex = i; v[27] |= 1 << i;	break; }}
				else if (i < 32 * 6 ) {	test = (K[26] >> i) & 1u; if (test == 1) { vIndex = i; v[26] |= 1 << i; break; }}
				else if (i < 32 * 7 ) { test = (K[25] >> i) & 1u; if (test == 1) { vIndex = i; v[25] |= 1 << i; break; }}
				else if (i < 32 * 8 ) { test = (K[24] >> i) & 1u; if (test == 1) { vIndex = i; v[24] |= 1 << i; break; }}
				else if (i < 32 * 9 ) { test = (K[23] >> i) & 1u; if (test == 1) { vIndex = i; v[23] |= 1 << i; break; }}
				else if (i < 32 * 10) {	test = (K[22] >> i) & 1u; if (test == 1) { vIndex = i; v[22] |= 1 << i; break; }}
				else if (i < 32 * 11) {	test = (K[21] >> i) & 1u; if (test == 1) { vIndex = i; v[21] |= 1 << i;	break; }}
				else if (i < 32 * 12) { test = (K[20] >> i) & 1u; if (test == 1) { vIndex = i; v[20] |= 1 << i; break; }}
				else if (i < 32 * 13) { test = (K[19] >> i) & 1u; if (test == 1) { vIndex = i; v[19] |= 1 << i; break; }}
				else if (i < 32 * 14) { test = (K[18] >> i) & 1u; if (test == 1) { vIndex = i; v[18] |= 1 << i; break; }}
				else if (i < 32 * 15) { test = (K[17] >> i) & 1u; if (test == 1) { vIndex = i; v[17] |= 1 << i; break; }}
				else if (i < 32 * 16) { test = (K[16] >> i) & 1u; if (test == 1) { vIndex = i; v[16] |= 1 << i; break; }}
				else if (i < 32 * 17) { test = (K[15] >> i) & 1u; if (test == 1) { vIndex = i; v[15] |= 1 << i; break; }}
				else if (i < 32 * 18) { test = (K[14] >> i) & 1u; if (test == 1) { vIndex = i; v[14] |= 1 << i; break; }}
				else if (i < 32 * 19) { test = (K[13] >> i) & 1u; if (test == 1) { vIndex = i; v[13] |= 1 << i; break; }}
				else if (i < 32 * 20) { test = (K[12] >> i) & 1u; if (test == 1) { vIndex = i; v[12] |= 1 << i; break; }}
				else if (i < 32 * 21) { test = (K[11] >> i) & 1u; if (test == 1) { vIndex = i; v[11] |= 1 << i; break; }}
				else if (i < 32 * 22) { test = (K[10] >> i) & 1u; if (test == 1) { vIndex = i; v[10] |= 1 << i; break; }}
				else if (i < 32 * 23) { test = (K[ 9] >> i) & 1u; if (test == 1) { vIndex = i; v[ 9] |= 1 << i; break; }} 
				else if (i < 32 * 24) { test = (K[ 8] >> i) & 1u; if (test == 1) { vIndex = i; v[ 8] |= 1 << i; break; }}
				else if (i < 32 * 25) { test = (K[ 7] >> i) & 1u; if (test == 1) { vIndex = i; v[ 7] |= 1 << i; break; }}
				else if (i < 32 * 26) { test = (K[ 6] >> i) & 1u; if (test == 1) { vIndex = i; v[ 6] |= 1 << i; break; }}
				else if (i < 32 * 27) { test = (K[ 5] >> i) & 1u; if (test == 1) { vIndex = i; v[ 5] |= 1 << i; break; }}
				else if (i < 32 * 28) { test = (K[ 4] >> i) & 1u; if (test == 1) { vIndex = i; v[ 4] |= 1 << i; break; }}
				else if (i < 32 * 29) {	test = (K[ 3] >> i) & 1u; if (test == 1) { vIndex = i; v[ 3] |= 1 << i; break; }}
				else if (i < 32 * 30) {	test = (K[ 2] >> i) & 1u; if (test == 1) { vIndex = i; v[ 2] |= 1 << i; break; }}
				else if (i < 32 * 31) { test = (K[ 1] >> i) & 1u; if (test == 1) { vIndex = i; v[ 1] |= 1 << i; break; }}
				else                  { test = (K[ 0] >> i) & 1u; if (test == 1) { vIndex = i; v[ 0] |= 1 << i; break; }}
			}
		}
		
		for (int i = 0; i < wordCount; i++)
			K[i] = K[i] & ~v[i];			// K = K del v
	
		for (int i = 0; i < wordCount; i++)
			itoa(v[i], Buffer[i], 2);

		uint_fast32_t Mnew[wordCount], Knew[wordCount], Pnew[wordCount];
		for (int i = 0; i < wordCount; i++) {
			Pnew[i] = 0;
			Mnew[i] = 0;
			Knew[i] = 0;

			Mnew[i] = M[i];
			Pnew[i] = P[i] | v[i];
			Knew[i] = K[i];
		}



		sign = 0;
		for (int i = 0; i < wordCount; i++)
			K[i] = K[i] & a[vIndex][i];
		
		sign += (K[0] != 0)  || (K[1] != 0)  || (K[2] != 0)  || (K[3] != 0)  || (K[4] != 0)  || (K[5] != 0)  || (K[6] != 0)  || (K[7] != 0)  || (K[8] != 0)  || (K[9] != 0) ||
			  (K[10] != 0) || (K[11] != 0) || (K[12] != 0) || (K[13] != 0) || (K[14] != 0) || (K[15] != 0) || (K[16] != 0) || (K[17] != 0) || (K[18] != 0) || (K[19] != 0) ||
			  (K[20] != 0) || (K[21] != 0) || (K[22] != 0) || (K[23] != 0) || (K[24] != 0) || (K[25] != 0) || (K[26] != 0) || (K[27] != 0) || (K[28] != 0) || (K[29] != 0) ||
			  (K[30] != 0) || (K[31] != 0);

		for (int i = 0; i < wordCount; i++) {
			M[i] = M[i] | v[i];
			P[i] = P[i] & a[vIndex][i];
		}

		testBit(mode, Size, Knew, Mnew, Pnew, a);

		int temp = 0;
		for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
			temp += K[i] + P[i];
		if (temp == 0)
			clickCounter++;
		
		if (mode == 1) {
			if (temp == 0) {
				for (int i = 0; i < wordCount; i++)
					itoa(M[i], Buffer[i], 2);
				FILE* Clicks;
				Clicks = fopen("Clicks.txt", "a");
				fprintf(Clicks, ">>Click[%010d]:   ", clickCounter);
				for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
					fprintf(Clicks, "%032s ", Buffer[i]);
				fprintf(Clicks, "\n");
				fclose(Clicks);
			}
		}
		
		
	}
	mGlobal++;

	return mGlobal;
}

double testBitOne(int Size, uint_fast32_t* K, uint_fast32_t* M, uint_fast32_t* P, uint_fast32_t** a) {

	char Buffer[wordCount][33];

	mGlobal++;
	int vIndex = 0;
	uint_fast32_t v[wordCount];
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;
	v[5] = 0;
	v[6] = 0;
	v[7] = 0;
	v[8] = 0;
	v[9] = 0;

	bool test = 0;


	if (Size <= 32*10) {
		for (int i = 0; i < Size; i++) {
			if (i < 32 * 1) {
				test = (K[9] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[9] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 2) {
				test = (K[8] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[8] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 3) {
				test = (K[7] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[7] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 4) {
				test = (K[6] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[6] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 5) {
				test = (K[5] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[5] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 6) {
				test = (K[4] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[4] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 7) {
				test = (K[3] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[3] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 8) {
				test = (K[2] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[2] |= 1 << i;
					break;
				}
			}
			else if (i < 32 * 9) {
				test = (K[1] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[1] |= 1 << i;
					break;
				}
			}
			else {
				test = (K[0] >> i) & 1u;
				if (test == 1) {
					vIndex = i;					// vIndex = очередному K
					v[0] |= 1 << i;
					break;
				}
			}
		}
	}
	for (int i = 0; i < wordCount; i++)
		K[i] = K[i] & ~v[i];			// K = K del v

	uint_fast32_t Mnew[wordCount], Knew[wordCount], Pnew[wordCount];
	for (int i = 0; i < wordCount; i++) {
		Pnew[i] = 0;
		Mnew[i] = 0;
		Knew[i] = 0;

		Mnew[i] = M[i];
		Pnew[i] = P[i] | v[i];
		Knew[i] = K[i];
	}



	for (int i = 0; i < wordCount; i++)
		K[i] = K[i] & a[vIndex][i];



	for (int i = 0; i < wordCount; i++) {
		M[i] = M[i] | v[i];
		P[i] = P[i] & a[vIndex][i];
	}


	for (int i = 0; i < wordCount; i++)
		itoa(Knew[i], Buffer[i], 2);
	FILE* newLeftK;
	newLeftK = fopen("2/K.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newLeftK, "%032s ", Buffer[i]);
	fprintf(newLeftK, "\n");
	fclose(newLeftK);

	for (int i = 0; i < wordCount; i++)
		itoa(Mnew[i], Buffer[i], 2);
	FILE* newLeftM;
	newLeftM = fopen("2/M.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newLeftM, "%032s ", Buffer[i]);
	fprintf(newLeftM, "\n");
	fclose(newLeftM);

	for (int i = 0; i < wordCount; i++)
		itoa(Pnew[i], Buffer[i], 2);
	FILE* newLeftP;
	newLeftP = fopen("2/P.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newLeftP, "%032s ", Buffer[i]);
	fprintf(newLeftP, "\n");
	fclose(newLeftP);


	for (int i = 0; i < wordCount; i++)
		itoa(K[i], Buffer[i], 2);
	FILE* newRightK;
	newRightK = fopen("1/K.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newRightK, "%032s ", Buffer[i]);
	fprintf(newRightK, "\n");
	fclose(newRightK);

	for (int i = 0; i < wordCount; i++)
		itoa(M[i], Buffer[i], 2);
	FILE* newRightM;
	newRightM = fopen("1/M.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newRightM, "%032s ", Buffer[i]);
	fprintf(newRightM, "\n");
	fclose(newRightM);

	for (int i = 0; i < wordCount; i++)
		itoa(P[i], Buffer[i], 2);
	FILE* newRightP;
	newRightP = fopen("1/P.txt", "w");

	for (int i = wordCount - ceil(Size / 32.0); i < wordCount; i++)
		fprintf(newRightP, "%032s ", Buffer[i]);
	fprintf(newRightP, "\n");
	fclose(newRightP);

	return 0;
}

uint_fast32_t main(uint_fast32_t argc, char* argv[])
{
	FILE* Clicks;
	vector<int>D;
	fclose;
	int P = 0;
	float p = 0.5;
	
	int filesF = 0;
	int mode = 0;
	int detailedClicks = 0;
	int matrixOptimization = 0;
	uint_fast32_t matrixAFlag = 1;
	char Buffer[wordCount][33];

	
	setlocale(LC_ALL, "Russian");
	for (uint_fast32_t i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			cout << endl << endl;
			cout << ">>--------------------------   Info   --------------------------<<" << endl;
			cout << ">>  -i     |  Информация о параметрах                               <<" << endl;
			cout << ">>  -c     |  Вывод клик в файл (полный граф)                       <<" << endl;
			cout << ">>  -d     |  Чтение матрицы с файла                                <<" << endl;
			cout << ">>  -s     |  Размер обрабатываемой матрицы                         <<" << endl;
			cout << ">>  -m     |  режим работы:                                         <<" << endl;
			cout << ">>         |    - по умолчанию рекурсивный алгоритм                 <<" << endl;
			cout << ">>         |    - один шаг                                          <<" << endl;
			cout << ">>  -k     |  чтение K,M,P из файлов                                <<" << endl;
			cout << ">>  -p     |  выроятность 1-ы в интервале [0,100] (По умолчанию 50) <<" << endl;
			cout << ">>  -opt N |  вариант переупорядочивания:                           <<" << endl;
			cout << ">>         |  N = 1 - переупорядочивание вершин в матрице           <<" << endl;
			//cout << ">>         |  N = 2 - переупорядочивание списка кандидатов          <<" << endl;
			cout << ">>--------------------------------------------------------------<<" << endl;
			cout << endl;
			return 0;
		}
		if (strcmp(argv[i], "-d") == 0)
		{
			matrixAFlag = 0;

		}
		if (strcmp(argv[i], "-opt") == 0)
		{
			if (argv[i + 1][0] != '-')
				sscanf(argv[i + 1], "%d", &matrixOptimization);
		}

		if (strcmp(argv[i], "-c") == 0)
		{
			detailedClicks = 1;

		}
		if (strcmp(argv[i], "-k") == 0)
		{
			filesF = 1;

		}

		if (strcmp(argv[i], "-s") == 0)
		{
			if (argv[i + 1][0] != '-')
				sscanf(argv[i + 1], "%d", &Size);
		}

		//if (strcmp(argv[i], "-m") == 0)
		//{
		//	mode = 1;
		//}


		if (strcmp(argv[i], "-p") == 0)
		{
			if (argv[i + 1][0] != '-')
				sscanf(argv[i + 1], "%d", &P);
			p = float(P) / 100;
		}
	}

	uint_fast32_t Kb[wordCount], Mb[wordCount], Pb[wordCount];
	uint_fast32_t** A = new uint_fast32_t * [Size];
	for (int i = 0; i < Size; i++)
		A[i] = new uint_fast32_t[wordCount];

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < wordCount; j++)
			A[i][j] = 0;
	}



	if (detailedClicks == 1)
		Clicks = fopen("Clicks.txt", "w");
	//printf("Размерность матрицы:");
	//scanf("%d", &n);
	uint_fast32_t** a = new uint_fast32_t * [Size];
	for (int i = 0; i < Size; i++)
		a[i] = new uint_fast32_t[Size];
	//a[0][0] = 0; a[1][0] = 1; a[2][0] = 1; a[3][0] = 0; a[4][0] = 0;
	//a[0][1] = 1; a[1][1] = 0; a[2][1] = 0; a[3][1] = 0; a[4][1] = 1;
	//a[0][2] = 1; a[1][2] = 0; a[2][2] = 0; a[3][2] = 1; a[4][2] = 1;
	//a[0][3] = 0; a[1][3] = 0; a[2][3] = 1; a[3][3] = 0; a[4][3] = 1;
	//a[0][4] = 0; a[1][4] = 1; a[2][4] = 1; a[3][4] = 1; a[4][4] = 0; 

	if (matrixAFlag)
	{
		srand(time(0));

		for (uint_fast32_t i = 0; i < Size; i++)
		{
			for (uint_fast32_t j = i; j < Size; j++)
			{
				if (i == j)
				{
					a[i][j] = 0;
				}
				else
				{
					if (rand() % 100 > (p * 100))
					{
						a[i][j] = 0;
						a[j][i] = 0;
					}
					else
					{
						a[i][j] = 1;
						a[j][i] = 1;
					}
				}
			}
		}
		matrixEntry(a, Size, fopen("MatrixAGen.txt", "w"));
	}
	else {
		string line;
		ifstream inMatrixA("MatrixA.txt");
		if (inMatrixA.is_open())
		{
			for (uint32_t i = 0; i < Size; i++)
			{
				getline(inMatrixA, line);
				smatch number;
				string digits;
				for (uint_fast32_t j = 0; j < Size; j++) {

					if (regex_search(line, number, regex("[0-1]")))
						a[i][j] = stoi(number[0]);
					line = line.substr(number.position() + 1);
				}
			}
		}
		else
		{
			printf("\n\n>>   ERROR: There no such file \"MatrixA.txt\"!\n\n\n");
			system("pause");
			return 2;
		}
	}

	//---------------определение минимальной степени-------------//
	//----------------минимальное количество вершин--------------//
	int* newK = new int[Size];
	uint32_t** A_TEST = new uint32_t * [Size];
	A_TEST = a;
	for (int i = 0; i < Size; i++)
	{
		newK[i] = 0;
		for (int j = 0; j < Size; j++)
		{
			if (A_TEST[i][j] == 1)
				newK[i] += 1;
			
		}
		//cout << i << "  " << newK[i] << endl;
	}
	//---------------переупорядочивание вершин в матрице-------------//
	if (matrixOptimization == 1)
	{
		vector<int> twoCounter;
		vector<int> Glob;
		for (int i = 0; i < Size; i++)
			Glob.push_back(i);

		uint_fast32_t** b = new uint_fast32_t * [Size];
		for (int i = 0; i < Size; i++)
			b[i] = new uint_fast32_t[Size];
		
		string* temp = new string[Size];
		string line;
		ifstream inMatrixA("MatrixA.txt");

		for (int i = 0; i < Size; i++)
			for (int j = 0; j < Size; j++)
				b[i][j] = a[i][j];
		int g = 0;
		while ((Size - g) != 0)
		{
			//счетчик единиц
			vector<int> oneCounter;
			for (int i = 0; i < Size - g; i++)
			{
				oneCounter.push_back(0);

				for (int j = 0; j < Size - g; j++)
				{
					if (a[i][j] == 1)
						oneCounter.back()++;

				}
			}
			
			//сложная индексация 
			vector<int>oneCounter1(oneCounter);
			sort(oneCounter1.begin(), oneCounter1.end());


			//вырожденость матрицы (для статистики)
			D.push_back(oneCounter1.front());
			
			int fix = -1;
			for (int i = 0; i < Size - g; i++){
				for (int j = 0; j < Size - g; j++)
					if (oneCounter1[i] == oneCounter[j]){
						twoCounter.push_back(Glob[j]);//twoCounter - новый порядок
						fix = j;
						Glob.erase(Glob.begin() + j);
						break;
					}
				break;
			}
			//сдвиг строки и столбца 
			for (int i = fix; i < Size - g; i++)
			{
				a[i] = a[i + 1];
			}
			g++;

			for (int i = 0; i < Size - g; i++)
			{
				for (int j = fix; j < Size; j++)
					a[i][j] = a[i][j + 1];

			}


		}

		//for (int i = 0; i < twoCounter.size(); i++)
		//	cout << twoCounter[i] << endl;
		uint_fast32_t* tempArr = new uint_fast32_t[Size];
		
		vector<int>tempOrder;
		for (int i = 0; i < Size; i++)
		{
			tempOrder.push_back(i);
		}

		//
		for (int i = 0; i < Size; i++)
		{
			if (i < Size)
			{
				int t1 = tempOrder[i];
				int fix = 0;
				for (int k = 0; k < Size; k++)
					if (twoCounter[i] == tempOrder[k])
						fix = k;
				
				tempOrder[fix] = tempOrder[i];
				tempOrder[i] = twoCounter[i];
				
				tempArr = b[i];
				b[i] = b[fix];
				b[fix] = tempArr;
				
				int tempT = 0;
				for (int j = 0; j < Size; j++)
				{
					
					tempT = b[j][i];
					b[j][i] = b[j][fix];
					
					b[j][fix] = tempT;
				}
			}
			
		}

		//вывод
		ofstream matrixA("Matrix.txt");
		for (int k = 0; k < Size; k++)
		{
			for (int j = 0; j < Size; j++)
			{
				matrixA << b[k][j] << " ";
			}
			matrixA << endl;
		}
		////////////////////////////////////////////////////////////////
		matrixA.close();


		cout << ">> The vertices in the matrix are reordered" << endl;














































		
		uint_fast32_t*k = new uint_fast32_t[Size];
		uint_fast32_t*m = new uint_fast32_t[Size];
		uint_fast32_t*p = new uint_fast32_t[Size];
		for (int i = 0; i < Size; i++)
		{
			m[i] = 0;
			k[i] = 0;
			p[i] = 0;
		}
		
		ofstream K;
		ofstream M;
		ofstream P;
		K.open("K.txt", ios::trunc);
		K << " \t";
		for (int j = Size - 1; j > -1; j--)
			K << j << " ";
		K << endl << endl;
		M.open("M.txt", ios::trunc);
		M << " \t";
		for (int j = Size - 1; j > -1; j--)
			M << j << " ";
		M << endl << endl;
		P.open("P.txt", ios::trunc);
		P << " \t";
		for (int j = Size - 1; j > -1; j--)
			P << j << " ";
		P << endl << endl;
		
		for (int i = 0; i < Size; i++)
		{
			ofstream KMP;
			
			KMP.open("KMP" + to_string(i) + ".txt");
			

			for (int j = 0; j < Size; j++)
			{
				p[j] = b[i][j];
				k[j] = b[i][j];
			}
			int ms = -1;
			for (int j = 0; j < Size; j++)
			{
				m[i] = 1;
				if (m[j] == 1)
					ms = j;
			}

			for (int j = 0; j < Size; j++)
			{
				if (j > ms)
				{
					k[j] = k[j] & !m[j];
					p[j] = 0;
				}
				else
				{
					k[j] = 0;
					p[j] = p[j] & !m[j];
				}
			}
			KMP << "K:\t";
			K<<i<< ":\t";
			for (int j = Size - 1; j > -1; j--)
			{
				KMP << k[j] << " ";
				K << k[j] << " ";
			}
			K << endl;
			KMP << endl << "M:\t";

			M << i << ":\t";
			for (int j = Size - 1; j > -1; j--)
			{
				KMP << m[j] << " ";
				M << m[j] << " ";
			}
			M << endl;
			KMP << endl << "P:\t";
			P << i << ":\t";
			for (int j = Size-1; j >-1; j--)
			{
				KMP << p[j] << " ";
				P << p[j] << " ";
			}
			P << endl;
			KMP<<endl;
			m[i] = 0;
			KMP.close();

		}
		
		K << endl;
		M << endl;
		P << endl;
		K.close();
		M.close();
		P.close();
		
		dataReorganization(b, A);
		
		ofstream Piks;
		ofstream Clics;
		Piks.open("Piks.txt");
		Clics.open("Clics.txt");
		
		for (int i = 0; i < Size; i++)
		{
			
			clickCounter = 0;
			for (int k = 0; k < wordCount; k++)
			{
				Pb[k] = 0;
				Mb[k] = 0;
				Kb[k] = 0;
			}
			
			ifstream in("KMP" + to_string(i) + ".txt");
			if (in.is_open())
			{
				smatch number;
				while(getline(in, line))
				if (line[0] == 'K')
				{
					line = line.substr(3);
					lineHandler(Kb, line, number);
					
				}else if (line[0] == 'M')
				{
					line = line.substr(3);
					lineHandler(Mb, line, number);
				}
				else if (line[0] == 'P')
				{
					line = line.substr(3);
					lineHandler(Pb, line, number);
				}
				printf(">>\tIteration %d\t<<\n", i);
					
				printBuffer(Kb, ">>K:\t");
				printBuffer(Mb, ">>M:\t");
				printBuffer(Pb, ">>P:\t");
				printf("\n");
					long long int  temp2=0;
					mGlobal = 0;
					FILE* Clicks;
					Clicks = fopen("Clicks.txt", "a");
					fprintf(Clicks, "<<----------------Iter %d------------------(from left to right)\n", i);
					fclose(Clicks);

					temp2 = testBit(detailedClicks, Size, Kb, Mb, Pb, A);

					Clicks = fopen("Clicks.txt", "a");
					fprintf(Clicks, "\n");
					fclose(Clicks);
					
					Piks << i<<":\t" << temp2 << endl;
					Clics << i<<":\t"<< clickCounter << endl;
			}
			in.close();
			string name = "KMP" + to_string(i) + ".txt";
			remove(name.c_str());
		}
		

		sort(D.begin(), D.end());
		Piks << "D_MAX = " << D.back() << endl;
		Clics << "D_MAX = " << D.back() << endl;
		Piks.close();
		Clics.close();
		return 0;
	}
	else if (matrixOptimization == 2)
	{
	}






































































	dataReorganization(a, A);
	
	for (int i = 0; i < wordCount; i++)
	{
		Pb[i] = 0;
		Mb[i] = 0;
		Kb[i] = 0;
	}

	if (filesF == 0) {

		if (Size < 32 * 1)
			for (int j = 0; j < Size; j++)
				Kb[31] |= 1 << j;
		else if (Size < 32 * 2) {
			for (int j = 0; j < 32 * 1; j++)
				Kb[31] |= 1 << j;
			for (int j = 0; j < Size - 32 * 1; j++)
				Kb[30] |= 1 << j;
		}
		else if (Size < 32 * 3) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 2; j++)
				Kb[29] |= 1 << j;
		}
		else if (Size < 32 * 4) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 3; j++)
				Kb[28] |= 1 << j;
		}
		else if (Size < 32 * 5) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 4; j++)
				Kb[27] |= 1 << j;
		}
		else if (Size < 32 * 6) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 5; j++)
				Kb[26] |= 1 << j;
		}
		else if (Size < 32 * 7) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 6; j++)
				Kb[25] |= 1 << j;
		}
		else if (Size < 32 * 8) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 7; j++)
				Kb[24] |= 1 << j;
		}
		else if (Size < 32 * 9) {
			for (int j = 0; j < 32; j++)
			{
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 8; j++)
				Kb[23] |= 1 << j;
		}
		else if (Size < 32 * 10) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 9; j++)
				Kb[22] |= 1 << j;
		}
		else if (Size < 32 * 11) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 10; j++)
				Kb[21] |= 1 << j;
		}
		else if (Size < 32 * 12) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
				Kb[21] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 11; j++)
				Kb[20] |= 1 << j;
		}
		else if (Size < 32 * 13) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
				Kb[21] |= 1 << j;
				Kb[20] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 12; j++)
				Kb[19] |= 1 << j;
		}
		else if (Size < 32 * 14) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
				Kb[21] |= 1 << j;
				Kb[20] |= 1 << j;
				Kb[19] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 13; j++)
				Kb[18] |= 1 << j;
		}
		else if (Size < 32 * 15) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
				Kb[21] |= 1 << j;
				Kb[20] |= 1 << j;
				Kb[19] |= 1 << j;
				Kb[18] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 14; j++)
				Kb[17] |= 1 << j;
		}
		else if (Size < 32 * 16) {
			for (int j = 0; j < 32; j++) {
				Kb[31] |= 1 << j;
				Kb[30] |= 1 << j;
				Kb[29] |= 1 << j;
				Kb[28] |= 1 << j;
				Kb[27] |= 1 << j;
				Kb[26] |= 1 << j;
				Kb[25] |= 1 << j;
				Kb[24] |= 1 << j;
				Kb[23] |= 1 << j;
				Kb[22] |= 1 << j;
				Kb[21] |= 1 << j;
				Kb[20] |= 1 << j;
				Kb[19] |= 1 << j;
				Kb[18] |= 1 << j;
				Kb[17] |= 1 << j;
			}
			for (int j = 0; j < Size - 32 * 15; j++)
				Kb[16] |= 1 << j;
		}
		else if (Size < 32 * 17) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 16; j++)
			Kb[15] |= 1 << j;
		}
		else if (Size < 32 * 18) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 17; j++)
			Kb[14] |= 1 << j;
		}
		else if (Size < 32 * 19) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 18; j++)
			Kb[13] |= 1 << j;
		}
		else if (Size < 32 * 20) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 19; j++)
			Kb[12] |= 1 << j;
		}
		else if (Size < 32 * 21) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 20; j++)
			Kb[11] |= 1 << j;
		}
		else if (Size < 32 * 22) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 21; j++)
			Kb[10] |= 1 << j;
		}
		else if (Size < 32 * 23) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 22; j++)
			Kb[ 9] |= 1 << j;
		}
		else if (Size < 32 * 24) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[ 9] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 23; j++)
			Kb[ 8] |= 1 << j;
		}
		else if (Size < 32 * 25) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 24; j++)
			Kb[7] |= 1 << j;
		}
		else if (Size < 32 * 26) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 25; j++)
			Kb[6] |= 1 << j;
		}
		else if (Size < 32 * 27) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 26; j++)
			Kb[5] |= 1 << j;
		}
		else if (Size < 32 * 28) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
			Kb[5] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 27; j++)
			Kb[4] |= 1 << j;
		}
		else if (Size < 32 * 29) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
			Kb[5] |= 1 << j;
			Kb[4] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 28; j++)
			Kb[3] |= 1 << j;
		}
		else if (Size < 32 * 30) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
			Kb[5] |= 1 << j;
			Kb[4] |= 1 << j;
			Kb[3] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 29; j++)
			Kb[2] |= 1 << j;
		}
		else if (Size < 32 * 31) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
			Kb[5] |= 1 << j;
			Kb[4] |= 1 << j;
			Kb[3] |= 1 << j;
			Kb[2] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 30; j++)
			Kb[1] |= 1 << j;
		}
		else if (Size <= 32 * 32) {
		for (int j = 0; j < 32; j++) {
			Kb[31] |= 1 << j;
			Kb[30] |= 1 << j;
			Kb[29] |= 1 << j;
			Kb[28] |= 1 << j;
			Kb[27] |= 1 << j;
			Kb[26] |= 1 << j;
			Kb[25] |= 1 << j;
			Kb[24] |= 1 << j;
			Kb[23] |= 1 << j;
			Kb[22] |= 1 << j;
			Kb[21] |= 1 << j;
			Kb[20] |= 1 << j;
			Kb[19] |= 1 << j;
			Kb[18] |= 1 << j;
			Kb[17] |= 1 << j;
			Kb[16] |= 1 << j;
			Kb[15] |= 1 << j;
			Kb[14] |= 1 << j;
			Kb[13] |= 1 << j;
			Kb[12] |= 1 << j;
			Kb[11] |= 1 << j;
			Kb[10] |= 1 << j;
			Kb[9] |= 1 << j;
			Kb[8] |= 1 << j;
			Kb[7] |= 1 << j;
			Kb[6] |= 1 << j;
			Kb[5] |= 1 << j;
			Kb[4] |= 1 << j;
			Kb[3] |= 1 << j;
			Kb[2] |= 1 << j;
			Kb[1] |= 1 << j;
		}
		for (int j = 0; j < Size - 32 * 31; j++)
			Kb[0] |= 1 << j;
		}
	}
	else {
		string line;
		ifstream inK("K.txt");
		if (inK.is_open())
		{
			getline(inK, line);
			smatch number;
			lineHandler(Kb, line, number);

		}
		else
		{
			printf("\n\n>>   ERROR: There no file \"K.txt\"!\n\n\n");
			system("pause");
			return 2;
		}

		ifstream inM("M.txt");
		if (inM.is_open())
		{
			getline(inM, line);
			smatch number;
			lineHandler(Mb, line, number);

		}
		else
		{
			printf("\n\n>>   ERROR: There no file \"M.txt\"!\n\n\n");
			system("pause");
			return 2;
		}

		ifstream inP("P.txt");
		if (inP.is_open())
		{
			getline(inP, line);
			smatch number;
			lineHandler(Pb, line, number);
		}
		else
		{
			printf("\n\n>>   ERROR: There no file \"K.txt\"!\n\n\n");
			system("pause");
			return 2;
		}
	}

	printBuffer(Kb, ">>K\t");
	printBuffer(Mb, ">>M\t");
	printBuffer(Pb, ">>P\t");
	printf("\n");

	for (int i = 0; i < Size; i++) {
		printBuffer(A[i], "A["+to_string(i)+"]:\t");
	}

	double t3, t4;
	long long int  temp2;
	t3 = get_time();
	if (mode == 0)
		temp2 = testBit(detailedClicks, Size, Kb, Mb, Pb, A);
	else {
		mkdir("1");
		matrixEntry(a, Size, fopen("1\\MatrixA.txt", "w"));
		mkdir("2");
		matrixEntry(a, Size, fopen("2\\MatrixA.txt", "w"));

		temp2 = testBitOne(Size, Kb, Mb, Pb, A);
	}
	t4 = get_time();
	show_time(t4 - t3);
	FILE* gCount;
	if (mGlobal != 1) {
		gCount = fopen("PicksCount.txt", "w");
		fprintf(gCount, "Piks   >>   %0I64d \n", temp2);
		fprintf(gCount, "Clicks >>   %0I64d \n", clickCounter);
		fclose(gCount);
	}
	
	

}
