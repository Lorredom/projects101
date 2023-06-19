#include <stdio.h>
#include <stdlib.h>

int* findSmallest(int *smallest, int *length, int list[]) {
    int j, index, k;
    *smallest = list[0];

    for (j = 0; j<*length; j++) { //searching for the smallest element in list;
        printf("list %d vs smallest %d: \n", list[j], *smallest);
        if (*smallest>list[j]) {
            *smallest=list[j];
            index = j;
            printf("New smallest %d and index is %d\n", *smallest, index);
        } 
    }

    printf("%d: ", *length);
    *length = (*length)-1; 
    int * new_list = malloc(*length * sizeof(int)); // creating Ptr to new list( for smallest elements in newly chipped original list)
    int x = 0;
    for (k=0; k<(*length+1); k++) {
        if (k == index) {
            continue;
        }
        printf("Adding %d\n", list[k]);
    	new_list[x] = list[k];
        x++;

        if (k < index) {
            printf("Adding %d\n", list[k]);
    		new_list[k] = list[k];
    	} else if (k > index) {
            printf("Adding %d\n", list[k]);
    		new_list[k-1] = list[k];
        }
    }
    return new_list;
}

int main() {
	int i, j, k;
    int array[] = {4, 1, 1, 2, 0, 4, 3, 19, 12, -3};
    int *length = (int*)malloc(sizeof(int));
    *length = (sizeof(array))/(sizeof(array[0]));
    int savedLength = *length;
    int *list = malloc((*length) * sizeof(int));

    for (k=0; k<(*length); k++) {
    	list[k] = array[k];
    }

    int sortedList[*length];
    int *smallest = (int*)malloc(sizeof(int));

    
	int * chippedList = list;

    for (j = 0; j<savedLength; j++) { //searching for the smallest element in list;
        printf("Smallest was %d, length was %d\n", *smallest, *length);
        chippedList = findSmallest(smallest, length, chippedList);
        printf("Smallest is %d, length is %d\n++++++++++++\n", *smallest, *length);
        sortedList[j] = *smallest;
    }
         

    for (i = 0; i<savedLength; i++) {
        printf("%dth element is %d\n", i, sortedList[i]);
    }
    return 0;
}