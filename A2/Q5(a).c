#include <stdio.h>

int main(){
    //normal diagonal matrix input
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%d",&matrix[i][j]);
      }
    }
    //printing the normal matrix
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        printf("%d ",matrix[i][j]);
      }
      printf("\n");
    }

    
    int diag[n];
    printf("\n");

    for (int i = 0; i < n; i++) {
        diag[i] = matrix[i][i];
    }

    //printing the diagonal elements    
    for (int i = 0; i < n; i++) {
        printf("%d ", diag[i]);
    }

    return 0;
}
