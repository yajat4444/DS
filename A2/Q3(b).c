#include <stdio.h>

int MissingNum2(int *arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((arr[mid] != (mid + 1)) && (mid > 0 && arr[mid - 1] == mid)) {
            return mid + 1;
        } else if (arr[mid] == (mid + 1)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
    
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n-1;i++){
        scanf("%d",&arr[i]);
    }

    int num = MissingNum2(arr, n);
    printf("The Missing Number is: %d\n", num);

    return 0;
}
