//TRN form pl.spoj.com
#include <stdio.h>
 
int main() {
	
	int numRows, numCols;
	scanf("%d %d", &numRows, &numCols);
	int matrix[numRows][numCols];
	
	for (int i = 0; i < numRows; i++) {
		
		for (int j = 0; j < numCols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	
	}
	
	for (int i = 0; i < numCols; i++) {
		
		for (int j = 0; j < numRows; j++) {
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
	return 0;
} 