#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char array[5][20];
	char* ptr[5];
	
	for (int i = 0; i < 5; i++) {
		gets(array[i]);
		ptr[i] = array[i];
	}

	for (int i = 0; i < 5; i++) {
		printf("\n%s", ptr[i]);
	}



	return 0;
}