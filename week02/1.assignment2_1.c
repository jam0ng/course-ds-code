#include <stdio.h>

int main(void)
{
	char string[10];
	int count = 0;
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(string);


	for (int i = 0; string[i] != '\0'; i++) {
		count = count + 1;
	}
	printf("\n�Էµ� ���ڿ���\n\"%s\"\n�Դϴ�.\n", string);
	printf("\n�Էµ� ���ڿ��� ���� = %d", count);
	
	getchar();
}