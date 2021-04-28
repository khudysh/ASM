#pragma comment(linker, "/MERGE:.data=.text")
#pragma comment(linker, "/MERGE:.rdata=.text")
#pragma comment(linker, "/SECTION:.text,EWR")
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)
//#define STD_OUTPUT_HANDLE ((unsigned __int32)-11)
//#include <stdio.h>

#include <Windows.h>



void Entry(void) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//TCHAR szName[16];
	//TCHAR szResp[32];
	TCHAR szResp[8];
	DWORD dwCount = 0;
	DWORD n = 9;
	char ch[128];
	const TCHAR szMsg[] = L"N = 9";
	short m = 1, a[9][9], i = 0, j = 0;
	//scanf("%hi", &n);
	
	WriteConsole(hStdout, &szMsg, STRLEN(szMsg), &dwCount, NULL);
	//ReadConsole(hStdin, &szName, STRLEN(szName), &dwCount, NULL);
	ReadConsole(hStdin, &ch, 128, &n, NULL);
	//ReadConsoleA(hStdin, buffer, sizeof(szResp), &n, NULL);
	//ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &ch, 300, &n, NULL);
	//n = int(szName[16]) - 32;
	//n = _tstoi(szName);
	wsprintf(szResp, L"\n\n");
	WriteConsole(hStdout, &szResp, lstrlen(szResp), &dwCount, NULL);
	
	if (n % 2 != 0) {
		a[(n / 2)][(n / 2)] = (n * n);
	}

	for (i = 0; i < (n / 2); i++) {
		for (j = i; j < (n - i); j++) {
			a[i][j] = m;
			m++;
		}
		for (j = 1; j < (n - i - i); j++) {
			a[(j + i)][(n - i) - 1] = m;
			m++;
		}
		for (j = (n - 2) - i; j >= i; j--) {
			a[(n - i) - 1][(j)] = m;
			m++;
		}
		for (j = ((n - i) - 2); j > i; j--) {
			a[j][i] = m;
			m++;
		}
	}
	char	Buf[32];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//printf("%d\t", a[i][j]);
			//wsprintfA(Buf, "%d\t", a[i][j]);
			wsprintf(szResp, L"%d\t", a[i][j]);
			WriteConsole(hStdout, &szResp, lstrlen(szResp), &dwCount, NULL);
		}
		//printf("\n");
		//wsprintfA(Buf, "\n");
		wsprintf(szResp, L"\n");
		WriteConsole(hStdout, &szResp, lstrlen(szResp), &dwCount, NULL);
	}
	ExitProcess(0);
}


//HANDLE WINAPI GetStdHandle(__in DWORD nStdHandle);
//int main()
//{
//	short n;
//	short m = 1;
//	//scanf("%hi", &n);
//	short a[81][81];
//
//	if (n % 2 != 0) {
//		a[(n / 2)][(n / 2)] = (n * n);
//	}
//
//	for (int i = 0; i < (n / 2); i++) {
//		for (int j = i; j < (n - i); j++) {
//			a[i][j] = m;
//			m++;
//		}
//		for (int j = 1; j < (n - i - i); j++) {
//			a[(j + i)][(n - i) - 1] = m;
//			m++;
//		}
//		for (int j = (n - 2) - i; j >= i; j--) {
//			a[(n - i) - 1][(j)] = m;
//			m++;
//		}
//		for (int j = ((n - i) - 2); j > i; j--) {
//			a[j][i] = m;
//			m++;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			//printf("%d\t", a[i][j]);
//		}
//		//printf("\n");
//	}
//
//}