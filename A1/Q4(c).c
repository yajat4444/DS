#include <stdio.h>

int main() {
	int m,n;
	
	scanf("%d%d",&m,&n);
	int a[m][n];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nNormal array:-\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	int b[n][m];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
					b[j][i]=a[i][j];
		}
	}
	printf("\nTransposed array:- \n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
