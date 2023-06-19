/*#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int array[3];
	int rear;
	int front;
} queue;

int enqueue (int Q[], int value, int rear) {
	if (rear == 3) {
		printf("The queue is full\n");
	} else {
		Q[rear] = value;
		printf("Success!\n");
		rear++;
	}
	return rear;
}

int dequeue (int Q[], int rear, int front) {
	if (front == rear) {
		printf("The queue is empty\n");
	} else {
		Q[front] = NULL;
		printf("Deleted\n");
		front++;
	}
	return front;
}

int main() {
	queue *newQ = malloc(sizeof(queue));
	newQ->front = 0;
	newQ->rear = 0;
	newQ->rear = enqueue(newQ->array, 10, newQ->rear);
	newQ->rear = enqueue(newQ->array, 20, newQ->rear);
	newQ->rear = enqueue(newQ->array, 30, newQ->rear);
	newQ->rear = enqueue(newQ->array, 40, newQ->rear);
	printf("newQ->rear is %d and newQ->front is %d\n", newQ->rear, newQ->front);
	
	newQ->front = dequeue(newQ->array, newQ->rear, newQ->front);
	newQ->front = dequeue(newQ->array, newQ->rear, newQ->front);
	newQ->front = dequeue(newQ->array, newQ->rear, newQ->front);
	newQ->front = dequeue(newQ->array, newQ->rear, newQ->front);
	return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int value;
	struct Stack *front; // top of stack
	struct Stack *rear; // bottom of stack
} stack;


stack * push(int value) {
	stack *Stack = malloc(sizeof(stack));

	if (Stack != NULL) {
		printf("Adding to stack...\n");
		Stack->value = value;
		Stack->front = NULL;
		Stack->rear = NULL;
		printf("pushed: %d %d %d\n", Stack->value, Stack->rear, Stack->front);
	} else {
		printf("Allocation failure");
	}
	return Stack;
}

stack * pull(stack *Stack) {
	//stack *temp = NULL;
	if (Stack != NULL) {
		printf("Removing from stack...\n");
		//temp = Stack->rear;
		(Stack->rear)->front = NULL;
		Stack = Stack->rear;
		//printf("pulled: %d %d %d\n", Stack->value, Stack->rear, Stack->front);
	} else { 
		printf("Stack is empty\n");
	}
	return Stack;
}

int main(void) {
	stack *newStack = NULL;
	stack *NextOnStack = NULL;
	stack *temp = NULL;
	
	while (1) {
		if (newStack == NULL) {
			newStack = push(16);
			newStack->rear = newStack;
			printf("new: %d %d %d\n", newStack->value, newStack->rear, newStack->front);
			NextOnStack = newStack;
			printf("next first: %d %d %d\n", NextOnStack->value, NextOnStack->rear, NextOnStack->front);
		} else {
			NextOnStack->front = push(20);
			printf("next before temp: %d %d %d\n", NextOnStack->value, NextOnStack->rear, NextOnStack->front);
			temp = NextOnStack->front;
			NextOnStack = temp;
			printf("next after temp: %d %d %d\n", NextOnStack->value, NextOnStack->rear, NextOnStack->front);
			NextOnStack->rear = temp;
			break;
		}
	}
	printf("new: %d %d %d\n", newStack->value, newStack->rear, newStack->front);
	printf("temp: %d %d %d\n", temp->value, temp->rear, temp->front);
	printf("next last: %d %d %d\n", NextOnStack->value, NextOnStack->rear, NextOnStack->front);
	NextOnStack = pull(NextOnStack);
	printf("after pull: %d %d %d\n", NextOnStack->value, NextOnStack->rear, NextOnStack->front);
	/*printf("%d %d\n", newStack->rear, newStack->front);
	newStack->rear = push(newStack->array, 18, newStack->rear);
	printf("%d %d\n", newStack->rear, newStack->front);
	newStack->rear = push(newStack->array, 1, newStack->rear);
	printf("%d %d\n", newStack->rear, newStack->front);
	newStack->rear = push(newStack->array, 3, newStack->rear);
	printf("%d %d\n", newStack->rear, newStack->front);
	newStack->rear = push(newStack->array, 19, newStack->rear);
	printf("%d %d\n", newStack->rear, newStack->front);*/
	
	return 0;
}
