#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <strsafe.h>
#include <Windows.h>
#include < stdlib.h >

LPWSTR ClipboardOutputText();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	while (TRUE)
	{
		LPSTR Data = ClipboardOutputText();
		TCHAR Alert[] = L"Вы нарушили Авторские права: ";
		TCHAR third[512];

		swprintf(third, sizeof third, L"%s%s", Alert, Data);
		switch (*Data)
		{
		case '1':
			MessageBoxW(NULL,  L"Один", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Один";
			ClipboardInputText(Data);
			break;
		case '2':
			MessageBoxW(NULL, L"Два", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Два";
			ClipboardInputText(Data);
			break;
		case '3':
			MessageBoxW(NULL, L"Три", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Три";
			ClipboardInputText(Data);
			break;
		case '4':
			MessageBoxW(NULL, L"Четыре", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Четыре";
			ClipboardInputText(Data);
			break;
		case '5':
			MessageBoxW(NULL, L"Пять", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Пять";
			ClipboardInputText(Data);
			break;
		case '6':
			MessageBoxW(NULL, L"Шесть", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Шесть";
			ClipboardInputText(Data);
			break;
		case '7':
			MessageBoxW(NULL, L"Семь", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Семь";
			ClipboardInputText(Data);
			break;
		case '8':
			MessageBoxW(NULL, L"Восемь", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Восемь";
			ClipboardInputText(Data);
			break;
		case '9':
			MessageBoxW(NULL, L"Девять", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Девять";
			ClipboardInputText(Data);
			break;
		case '0':
			MessageBoxW(NULL, L"Ноль", NULL, MB_OK | MB_ICONWARNING);
			Data = L"Ноль";
			ClipboardInputText(Data);
			break;
		default:
			break;
		}
		/*if (*Data != 0)
		{
			
			MessageBoxW(NULL, &third, L"Внимание!!! Нарушение!!!", MB_OK | MB_ICONWARNING);
			ClipboardInputText("");
		}*/
		Sleep(1000);
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

Text(LPSTR Data)
{
	
}