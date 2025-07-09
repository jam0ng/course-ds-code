#include <stdio.h>
#include <stdlib.h>
#include "queueS.h"

QueueType* createQueue() {		//���� ���� ť�� �����ϴ� ����
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType)); //����ü�� �޸𸮸� �Ҵ��ϰ� �� �ּҰ��� Q�� ����
	Q->front = -1;	//front �ʱ갪 ����
	Q->rear = -1;	//rear �ʱ갪 ����
	return Q;
}

int isQueueEmpty(QueueType* Q) {	//���� ť�� ���� �������� �˻��ϴ� ����
	if (Q->front == Q->rear) {		//Q�� front �� rear�� ������ ����
		printf(" Queue is empty! \n\t ");
		return 1;		//true
	}
	else return 0;	//false
}
int isQueueFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf(" Queue is full! \n\t "); // FULL�� �Ǵ� ������ ã�� ����
		return 1;
	}
	else return 0;
}
void enQueue(QueueType* Q, element item) {	//���� ť�� rear�� ���Ҹ� �����ϴ� ����
	if (isQueueFull(Q)) return; //��ȭ �����̸�, ���� ���� �ߴ�
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}
element deQueue(QueueType* Q) {		//���� ť�� front���� ���Ҹ� �����ϴ� ����
	if (isQueueEmpty(Q)) return;	//���� �����̸�, ���� ���� �ߴ�
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}
element peekQ(QueueType* Q) {	//���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
	if (isQueueEmpty(Q)) return; //���� �����̸� ���� �ߴ�
	else return Q->queue[Q->front + 1];
}
void printQ(QueueType * Q) {	//���� ť�� ���Ҹ� ����ϴ� ����
		int i;
		printf(" Queue : [");
		for (i = Q->front + 1; i <= Q->rear; i++)
			printf("%3c", Q->queue[i]);
		printf(" ]");
}