#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        scanf("%d",&arr[i]);
    }
    int save=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]==i+1){
            continue;
        }
        save=i+1;
        break;
    }
    printf("Missing number is %d",save);

    return 0;
}
