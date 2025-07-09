#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

DQueType* createDQue() {	//���� ��ũ�� �����ϴ� ����
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isDeQEmpty(DQueType* DQ) {			// ���� Ȯ���ϴ� ����
	if (DQ->front == NULL) return 1;		
	else return 0;
}

void insertFront(DQueType* DQ, element item) {		//�տ� ���Ҹ� �ִ� �Լ�
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {			// �����̶�� ��� ������ ��ũ�� ���� ��ũ �� �� NULL�� �ְ� front�� rear�� newNode�� ����Ű�� �����.
		DQ->front = newNode;		 
		DQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->front->llink = newNode;		// ���� front �ڸ��� ����� ���� ��ũ ���� newNode �ּҷ�
		newNode->rlink = DQ->front;		// newNode ������ �ּ� ���� �� front�� ����Ű�� �ּҷ�
		newNode->llink = NULL;			// ������ �� ��尡 �� ������ ���� �ű� ������ NULL
		DQ->front = newNode;			// front�� �� ���� ����Ű�� ����
	}
}

void insertRear(DQueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;		// �ڷ� ������ �ű� ������ ���� rear �ڸ��� ��� ������ ��ũ ���� NULL -> newNode
		newNode->rlink = NULL;			// �� ��� �������� NULL�� ����� ���� ����
		newNode->llink = DQ->rear;		// ������ ��ũ ���� ���� rear�ڸ� �ּҸ� �ְ�
		DQ->rear = newNode;				// �� rear �ּҷ� newnode
	}
}

element deleteFront(DQueType* DQ) {
	DQNode* old = DQ->front;			// ������ ����� �ּҸ� old�� ��´�.
	element item;						// ������ ��� �ȿ� �ִ� �����͸� ��� ����
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;	// �����̸� �׳� ����
	}
	else {
		item = old->data;					// �����͸� ���
		if (DQ->front->rlink == NULL) {		// �������� �� �� ���� ����Ű�� ����� ������ ��尡 NULL ���ٸ� ���� ť�� �ǹǷ� rear ���� NULL
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {								
			DQ->front = DQ->front->rlink;	//front�� ���� front ����� ������ ���� �ű��	
			DQ->front->llink = NULL;		//�� front ����� ���� ��ũ���� ���� front ����� ���� �����Ƿ� NULL
		}
		free(old);				
		return item;
	}
}

element deleteRear(DQueType* DQ) {
	DQNode* old = DQ->rear;
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = old->data;
		if (DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

element peekFront(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->front->data;
		return item;
	}
}

element peekRear(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf(" \n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->rear->data;
		return item;
	}
}

void printDQ(DQueType* DQ) {
	DQNode* temp = DQ->front;
	printf("DeQue ; [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ] ");
}