#include <stdio.h> 
typedef struct Item {
    int value;
    int weight;
    int fitForTransport;
} Item;


void printSum(int numOfItems, Item * items) {
    int p, sum=0;
    for(p=0; p<numOfItems; p++) {
        if (items[p].fitForTransport == 1) { // przedmioty przyjęte do transportu
            sum= sum + items[p].value;
        }
    }
    printf("%d\n", sum);
}


int findHighest(int numOfItems, Item * items, int maxWeightCapacity, int * capacityLeft) {
    int indexOfHighest;
    int shouldProgramContinue = 1;
    int shouldLoopContinue = 1;

    while (shouldLoopContinue==1) {
    	indexOfHighest = -1;
	    for(int p=0; p<numOfItems; p++) {
	    	if (items[p].fitForTransport == 2) {
	    		if (indexOfHighest == -1) {
                    indexOfHighest = p;
	    		} else {
	    			if (items[indexOfHighest].value < items[p].value) {
	                	indexOfHighest = p;
	            	}
	        	}
	    	}
	    }

        if (indexOfHighest == -1) {
            shouldProgramContinue = 0;
            break;
        }
	    if (items[indexOfHighest].weight <= *capacityLeft) {
        	*capacityLeft = *capacityLeft - items[indexOfHighest].weight;
        	items[indexOfHighest].fitForTransport = 1; //przedmioty przyjęte do transportu
        	shouldLoopContinue=0;
    	} else {
        	items[indexOfHighest].fitForTransport = 0; // przedmioty odrzucone w drugim podejściu
    	}
    }
    return shouldProgramContinue;
}


int main() {
    int i, j, k, m, numOfItems;

    int maxWeightCapacity, capacityLeft;
    int shouldProgramContinue = 1;

    scanf("%d", &numOfItems);
    Item listOfItems[numOfItems];
    for(i=0; i<numOfItems; i++) {
        scanf("%d", &(listOfItems[i].value));  
    }
    for(j=0; j<numOfItems; j++) {
        scanf("%d", &(listOfItems[j].weight));
    }
    scanf("%d", &maxWeightCapacity);
    capacityLeft=maxWeightCapacity;

    for(k=0; k<numOfItems; k++) {
        if ((listOfItems[k].weight) > maxWeightCapacity) {
            listOfItems[k].fitForTransport = 0; // przedmioty odrzucone ze względu na wagę
        } else {
        	listOfItems[k].fitForTransport = 2; // przedmioty, których nie można odrzucić z góry
        }
    }

    while (shouldProgramContinue == 1) {
        shouldProgramContinue = findHighest(numOfItems, listOfItems, maxWeightCapacity, &capacityLeft);
        for (m=0; m<numOfItems; m++) {
            if (listOfItems[m].fitForTransport == 2) {
                if ((listOfItems[m].weight) < capacityLeft) {
                    shouldProgramContinue=1;
                    break;
                }
            } else if (m==numOfItems) {
                shouldProgramContinue=0;
            }
        }
    }
    printSum(numOfItems, listOfItems);

    return 0;
}

/*
In
5
588 40 307 367 206
211 30 974 943 622
1766
1
596
997
550

Out
995
0*/