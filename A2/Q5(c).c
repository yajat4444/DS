#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix ");
    scanf("%d",&n);

    int lower[n*(n+1)/2];
    int k=0;

    for(int d=0; d<n; d++) {
        if(d==0) {
        printf("Enter %d elements of main diagonal\n", n);
        for(int i=0; i<n-d; i++) {
            scanf("%d", &lower[k++]);
        }
    }
        else{
        printf("Enter %d elements of %d diagonal below main \n", n-d, d);
        for(int i=0; i<n-d; i++) {
            scanf("%d", &lower[k++]);
        }
    }
    }

    int matrix[n][n];
    k=0;
    for(int d=0; d<n; d++) {
        for(int i=0; i<n-d; i++) {
            int row = i+d, col = i;
            matrix[row][col] = lower[k++];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<j) matrix[i][j] = 0;
        }
    }

    printf("\nNormal Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",matrix[i][j]);
        printf("\n");
    }

    printf("\nLower Triangular Storage:\n");
    for(int i=0;i<n*(n+1)/2;i++) printf("%d ",lower[i]);

    return 0;
}
