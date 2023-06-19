#include <stdio.h>

int main(void) {
	int array[] = {9,0,2,-2, 2,4,-9};
	int len = (sizeof(array))/(sizeof(array[0]));
	int sortedArray[len];
	int index[len];
	int a, i, j, k, m, smallest;
	
    for (a=0; a<len; a++) {
        index[a] = -1;
    }

	for(j=0; j<len; j++) {
        //printf("j is: %d\n",j);
        smallest = array[0];
		for(i=0; i<len; i++) {
            //printf("  i is: %d\n",i);
            int isInIndex = 0;
            for (k=0; k<len; k++) {
                if (index[k] == i) {
                    isInIndex = 1;
                    break;
                } 
            }
            if (isInIndex != 1) {
                if (array[i]<=smallest) {
                    //printf("    array[i] is: %d and array[i+1] is: %d\n",array[i], array[i+1]);
                    smallest = array[i];
                    //printf("    smallest is: %d\n",smallest);
                    index[j] = i;
                    //printf("    index[%d] is: %d\n",j, i);
                } else {
                    //printf("array[%d] isn't less than %d  \n", i, smallest);
                }
            }
        }
    }
	
	for (m=0; m<len; m++){
        //printf("m is: %d\n",m);
		sortedArray[m] = array[index[m]];
		printf("%d\n", sortedArray[m]);
        //printf("%d\n", index[m]);
	}
	return 0;
}
