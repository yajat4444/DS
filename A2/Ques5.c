#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        scanf("%d",&matrix[i][j];
      }
    }
    
    int diag[n];

    for (int i = 0; i < n; i++) {
        diag[i] = matrix[i][i];
    }

    return 0;
}
