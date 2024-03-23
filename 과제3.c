#include <stdio.h>

int main(void)
{
	int plane, row, column;
	char student[2][3][20];
	for (plane = 0; plane < 2; plane++) {
		printf("\n학생 %d의 이름 : ", plane + 1);
		gets(student[plane][0]);
		printf("\n학생 %d의 학과 : ", plane + 1);
		gets(student[plane][1]);
		printf("\n학생 %d의 학번 : ", plane + 1);
		gets(student[plane][2]);
	}

	for (plane = 0; plane < 2; plane++) {
		printf("\n\n학생%d", plane + 1);
		for (row = 0; row < 3; row++) {
			printf("\n\t");
			for (column = 0; student[plane][row][column] != '\0'; column++) {
				printf("%c", student[plane][row][column]);
			}
		}
	}

	getchar();
}
