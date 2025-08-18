#include<stdio.h>

void func(int *ar,int x);

int main(){



    int m;

    scanf("%d",&m);



    int arr[m];

    for(int i=0;i<m;i++){

        scanf("%d",&arr[i]);

    }

    func(arr,m);





    return 0;

}



void func(int *ar, int x){

    if(x%2==0){

        int temp;

        for(int i=0;i<x/2;i++){

            temp = ar[i];

            ar[i]=ar[x-1-i];

            ar[x-1-i]=temp;

        }

    }else{

        for(int i=0;i<x/2;i++){

            int y=(x-1)/2;

            int temp;

            if(i==y){

                continue;

            }

            temp = ar[i];

            ar[i]=ar[x-1-i];

            ar[x-1-i]=temp;

        }

    }

    for(int i=0;i<x;i++){

        printf("%d",ar[i]);

    }

}
