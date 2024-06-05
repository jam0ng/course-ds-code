#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"

// 공백 graph를 생성하는 연산
void createGraph(graphType* g) {
	int i, j;								// 행렬을 생각해서 i 행(row)의 숫자, j 열(column)의 숫자
	g->n = 0;								// 정점(Vertex) 개수를 0으로 초기화
	for (i = 0; i < MAX_VERTEX; i++) {		// row을 반복하는 반복문
		for (j = 0; j < MAX_VERTEX; j++)	// column을 반복하는 반복문
			g->adjMatrix[i][j] = 0;			// graph g에 대한 2차원 배열의 값을 0으로 초기화
	}
}

// graph g에 Vertex - v를 삽입하는 연산
void insertVertex(graphType* g, int v) {	
	if (((g->n) + 1) > MAX_VERTEX) {		// Vertex의 개수가 MAX를 넘었는지 확인
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;									// graph Vertex의 개수 n을 하나 증가
}

// graph g에 edge (u, v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	// Edge (u, v)를 삽입하기 위해 정점 u와 v가 graph에 존재하는지 확인
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;					// 삽입한 edge에 대한 2차원 배열의 원소 값을 1로 설정(simple graph)(directed graph)
}

// graph g의 2차원 배열 값을 순서대로 출력하는 연산
void print_adjMatrix(graphType* g) {
	int i, j;								// i(row), j(column)
	for (i = 0; i < (g->n); i++) {			// row 반복문
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++)		// column 반복문
			printf("%2d", g->adjMatrix[i][j]);		// i,j 번째의 데이터 출력
	}
}
