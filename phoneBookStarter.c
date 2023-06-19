#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	long int value;
	struct Queue *after; //came after, aka joining the queue
	struct Queue *before; //came before, aka already in queue
} queue;

queue * addToQueue(long int value) {
	queue * Queue = malloc(sizeof(queue));
	if (Queue == NULL) {
		printf("Allocation failure\n");
	} else {
		Queue->value = value;
		Queue->after = NULL;
	}
	return Queue;
}

queue * removeFromQueue(queue * Queue) {
    if (Queue == NULL) {
		printf("Nothing to remove\n");
	} else {
	    printf("inside else\n");

        if (Queue->before != NULL) {
            Queue = Queue->before;
            printf("Inside else's if");
        } else {
            Queue = Queue->after;
            Queue->before = NULL;
            printf("Inside else's else");
        }
	}
    return Queue;
}

void printQueue(queue * Queue) {
	queue * temp = Queue;
	if (temp == NULL) {
		printf("Your queue is empty\n");
	} else {
	    printf("Printing your queue:\n");
	    while (temp) {
	        printf("%ld ", temp->value);
	        temp = temp->after;
	    }
	}
}

queue cleanQueue (queue * Queue) {
    queue * temp = NULL;
    while (Queue) {
        temp = Queue->after;
        free(Queue);
        Queue = temp;
    }
}


int main(void) {
    printf("%ld\n", sizeof(long int));
	queue * firstInQueue = NULL;
	queue * nextInQueue = NULL;
	queue * temp = NULL;
	long int inputVal;
	int elo;
	char input[15];
	
	while (1) {
	    //input[0] = '\0';
	    printf("Enter number to be added, or command 'print', 'end' or 'remove'\n");
		fgets(input, 11, stdin);
	    printf("Input is %s", input);
		elo = sscanf(input, "%ld", &inputVal);
		printf("Elo elo %d\n", elo);
	    if (elo != EOF) {
		    if (firstInQueue == NULL) {
    			firstInQueue = addToQueue(inputVal);
    			printf("Value added is %ld to first\n", firstInQueue->value); 
    			if (firstInQueue != NULL) {
    				firstInQueue->before = NULL;
    				nextInQueue = firstInQueue;
    				printf("Next is %ld and first is %ld\n", nextInQueue->value, firstInQueue->value);
    				//printf("first->before: %p\n", firstInQueue->before);
    			} else {
    				printf("Error while adding to queue\n");
    			}
    		} else {
    			temp = nextInQueue; 
    			nextInQueue->after = addToQueue(inputVal);
    			nextInQueue = nextInQueue->after;
    			nextInQueue->before = temp;
    			printf("Value added is %ld to next\n", nextInQueue->value);
    			printf("Added successfully\n");
    		}
	    } else {
		    if (strncmp(input, "end", 3) == 0) {
		        printf("Program ended\n");
		        break;
		    } else if (strncmp(input, "print", 5) == 0) {
		        printf("Print function has been called\n");
		        printQueue(firstInQueue);
		        printf("first->before: %p\n", firstInQueue->before);
		    } else if (strncmp(input, "remove", 6) == 0) {
		        printf("Remove function has been called\n");
		        firstInQueue = removeFromQueue(firstInQueue);
		        printf("Print function has been called\n");
		        printQueue(firstInQueue);
		    }
		}
	}
	printQueue(firstInQueue);
	cleanQueue(firstInQueue);
	printQueue(firstInQueue);
	
	return 0;
}
