#include <stdio.h> 
typedef struct graphNode {
    int *self;
    struct graphNode *nodePrev;
    struct graphNode *nodeNext;
} node;


int main() {
    int h, i, j, k, m, n, numOfNodes;

    scanf("%d", &numOfNodes);
    int listOfNodeInteractions[numOfNodes*numOfNodes];
    node listOfNodes[numOfNodes]; 
    node *temp;
    node *firstNode;

    for (i=0; i<numOfNodes; i++) { 
        for(j=0; j<numOfNodes; j++) {
            scanf("%d", &(listOfNodeInteractions[(i*numOfNodes)+j]));
        }
    }

    for (i=0; i<numOfNodes; i++) { 
        for(j=0; j<numOfNodes; j++) {
            printf("%d", (listOfNodeInteractions[(i*numOfNodes)+j]));
        }
    }
    printf("\n");
    for (h=0; h<numOfNodes; h++) {
        printf("%d\n", h);
        listOfNodes[h].self = &h;
        listOfNodes[h].nodePrev = NULL;
        listOfNodes[h].nodeNext = NULL;
        //node * listOfNodes[h].nodeNext;
        //printf("%p ", (listOfNodes[h])->nodePrev);
        //printf("%p\n", (listOfNodes[h])->nodeNext);
        
    }


    for (k=0; k<numOfNodes*numOfNodes; k=k+numOfNodes) {
        for (m=0; m<numOfNodes; m++)  { 
            printf("\nk%d, m%d\n", k, m);
            if (listOfNodes[k/numOfNodes].nodePrev == NULL) {
                printf("immm\n");
                printf("k+m=%d\n", k+m);
                if (listOfNodeInteractions[(k+m)] == 1) {
                    //printf("k*numOfNodes+m=%d\n", k*numOfNodes+m);
                    printf("if k%d, m%d\n", k, m);
                    listOfNodes[k/numOfNodes].nodePrev = &listOfNodes[m];
                }
            } else if (listOfNodes[k/numOfNodes].nodeNext == NULL) {
                printf("emmm\n");
                printf("k+m=%d\n", k+m);
                if (listOfNodeInteractions[(k+m)] == 1) {
                    
                    printf("else if k%d, m%d\n", k, m);
                    listOfNodes[k/numOfNodes].nodeNext = &listOfNodes[m];
                }
            }
        }
    }

    firstNode = &listOfNodes[0];
    temp = firstNode;
    int count = 0;
    for  (n=0; n<numOfNodes; n++) {
        printf("count was %d| n%d: %p\n", count, n, &temp);
        count++;
        if (temp->nodeNext) {
            if (temp != firstNode->nodePrev) {
                printf("im here\n");
                temp = temp->nodeNext;
                printf("%p %p\n", temp, (temp->nodeNext));
            } else {
                break;
            }
        } else {
            break;
        }
    }  

    if (count == numOfNodes) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
