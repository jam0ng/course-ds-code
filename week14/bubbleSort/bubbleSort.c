#include <stdio.h>
// bubbleSort 하는 함수
void bubbleSort(int a[], int size) {
	// i : 반복하기 위한 변수이지만 끝부터 정렬하기 때문에 점점 줄어든다., j : i까지 list를 돌면서 j + 1과 비교하며 자리 교환, temp : 임시 int 변수 
	int i, j, t, temp;

	for (i = size - 1; i > 0; i--) {			// list 맨 뒤부터 차례대로 가는 반복문									(핵심)
		printf("\n %d단계>>", size - 1);		
		for (j = 0; j < i; j++) {				// 0부터 i번째까지 j와 j + 1 자리를 비교하면서 위치를 교환하는 반복문	(핵심)
			if (a[j] > a[j + 1]) {				// j와 j + 1 자리 값을 비교(j 자리 값이 크다면)							(핵심)
				temp = a[j];					// temp 에 j 자리 값을 임시 저장 *(j의 자리의 값을 j + 1로 전달)
				a[j] = a[j + 1];				// j 자리에 j + 1 자리 값을 넣고
				a[j + 1] = temp;				// j + 1에 temp(원래 j자리에 있던 값)을 넣는다.
			}
			printf("\n\t");
			for (t = 0; t < size; t++) printf("%3d ", a[t]); // 변경되는 과정을 보기 위해 list를 한 번 출력
		}
	}
}