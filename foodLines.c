// Food Lines from dmoj.com
#include <stdio.h>
 
int main(void) {
	int N, M, smallest, savedIndex;
 
	scanf("%d %d", &N, &M);
 
	int searchedArray[N], newArray[N];
 
	for (int k=0;k<N;k++) {
		scanf("%d", &searchedArray[k]);
	}
 
	for (int j=0;j<M;j++) {
		smallest = 100;
		for (int i=0; i<N; i++) {
			if (searchedArray[i] < smallest) {
				smallest = searchedArray[i];
				savedIndex = i;
			}
		}
		searchedArray[savedIndex]=searchedArray[savedIndex]+1;
		newArray[j]=smallest;
	}
 
	for (int j=0;j<M;j++) {
		printf("%d\n", newArray[j]);
	}
 
	return 0;
}
 