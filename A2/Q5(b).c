#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix  ");
    scanf("%d",&n);

    int tri[3*n - 2]; 
    int k = 0;

    //Input upper diagonal
    printf("Enter %d elements of Upper Diagonal:\n", n-1);
    for(int i=0;i<n-1;i++){
        scanf("%d",&tri[k++]);
    }

    //Input main diagonal
    printf("Enter %d elements of Main Diagonal:\n", n);
    for(int i=0;i<n;i++){
        scanf("%d",&tri[k++]);
    }

    //Input lower diagonal
    printf("Enter %d elements of Lower Diagonal:\n", n-1);
    for(int i=0;i<n-1;i++){
        scanf("%d",&tri[k++]);
    }

    int matrix[n][n];
    int idx = 0;

    //upper diagonal
    for(int i=0;i<n-1;i++){
        matrix[i][i+1] = tri[idx++];
    }

    //main diagonal
    for(int i=0;i<n;i++){
        matrix[i][i] = tri[idx++];
    }

    //lower diagonal
    for(int i=0;i<n-1;i++){
        matrix[i+1][i] = tri[idx++];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!(i==j || i==j+1 || i==j-1)){
                matrix[i][j] = 0;
            }
        }
    }

    // Print normal matrix
    printf("\nNormal Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    // Print compact storage
    printf("\nTri-diagonal (Upper, Main, Lower):\n");
    for(int i=0;i<3*n-2;i++){
        printf("%d ",tri[i]);
    }

    return 0;
}
