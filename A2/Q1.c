#include <stdio.h>

int Binary_Search(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    

    int targ;
    scanf("%d",&targ);
    int ind = Binary_Search(arr, n, targ);
    printf("The index of Element to be found is: %d\n", ind);
    return 0;
}
