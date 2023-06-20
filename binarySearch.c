#include <stdio.h>
 
int main(void) {
	int array[] = {0, 4, 9, 12, 16, 20, 21};
	int x = 0;
	int savedLen = (sizeof(array))/(sizeof(array[0]));
	int currentPos = savedLen;
	printf("currentPos: %d\n", currentPos);
	int value;
    printf("Enter value: ");
	scanf("%d", &value);
	printf("value: %d\n", value); 
 
	while (x == 0) {
		if (value < array[(currentPos/2)]) {
			printf("%d is less then %d\n", value, array[currentPos/2]);
			currentPos = currentPos/2;
			printf("IF new currentPos is %d\n", currentPos);
		} else if (value == array[currentPos/2]) {
			printf("Your value has been found at %d\n", (currentPos/2));
			x = 1;
		} else if (value > array[(currentPos/2)]){
			printf("%d is more then %d\n", value, array[currentPos/2]);
			currentPos = currentPos/2 + savedLen;
			printf("ELSE new currentPos is %d\n", currentPos);
		}
	}
	return 0;
}