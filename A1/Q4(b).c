#include <stdio.h>

int main()
{
    int m,n,o;
    printf("Write m and n dimensions for first array and n and o for second array\nWrite 3 dimensions:- ");
    scanf("%d%d%d",&m,&n,&o);
    int a[m][n],b[n][o];
    int c[m][o];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("First array is:- \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("Second array is:- \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    printf("Multiplied Array is:- \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
