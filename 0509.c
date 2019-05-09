#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Stack_Size 10             //宏  栈的大小
#define FALSE 0
#define TRUE 1

typedef int StackElementType;      //宏定义
typedef int QueueElementType;

typedef struct node      //定义一个结构体结点
{
	StackElementType data;  //定义栈的数据域
	struct node* next;      //定义栈的指针域
}LinkStackNode, *LinkStack;

typedef struct
{
	StackElementType elem[Stack_Size];  //定义栈的大小
	int top;                  //定义一个栈顶
}SeqStack;

typedef struct Node            //定义一个结构体结点
{
	QueueElementType data;     //定义队列的数据域
	struct Node* next;         //定义队列的指针域
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;     //定义一个队首
	LinkQueueNode *rear;       //定义一个队尾
}LinkQueue;

void InitLink(LinkStack top)//初始化链栈
{
	top->data = 0;
	top->next = NULL;
}

void PushLink(LinkStack top, StackElementType x)  //链栈入栈
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
}

void PopLink(LinkStack top, StackElementType *x)   //链栈出栈
{
	LinkStackNode* temp;
	temp = top->next;
	top->next = temp->next;
	*x = temp->data;
	free(temp);
}
void DisplayLink(LinkStack top)        //打印链栈
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

int InitSeq(SeqStack* S)          //初始化顺序栈
{
	S->top = -1;
	return TRUE;
}

void PushSeq(SeqStack* S, StackElementType x)     //顺序栈入栈
{
	if (S->top == Stack_Size - 1)
	{
		printf("栈已满！\n");
		return;
	}
	S->top++;
	S->elem[S->top] = x;

}

int PopSeq(SeqStack* S, StackElementType* x)         //顺序栈出栈
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
int GetTop(SeqStack* S, StackElementType* x)   //输出顺序栈的栈顶元素
{
	if (S->top == -1)
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];
		printf("出栈后栈顶元数为 %d\n", *x);
		return(TRUE);
	}
}

int InitQueue(LinkQueue *Q)               //定义链队列
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

int	EnterQueue(LinkQueue *Q, QueueElementType x)    //链队列入队
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

int DeleteQueue(LinkQueue *Q, QueueElementType *x)      //链队列出队
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
	QueueElementType data[Stack_Size];//定义顺序队列的大小
	int size;
}QueueSq;
void Init(QueueSq *S)           //初始化顺序队列
{
	S->size = -1;
}
void PushQueue(QueueSq* S, QueueElementType d)    //顺序队列入队
{
	if ((S->size + 1) >= Stack_Size)
		return;
	S->data[S->size + 1] = d;
	S->size++;
}
void PopQueue(QueueSq*S, QueueElementType *d)    //顺序队列出队
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
	printf("1.链式存储入栈、出栈 \n");
	printf("2.顺序存储入栈、出栈 \n");
	printf("3.链式存储入队、出队 \n");
	printf("4.顺序存储入队、出队 \n");
}
void test1()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("请输入要入栈元素个数：");
	scanf("%d", &i);
	LinkStack S = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	InitLink(S);
	for (; i > 0; i--)
	{
		printf("请输入要入栈元素：");
		scanf("%d", &d);
		PushLink(S, d);
		DisplayLink(S);
	}
	printf("请输入要出栈元素个数：");
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
	printf("请输入要入栈元素个数：");
	scanf("%d", &i);
	SeqStack S;
	InitSeq(&S);
	for (; i > 0; i--)
	{
		printf("\n请输入要入栈元素：\n");
		scanf("%d", &d);
		PushSeq(&S, d);
	}
	printf("\n请输入要出栈元素个数：");
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
	printf("请输入要入队元素个数：");
	scanf("%d", &i);
	LinkQueue S;
	InitQueue(&S);
	for (; i > 0; i--)
	{
		printf("\n请输入要入队元素：\n");
		scanf("%d", &d);
		EnterQueue(&S, d);
	}
	printf("\n请输入要出队元素个数：");
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
	printf("请输入要入队元素个数：");
	scanf("%d", &i);
	QueueSq S;
	Init(&S);
	for (; i > 0; i--)
	{
		printf("\n请输入要入队元素：\n");
		scanf("%d", &d);
		PushQueue(&S, d);
	}
	printf("\n请输入要出队元素个数：");
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
		printf("请选择\n");
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
			printf("选择错误\n");
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
