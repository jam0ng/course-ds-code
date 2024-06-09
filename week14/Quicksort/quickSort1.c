#include <stdio.h>

int i = 0;												// 퀵 정렬 단계 출력용 변수

// 주어진 부분집합 안에서 pivot의 위치를 확정하여 분할 위치를 정하는 연산
int partition(int a[], int begin, int end, int size) {

	int pivot, L, R, t, temp;
	L = begin;
	R = end;
	pivot = (begin + end) / 2;	// 중간에 위치한 원소를 pivot 원소로 선택(핵심)
	printf("\n [%d단계 : pivot = %d ] \n", ++i, a[pivot]);
 	while (L < R) {										// 왼쪽을 담당하는 인덱스가 오른쪽을 담당하는 인덱스보다 작을 때 반복
		while ((a[L] < a[pivot]) && (L < R)) L++;		// 왼쪽 부분을 돌아다니면서 pivot에 있는 값보다 큰 값을 발견하면 L을 그 자리에 고정, L은 R을 만나면 더 이상 오른쪽으로 갈 수 없음			(핵심)
		while ((a[R] >= a[pivot]) && (L < R)) R--;		// 오른쪽 부분을 돌아다니면서 pivot에 있는 값보다 작거나 같은 값을 발견하면 R을 그 자리에 고정, R을 L을 만나면 더이상 왼쪽으로 갈 수 없음	(핵심)
		if (L < R) {									// L 과 R 모두 pivot을 기준으로 자기 영역 안에서 원하는 값을 찾음
			temp = a[L];								// L 과 R 원소의 자리 교환(핵심)
			a[L] = a[R];								//(핵심)
			a[R] = temp;								//(핵심)
			// L이 pivot인 경우, 변경된 pivot의 위치(R)를 다시 저장!(그냥 pivot 위치 따라가는 거 비교해야하니까 pivot을 기준으로)
			if (L == pivot) pivot = R;
		} // if(L<R)
	} // while(L<R)
	 // (L=R)이 된 경우, (pivot을 기준으로 왼쪽과 오른쪽이 모두 분류가 끝났거나(L=pivot=R), 제일 작거나 컸다면 L=R은 같지만 pivot은 같지 않음 그러므로 R을 리턴해주는 것 R이 도달한 있는 위치를 바탕으로 양쪽이 정렬되어 있음)
	 // 더 이상 진행할 수 없으므로 R 원소와 pivot 원소의 자리를 교환하여 마무리
	temp = a[pivot];									// L = R 이지만 pivot이 아닐 경우, 원소 자리를 교환 분류가 모두 되었다면 값은 바뀌지 않음(핵심)
	a[pivot] = a[R];									//(핵심)
	a[R] = temp;										//(핵심)
	for (t = 0; t < size; t++) printf("%4d", a[t]);		// 현재의 정렬 상태 출력
	printf("\n\n");										
	return R;											// 정렬되어 확정된 피봇의 위치 반환
}

void quickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end) {									// 시작과 끝이 동일하거나 끝이 작다면 넘어감
		printf("시작 인덱스 : %d 끝 인덱스 %d", begin, end );
		p = partition(a, begin, end, size);				// 중간을 나누고
		quickSort(a, begin, p - 1, size);				// 중간을 기준으로 왼쪽 정렬
		quickSort(a, p + 1, end, size);					// 중간을 기준으로 오른쪽 정렬
	}
}