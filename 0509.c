#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 10             //��  ջ�Ĵ�С
#define FALSE 0
#define TRUE 1

typedef int StackElementType;      //�궨��
typedef int QueueElementType;

typedef struct node      //����һ���ṹ����
{
	StackElementType data;  //����ջ��������
	struct node* next;      //����ջ��ָ����
}LinkStackNode, *LinkStack;

typedef struct
{
	StackElementType elem[Stack_Size];  //����ջ�Ĵ�С
	int top;                  //����һ��ջ��
}SeqStack;

typedef struct Node            //����һ���ṹ����
{
	QueueElementType data;     //������е�������
	struct Node* next;         //������е�ָ����
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;     //����һ������
	LinkQueueNode *rear;       //����һ����β
}LinkQueue;

void InitLink(LinkStack top)//��ʼ����ջ
{
	top->data = 0;
	top->next = NULL;
}

void PushLink(LinkStack top, StackElementType x)  //��ջ��ջ
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
}

void PopLink(LinkStack top, StackElementType *x)   //��ջ��ջ
{
	LinkStackNode* temp;
	temp = top->next;
	top->next = temp->next;
	*x = temp->data;
	free(temp);
}
void DisplayLink(LinkStack top)        //��ӡ��ջ
{
	LinkStackNode *temp;
	temp = top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("%d", temp->data);
		printf("->");
	}
	printf("NULL\n");
}

int InitSeq(SeqStack* S)          //��ʼ��˳��ջ
{
	S->top = -1;
	return TRUE;
}

void PushSeq(SeqStack* S, StackElementType x)     //˳��ջ��ջ
{
	if (S->top == Stack_Size - 1)
	{
		printf("ջ������\n");
		return;
	}
	S->top++;
	S->elem[S->top] = x;

}

int PopSeq(SeqStack* S, StackElementType* x)         //˳��ջ��ջ
{
	if (S->top == -1)
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return(TRUE);
	}
}
int GetTop(SeqStack* S, StackElementType* x)   //���˳��ջ��ջ��Ԫ��
{
	if (S->top == -1)
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];
		printf("��ջ��ջ��Ԫ��Ϊ %d\n", *x);
		return(TRUE);
	}
}

int InitQueue(LinkQueue *Q)               //����������
{
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return (TRUE);
	}
	else
		return (FALSE);
}

int	EnterQueue(LinkQueue *Q, QueueElementType x)    //���������
{
	LinkQueueNode *NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return (TRUE);
	}
	else
		return (FALSE);
}

int DeleteQueue(LinkQueue *Q, QueueElementType *x)      //�����г���
{
	LinkQueueNode *p;
	if (Q->front == Q->rear)
	{
		return (FALSE);
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	*x = p->data;
	free(p);
	return (TRUE);
}

typedef struct Queue         
{
	QueueElementType data[Stack_Size];//����˳����еĴ�С
	int size;
}QueueSq;
void Init(QueueSq *S)           //��ʼ��˳�����
{
	S->size = -1;
}
void PushQueue(QueueSq* S, QueueElementType d)    //˳��������
{
	if ((S->size + 1) >= Stack_Size)
		return;
	S->data[S->size + 1] = d;
	S->size++;
}
void PopQueue(QueueSq*S, QueueElementType *d)    //˳����г���
{
	if (S->size == -1)
		return;
	*d = S->data[0];
	for (int i = 0; i < S->size; ++i)
	{
		S->data[i] = S->data[i + 1];
	}
	S->size--;
}

void menu()
{
	printf("1.��ʽ�洢��ջ����ջ \n");
	printf("2.˳��洢��ջ����ջ \n");
	printf("3.��ʽ�洢��ӡ����� \n");
	printf("4.˳��洢��ӡ����� \n");
}
void test1()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("������Ҫ��ջԪ�ظ�����");
	scanf("%d", &i);
	LinkStack S = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	InitLink(S);
	for (; i > 0; i--)
	{
		printf("������Ҫ��ջԪ�أ�");
		scanf("%d", &d);
		PushLink(S, d);
		DisplayLink(S);
	}
	printf("������Ҫ��ջԪ�ظ�����");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopLink(S, &b);
		DisplayLink(S);
	}
}
void test2()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("������Ҫ��ջԪ�ظ�����");
	scanf("%d", &i);
	SeqStack S;
	InitSeq(&S);
	for (; i > 0; i--)
	{
		printf("\n������Ҫ��ջԪ�أ�\n");
		scanf("%d", &d);
		PushSeq(&S, d);
	}
	printf("\n������Ҫ��ջԪ�ظ�����");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopSeq(&S, &b);
		GetTop(&S, &b);
	}
}
void test3()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b;
	printf("������Ҫ���Ԫ�ظ�����");
	scanf("%d", &i);
	LinkQueue S;
	InitQueue(&S);
	for (; i > 0; i--)
	{
		printf("\n������Ҫ���Ԫ�أ�\n");
		scanf("%d", &d);
		EnterQueue(&S, d);
	}
	printf("\n������Ҫ����Ԫ�ظ�����");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		DeleteQueue(&S, &b);
		printf("%d\n", b);
	}
}
void test4()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b;
	printf("������Ҫ���Ԫ�ظ�����");
	scanf("%d", &i);
	QueueSq S;
	Init(&S);
	for (; i > 0; i--)
	{
		printf("\n������Ҫ���Ԫ�أ�\n");
		scanf("%d", &d);
		PushQueue(&S, d);
	}
	printf("\n������Ҫ����Ԫ�ظ�����");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopQueue(&S, &b);
		printf("%d\n", b);
	}
}

void test()
{
	int input = 1;
	do{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (1);
}
int main()
{
	test();
	system("pause");
	return 0;
}
