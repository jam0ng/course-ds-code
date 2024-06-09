#include <stdio.h>

void SelectionSort(int a[], int size){
	int i, j, t, min, temp;
	for (i = 0; i < size - 1; i++) {		// 모든 원소를 정렬하기 위해 반복																										(중요)
		min = i;							// 가장 작은 원소가 있는 인덱스를 저장하는 변수(하지만 0 ~ 배열 끝까지 돌면서 모두 정렬하기 위해 i를 계속 순환하게 함)					(중요)
		for (j = i + 1; j < size; j++) {	// 바꿀 위치 = i 그 앞에 있는 원소를 비교 후 작다면 min에 담고를 반복(마지막까지 min = i 이거나 min이 제일 작은 수가 들어있는 위치가 됨)(중요)
			if (a[j] < a[min])min = j;		//																																		(중요)
		}
		temp = a[i];						// i = 바꿀 위치에 있는 값을 일단 temp에 담고				(중요)
		a[i] = a[min];						// i 자리에 위에서 찾은 작은 값이 있던 min에 있는 값을 넣고	(중요)
		a[min] = temp;						// min 자리에 i값을 넣는다.									(중요)
		printf("\n %d단계 : ", i + 1);		// 출력
		for (t = 0; t < size; t++) printf("%3d", a[t]);
	}
}