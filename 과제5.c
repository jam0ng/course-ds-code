#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	hanoi(num, 'A', 'B', 'C');
	getchar();
}

int hanoi(int n, char start, char work, char target)
{
	if (n == 1) {
		printf("\n%c에서 원반 %d를(을) %c로 옮김", start, n, target);
		return 0;
	}
	hanoi(n - 1, start, target, work);
	printf("\n%c에서 원반 %d를(을) %c로 옮김", start, n, target);
	hanoi(n - 1, work, start, target);


	return 0;

}