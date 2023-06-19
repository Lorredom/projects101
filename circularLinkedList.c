// Takes number of nodes to be added
// Values start at value given as number
// And are incremented by 1
// Function creates a circular list and self-destroyes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long int value;
    struct Node *forward;
} node;


node *linkNodes(long int value) {
    node * Node = malloc(sizeof(node));
    if (Node == NULL) {
        printf("Allocation failure\n");
    } else {
        Node->value = value;
        Node->forward = NULL;
        printf("Node %ld has been linked\n", Node->value);
    }
    return Node;
}

node * deleteFirstFromCircle(node *Node) {
    //node * temp;
     if (Node == NULL) {
        printf("Nothing's in the circle\n");
     } else {
        //temp = (Node->forward);
        Node->forward = (Node->forward)->forward;
     }
    return Node->forward;
}


void printCircle(node * Node) {
    if (Node == NULL) printf("No nodes, no circle");
    else {
        //node * firstTemp = Node;
        node * temp = Node;
        printf("Your circle:\n");
        do { 
            printf("%ld at %p to %p\n", temp->value, temp, temp->forward);
            temp=temp->forward;
        } while (temp != Node);
    }
}

//TODO
void destroyCircle(node * Node) {

    if (Node != NULL) {
        node * firstTemp = Node;
        node * temp = NULL;
        while (Node) {
            temp = Node->forward;
            printf("Destroying %ld node at %p to %p\n", Node->value, Node, Node->forward);
            //Node->forward = NULL;
            //Node = NULL;
            if (Node->forward == firstTemp) {
                printf("end of circle\n");
                //Node->forward = NULL;
                free(Node);
                //free(Node->forward);
                break;
            }
            
            //Node = NULL;
            free(Node);
            //free(NULL);
            Node = temp;
        }
        //temp = NULL;
        //firstTemp = NULL;
        //free(temp);
        printf("Your circle has been ereased\n");

    } else {
        printf("Your circle doesn't exist\n");
    } 

}

int main () {
    node * firstNode = NULL;
    node * lastNode = NULL;
    node * temp = NULL;

    long int data;
    printf("Enter starting value: ");
    scanf("%ld", &data);
    for (int i=0; i<data; i++) {
        //printf("i%d: ", i);
        if (firstNode==NULL) {
            firstNode = linkNodes(data);
            lastNode = firstNode;
            firstNode->forward = lastNode;
            lastNode->forward = firstNode;
            temp = firstNode;
        } else {
            lastNode->forward = linkNodes(data+i);
            lastNode = lastNode->forward;
            lastNode->forward = temp;
        }
    }
    printCircle(firstNode);
    firstNode = deleteFirstFromCircle(lastNode);
    //lastNode = deleteFirstFromCircle(lastNode);
    //firstNode = lastNode->forward;
    //printCircle(firstNode);

    destroyCircle(firstNode);
    firstNode = NULL;
    lastNode = NULL;
    printCircle(firstNode);
    return 0;  
}