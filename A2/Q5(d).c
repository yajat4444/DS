#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix ");
    scanf("%d",&n);

    int upper[n*(n+1)/2];
    int k=0;

    for(int d=0; d<n; d++) {
        if(d==0) {
            printf("Enter %d elements of main diagonal\n", n);
        } else {
            printf("Enter %d elements of %d diagonal above main\n", n-d, d);
        }
        for(int i=0; i<n-d; i++) scanf("%d",&upper[k++]);
    }

    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) matrix[i][j]=0;
    }

    k=0;
    for(int d=0; d<n; d++) {
        for(int i=0; i<n-d; i++) {
            int row=i, col=i+d;
            matrix[row][col] = upper[k++];
        }
    }

    printf("\nNormal Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",matrix[i][j]);
        printf("\n");
    }

    printf("\nUpper Triangular Storage:\n");
    for(int i=0;i<n*(n+1)/2;i++) printf("%d ",upper[i]);

    return 0;
}
