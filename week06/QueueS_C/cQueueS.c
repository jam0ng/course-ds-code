#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue() {		//���� ���� ť�� �����ϴ� ���� ������ �޸� �⺻���� 0�̴�.
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType)); //����ü�� �޸𸮸� �Ҵ��ϰ� �� �ּҰ��� Q�� ����
	cQ->front = 0;	//front �ʱ갪 ����
	cQ->rear = 0;	//rear �ʱ갪 ����
	return cQ;
}

int isCQueueEmpty(QueueType* cQ) {	//���� ť�� ���� �������� �˻��ϴ� ����
	if (cQ->front == cQ->rear) {		//Q�� front �� rear�� ������ ����
		printf(" Circular Queue is empty! \n\t ");
		return 1;		//true
	}
	else return 0;	//false
}
int isCQueueFull(QueueType* cQ) {		//���� ť�� ���� �������� �˻��ϴ� ����
	if (((cQ->rear + 1)% CQ_SIZE) == cQ->front) {		//���� ť���� ���ϴ� �� (�߿�)
		printf(" Circular Queue is full! \n\t "); 
		return 1;
	}
	else return 0;
}
void enCQueue(QueueType* cQ, element item) {	//���� ť�� rear�� ���Ҹ� �����ϴ� ����
	if (isCQueueFull(cQ)) return; //��ȭ �����̸�, ���� ���� �ߴ�
	else {
		cQ->rear = (cQ->rear + 1) % CQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}
element deCQueue(QueueType* cQ) {		//���� ť�� front���� ���Ҹ� �����ϴ� ����
	if (isCQueueEmpty(cQ)) return;	//���� �����̸�, ���� ���� �ߴ�
	else {
		cQ->front = (cQ->front + 1) % CQ_SIZE;
		return cQ->queue[cQ->front];
	}
}
element peekCQ(QueueType* cQ) {	//���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
	if (isCQueueEmpty(cQ)) return; //���� �����̸� ���� �ߴ�
	else return cQ->queue[(cQ->front + 1) % CQ_SIZE];
}
void printCQ(QueueType* cQ) {	//���� ť�� ���Ҹ� ����ϴ� ����
	int i, first, last;
	first = (cQ->front + 1) % CQ_SIZE;
	last = (cQ->rear + 1) % CQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % CQ_SIZE;
	}
	printf(" ] ");
}