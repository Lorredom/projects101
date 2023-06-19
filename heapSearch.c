#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    bool root;
    int unsortedMaxVal;
    struct Node *parent;
    struct Node *child_right;
    struct Node *child_left;
} node;

int searchForMax(node unsortedArray[], int length, int* maxIndex, int * loopCounter) {
    int maxValue = unsortedArray[0].value;
    *maxIndex = 0;
    *loopCounter = 0;
    for(int i=0; i<length; i++) {
        if (unsortedArray[i].unsortedMaxVal != 1) { 
            if (unsortedArray[i].value > maxValue) {
                maxValue = unsortedArray[i].value;
                printf("%d.%d|| ", i, maxValue);
                *maxIndex = i;
            }
        } else {
            (*loopCounter)++;
            printf("loopCounter is %d\n", *loopCounter);
        }
    }
    unsortedArray[*maxIndex].unsortedMaxVal = 1;
    printf("maxIndex:%d\n", *maxIndex);
    return (unsortedArray[*maxIndex].unsortedMaxVal);

}

void printYourHeap(node nodeList[], int savedLen) {
    int p, childCount = (savedLen+1)/2; // factor for excluding childless nodes in child-printing
    for (p=0; p<savedLen; p++) { // printing loop
        printf("%d, %d\n", p, nodeList[p].value);
        // if (p<(savedLen-childCount)) {
        //     printf("p%d children of %d: %d %d\n", p, p, ((nodeList[p].child_left)->value), ((nodeList[p].child_right)->value));
        // }
    }

}

int main () {
    int array[]={89, 15, 16, 0, 22, 29, 11, 4, 20, 29, 99, 100, 200, -20}; // user input placeholder; TODO
    int savedLen = sizeof(array)/sizeof(array[0]);
    int len = savedLen;
    node nodeList[len];
    int odd, even, childCount, i, p, s, maxIndex, loopCounter;

    // appending loop
    for (i=0; i<len; i++) {  
        nodeList[i].root = false;
        if (i == 0) {
            nodeList[i].root = true;
            nodeList[i].parent = NULL;
        } else if (i%2 == 0) {
            even = ((i/2)+1);
            printf("even%d| ", even);
            if (nodeList[i-even].child_right==NULL) {
                printf("%d) even is: %d and i-even is:%d \n", i, even, i-even);
                nodeList[i-even].child_right = &(nodeList[i]); 
                nodeList[i].parent = &(nodeList[i-even]);
            } 

        } else if (i%2 != 0) {
            odd = ((i+1)/2);
            printf("odd%d| ", odd);
            if (nodeList[i-odd].child_left==NULL) {
                printf("%d) odd is: %d and i-odd is:%d \n", i, odd, i-odd);
                nodeList[i-odd].child_left = &(nodeList[i]);
                nodeList[i].parent = &(nodeList[i-odd]);
            }          
        }
        nodeList[i].value = array[i];
        nodeList[i].child_left = NULL;
        nodeList[i].child_right = NULL;
        nodeList[i].unsortedMaxVal = 0;
        printf("%d. new is: %d\n", i, nodeList[i].value);
    }


    childCount = (savedLen)/2; // factor for excluding childless nodes in child-printing
    // children checking loop
    for (p=0; p<savedLen; p++) { 
        printf("%d, %d\n", p, nodeList[p].value);
        if ((nodeList[p].child_left)!=NULL) {
            printf("p%d child left of %d: %d\n", p, p, ((nodeList[p].child_left)->value));
        }
        if ((nodeList[p].child_right)!=NULL) {
            printf("p%d child right of %d: %d\n", p, p, ((nodeList[p].child_right)->value));
        }
    }
    printYourHeap (nodeList, savedLen);

    int tempValue, tempMax, temp;
    // IF reheaps, ELSE sorts
    while (loopCounter != savedLen-1) { 
        temp = searchForMax(nodeList, savedLen, &maxIndex, &loopCounter);
        nodeList[maxIndex].unsortedMaxVal = temp;
        if (maxIndex != 0) {
            tempValue=nodeList[0].value;
            tempMax=nodeList[0].unsortedMaxVal;

            nodeList[0].value = nodeList[maxIndex].value;
            nodeList[0].unsortedMaxVal = nodeList[maxIndex].unsortedMaxVal;

            nodeList[maxIndex].value = tempValue;
            nodeList[maxIndex].unsortedMaxVal = tempMax;
        } else {
            tempValue=nodeList[0].value;
            tempMax=nodeList[0].unsortedMaxVal;

            nodeList[0].value = nodeList[len-1].value;
            nodeList[0].unsortedMaxVal = nodeList[len-1].unsortedMaxVal;

            nodeList[len-1].value = tempValue;
            nodeList[len-1].unsortedMaxVal = tempMax;
            len = len-1;
            printf("new len is %d", len);
        }
        printf("-----------\n");
        printYourHeap (nodeList, savedLen);

    }
    // printYourHeap (nodeList, savedLen);
}