#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Stack
{
	Node* stacktop;
	int size;
}Stack;

Stack* CreatNewStack()
{
	Stack* NewStack = (Stack*)malloc(sizeof(Stack));
	NewStack->size = 0;
	NewStack->stacktop = NULL;
	return NewStack;
}

Node* CreatNewNode()
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	return NewNode;
}

void PushStack(Stack* stack,int x)
{
	Node* NewNode = CreatNewNode();
	NewNode->data = x;
	NewNode->next = stack->stacktop;
	stack->stacktop = NewNode;
	stack->size++;
	printf("压栈\n");
}

void PopStack(Stack* stack)
{
	if (stack->stacktop)
	{
		stack->stacktop = stack->stacktop->next;
		stack->size--;
		printf("出栈\n");
	}
	else
	{
		printf("栈中无元素\n");
		return;
	}
}


int main()
{
	Stack* stack = CreatNewStack();
	PushStack(stack, 3);
	PopStack(stack);
	PopStack(stack);

}