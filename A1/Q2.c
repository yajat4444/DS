#include <stdio.h>

void Display(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
}

int Delete(int* arr, int n, int pos) {
    int ind = pos - 1;
    for (int i = ind; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                n = Delete(arr, n, j + 1);
                j--; // Adjust j after deletion
            }
        }
    }

    Display(arr, n);
    return 0;
}
