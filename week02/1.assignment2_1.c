#include <stdio.h>

int main(void)
{
	char string[10];
	int count = 0;
	printf("문자열을 입력하세요 : ");
	gets(string);


	for (int i = 0; string[i] != '\0'; i++) {
		count = count + 1;
	}
	printf("\n입력된 문자열은\n\"%s\"\n입니다.\n", string);
	printf("\n입력된 문자열의 길이 = %d", count);
	
	getchar();
}