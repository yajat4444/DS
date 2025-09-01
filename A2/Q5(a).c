#include <stdio.h>

int main(){
    //normal diagonal matrix input
    int n;
    scanf("%d",&n);
    int diag[n];
    //Input Diagonal elements
    for(int i=0;i<n;i++){
        scanf("%d",&diag[i]);
    }
    int matrix[n][n];
    //filling the normal matrix with diagonal elements 
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j){
          matrix[i][j]=diag[i];
        }
        else{
          matrix[i][j]=0;
        }
      }
    }
    //printing the normal matrix
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        printf("%d ",matrix[i][j]);
      }
      printf("\n");
    }

    
    printf("\n");
    //printing the diagonal elements    
    for (int i = 0; i < n; i++) {
        printf("%d ", diag[i]);
    }

    return 0;
}
