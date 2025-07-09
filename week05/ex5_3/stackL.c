#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"

//������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty(void) {
	if (top == NULL) return 1;
	else return 0;
}

//������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;	//���� ��带 top�� ���� ���� (�������̸�(temp) -> ��������̸� = ��)
	top = temp;			//top ��ġ�� ���� ���� �̵�
}

//������ top���� ���Ҹ� �����ϴ� ����
element pop(void) {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {	//������ ���� ����Ʈ�� ���
		printf("\n\n Stack is Empty! \n");
		return 0;
	}
	else {					//������ ���� ����Ʈ�� �ƴ� ���

		item = temp->data;
		top = temp->link;	//top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			//������ ����� �޸� ��ȯ
		return item;		//������ ���� ��ȯ
	}
}

//������ top ���Ҹ� �˻��ϴ� ����

element peek(void) {
	if (isStackEmpty()) {	//������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty! \n");
		return 0;
	}
	else {					//������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);	//���� top�� ���� ��ȯ
	}
}

//������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack(void) {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}