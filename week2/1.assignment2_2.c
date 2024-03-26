#include <stdio.h>

void main()
{
	int array[2][3][4];
	int plane, row, column, value = 0;
	for (plane = 0; plane < 2; plane++) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 4; column++) {
				array[plane][row][column] = value;
				printf("\n array[%d][%d][%d] = %d", plane, row, column, array[plane][row][column]);
				value++;
			}
		}
	}
	getchar();
}
