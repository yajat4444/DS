#include<stdio.h> 
void func(int*ar,int x,int y);
int main(){
    int m,n;
    scanf("%d%d",&m,&n);

    int arr[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",*(*(arr+i)+j));
        }
        printf("\n");
    }
    func(*arr,m,n);

    return 0;
}

void func(int *ar,int x,int y){
    //sum of rows
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d\t",*(ar + i * y + j));
        }
        printf("\n");
    }
    for(int i=0;i<x;i++){
    int sum=0;
        for(int j=0;j<y;j++){
            sum+=*(ar + i * y + j);
        }
    printf("Sum of %d row is %d\n",i+1,sum);
}
for(int i=0;i<y;i++){
    //sum of coloumns
    int sum=0;
        for(int j=0;j<x;j++){
            sum+=*(ar + j * x + i);
        }
    printf("Sum of %d coloumn is %d\n",i+1,sum);
}
}
