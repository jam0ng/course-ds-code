#pragma once
#define CQ_SIZE 4
typedef char element;		// ť ����(element)�� �ڷ����� char�� ����

typedef struct {			// ����ü ���� - front �� rear�� ������ �ֱ� ���� ����ü�� ������ �� �ڷᱸ���� ������ Ÿ���� ����ü���� �� �ȿ� �����ʹ� �迭��
	element queue[CQ_SIZE];	// 1���� �迭 ť ����
	int front, rear;
} QueueType;

QueueType* createCQueue();
int isCQueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);