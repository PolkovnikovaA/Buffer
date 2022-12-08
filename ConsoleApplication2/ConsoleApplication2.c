#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <strsafe.h>
#include <Windows.h>
#include < stdlib.h >

LPWSTR ClipboardOutputText();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	int p = 1;
	while (p)
	{
		LPSTR* Data = ClipboardOutputText();
		//TCHAR Alert[] = L"Вы нарушили Авторские права: ";
		char* m = calloc(100, sizeof(char));
		TCHAR third[1024];
		Text(Data);
		Sleep(1000);
		p = 0;
	}
	return 0;
}

TCHAR* ClipboardOutputText()
{
	TCHAR* Mess = NULL;
	OpenClipboard(NULL);	//открыть буфер обмена
	HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);	//записать в буфер обмена данные соответствующего типа
	Mess = (TCHAR*)GlobalLock(hClipboardData);	//считать из глобального участка памяти, привести это все к строке
	GlobalUnlock(hClipboardData);	//освободить глобальные участки памяти
	CloseClipboard();	//закрыть буфер обмена, сделать его доступным для других приложений
	EmptyClipboard();	//очистить буфер обмена

	return Mess;
}

int ClipboardInputText(LPWSTR buffer)
{
	DWORD len;
	HANDLE hMem;
	len = wcslen(buffer) + 1;

	

	hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();

	return 0;
}

Text(TCHAR* Data)
{
	int i = 0;
	TCHAR third[1024];
	char* m = calloc(100, sizeof(char));
	while (Data[i])
	{
		if (Data[i] == '1')
		{
			sprintf(m, "%s%s", m, L"Один");
			MessageBoxW(NULL, L"Один", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '2')
		{
			sprintf(m, "%s%s", m, L"Два");
			MessageBoxW(NULL, L"Два", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '3')
		{
			sprintf(m, "%s%s", m, L"Три");
			MessageBoxW(NULL, L"Три", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '4')
		{
			sprintf(m, "%s%s", m, L"Четыре");
			MessageBoxW(NULL, L"Четыре", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '5')
		{
			sprintf(m, "%s%s", m, L"Пять");
			MessageBoxW(NULL, L"Пять", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '6')
		{
			sprintf(m, "%s%s", m, L"Шесть");
			MessageBoxW(NULL, L"Шесть", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '7')
		{
			sprintf(m, "%s%s", m, L"Семь");
			MessageBoxW(NULL, L"Семь", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '8')
		{
			sprintf(m, "%s%s", m, L"Восемь");
			MessageBoxW(NULL, L"Восемь", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '9')
		{
			sprintf(m, "%s%s", m, L"Девять");
			MessageBoxW(NULL, L"Девять", NULL, MB_OK | MB_ICONWARNING);
		}
		if (Data[i] == '0')
		{
			sprintf(m, "%s%s", m, L"Ноль");
			MessageBoxW(NULL, L"Ноль", NULL, MB_OK | MB_ICONWARNING);
		}
		i++;

	}
	swprintf(third, sizeof(third), L"%s", m);
	ClipboardInputText(third);
}