#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

LQueueType* createLinkedQueue() {	// ���� ���� ť�� �����ϴ� ����
	LQueueType* LQ;					// Front�� Rear�� ��� �ִ� ����ü�� �����͸� ����
	LQ = (LQueueType*)malloc(sizeof(LQueueType));	// �޸� �Ҵ� �� �ּҰ��� LQ�� �ֱ�
	LQ->front = NULL;							// Front�� Rear�� ���� NULL�� �������μ� ���� �����
	LQ->rear = NULL;
	return LQ;									// LQ �� ��ȯ
}

int isLQEmpty(LQueueType* LQ) {		// ���� ť�� ���� �������� �˻��ϴ� ����
	if (LQ->front == NULL) {			//fornt�� NULL �̶�� ���� 
		//- rear�� �����Ͱ� �߰� �� �� �þ�� front�� �����Ͱ� ���� �� �� �پ������ front�� �����Ǵٰ� NULL�� �Ǿ��ٴ� ���� �� �̻� �����Ͱ� �������� �ʴ´ٴ� ���� �ǹ�
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enLQueue(LQueueType* LQ, element item) {	// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;			// data �� �ֱ�
	newNode->link = NULL;			// ����Ʈ ���� NULL�� �ֱ�
	if (LQ->front == NULL) {		// ����Q���� Ȯ��
		LQ->front = newNode;		// �����̶�� front, rear �� ������ ������ newNode �ּ� �ֱ�
		LQ->rear = newNode;		
	}
	else {							// �ƴ϶��
		LQ->rear->link = newNode;	// ����Ʈ �������� ���� NULL���� newNode�� �ּҷ� �ٲٱ�;
		LQ->rear = newNode;			// rear�� ���� ���� ���� ������ �ٲٸ鼭 ����Ʈ�� ���� �߰��ϱ�
	}
}

element deLQueue(LQueueType* LQ) {			// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
	QNode* old = LQ->front;					// free�� �޸� �Ҵ� ������ �ϱ� ���� ���� old ����
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = old->data;					// ������ ����� �ִ� ������ ����
		LQ->front = LQ->front->link;		// front�� ����Ʈ �������� �ѱ��
		if (LQ->front == NULL)				// front�� NULL�̶�� ����Ʈ ���� ������ ���̹Ƿ� ���� ť�� ��
			LQ->rear = NULL;				// �׷��⿡ rear�� NULL�� ����
		free(old);							// �޸� �Ҵ� ����
		return item;						// item ��ȯ
	}
}

element peekLQ(LQueueType* LQ) {		//���� ť���� ���Ҹ� �˻��ϴ� ���� - front�� ���Ҹ� ��ȯ�ϴ� ����
	element item;							
	if (isLQEmpty(LQ)) return;		// �����̶�� �׳� ����
	else {
		item = LQ->front->data;		// front�� ����Ű�� Q����� ������ ��
		return item;		
	}
}

void printLQ(LQueueType* LQ) {			//���� ť���� ���Ҹ� �˻��ϴ� ����
	QNode* temp = LQ->front;			//��ȸ�� temp�� ����
	printf(" Linked Queue : [");		
	while (temp) {						//����Ʈ ó������ ������ ���鼭 �����͸� �����
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}