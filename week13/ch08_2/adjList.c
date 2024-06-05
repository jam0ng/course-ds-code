#include <stdio.h>
#include "adjList.h"

// 공백 graph를 생성하는 연산
void createGraph(graphType* g) {
	int v;								
	g->n = 0;								// graph의 vertex 개수를 0으로 초기화
	for (v = 0; v < MAX_VERTEX; v++)		// (adjList_H[n]이 1 ~ n번의 vertex를 대표함 와 관련된 edge 정보를 연결리스트 형태로 저장하겠다는 의미이기에 배열을 초기화 하는 것)
		g->adjList_H[v] = NULL;				// graph의 vertex에 대한 헤드 포인터 배열을 NULL로 초기화
}

// graph g에 vertex v를 삽입하는 연산(정확히 내가 넣은 값을 추가 해 주는 것이 아니라 그냥 실행 횟수로 증가해주는 함수임)
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {		// (예외) 새로운 vertex를 추가하려는 데 vertex의 최대 개수를 넘었기 때문에 거절		
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;									// graph의 vertex 개수 n을 하나 증가
}

// graph g에 edge (u, v)를 삽입하는 연산(연결을 저장할 때 포인터는 그냥 list 형식으로 저장 나중에 생성된 노드를 head로 지정하고 나머지를 그 뒤로 연결하는 거임)
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	// edge (u, v)를 삽입하기 위해 vertex u와 vertex v가 현재 graph에 있는지 확인
	// 연결하려는 vertex가 graph에 없는 vertex일 경우 생성되어 있는 vertex의 수를 파악(vertex를 숫자로 하기 때문에) 생성되어 있는 수 보다 받으려고 하는 수가 크거나 같으면
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));		
	node->vertex = v;								// vertex 값으로 v를 저장(어디로 가는지 어디랑 연관 되어 있는지)
	node->link = g->adjList_H[u];					// 전에 있던 v를 정보가 담긴 혹은 NULL을 link에 담고(뒤로 밀고)
	g->adjList_H[u] = node;							// head에 이 node의 주소를 넣는다.
}

// graph g의 각 vertex에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType* g) {					
	int i;											
	graphNode* p;									
	for (i = 0; i < g->n; i++) {					// vertex(1 ~ n) = g->adjList_H[i] 이고 i를 돌며 i 번째의 연결리스트를 확인
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);	
		p = g->adjList_H[i];						// 연결리스트 head를 p에 담고
		while (p) {									// p가 NULL이 될 때(끝일 때)까지
			printf(" -> %c", p->vertex + 65);		// vertex 0~3을 A~D로 출력 (+65)
			p = p->link;
		}
	}
}
