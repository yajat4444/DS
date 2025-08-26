
#include <stdio.h>

int main()
{
    //declaration
    int sp[9][3]={{6,6,8},{0,0,15},{0,3,22},{0,5,-15},{1,1,11},{1,2,3},{2,3,-6},{4,0,91},{5,2,28}};
    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            printf("%d  ",sp[i][j]);
        }
        printf("\n");
    }
    int temp;
    //sort
    for(int i=1;i<9;i++){
        temp=sp[i][0];
        sp[i][0]=sp[i][1];
        sp[i][1]=temp;
    }
    printf("\n");
    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            printf("%d  ",sp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int flag;
    //sort
    for(int i=0;i<9;i++){
        flag=0;
        for(int j=1;j<8-i;j++){
            if(sp[j][0]>sp[j+1][0]){
                flag=1;
                for(int k=0;k<3;k++){
                    temp=sp[j][k];
                    sp[j][k]=sp[j+1][k];
                    sp[j+1][k]=temp;
                }
                if(flag==0){
                    break;
                }
            }
        }
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            printf("%d  ",sp[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
