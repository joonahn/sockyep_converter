#include <stdio.h>
#include <windows.h>

int main()
{
	char str[200];
	char str2[200];
	wchar_t strUni[200];
	int length;


	printf("input data:");
	scanf("%s",str);

	//length = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
	//MultiByteToWideChar(CP_ACP, 0, str, 200, str2, length);

	//printf(str2);

	//(UTF8)str -> unicode
	length = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, NULL);
	MultiByteToWideChar(CP_UTF8, 0, str, 200, strUni, length);
	wprintf(strUni);

	//unicode -> UTF8
	length = WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), str2, length, NULL, NULL);
	str2[length] = 0;
	printf(str2);
	printf("\n");

	//length = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
	//WideCharToMultiByte(CP_ACP,0,str,-1, str2, length, NULL, NULL);
	//printf("%s",str2);
	system("PAUSE");
	return 0;
}