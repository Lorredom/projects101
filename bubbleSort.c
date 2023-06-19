#include <stdio.h>
 
int main() {
    int temp, i, count;
    int redundantLoop;
    int list[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    count = (sizeof(list))/(sizeof(list[0]));
 
    while (1) {
        redundantLoop = 0;
        for (i=0; i<count-1; i++) {
            if (list[(i+1)] < list[i]) {
                temp = list[i];
                list[i] = list[(i+1)];
                list[(i+1)] = temp;
                printf("Replacing...\n");
                //printf("Replacing %d with %d\n", list[i], list[i+1]);
            } else {
                redundantLoop++;
                printf("Redundant loop is %d, continuing\n", redundantLoop);
            }
        }
        if (redundantLoop>count-2) {
            printf("Redundant loop is %d, breaking\n", redundantLoop);
            break;
        }
    }
    printf("ended, printing\n");
    for (i=0; i<count; i++) {
        printf("%d. %d\n", i+1, list[i]);
    }
    return 0;
}
