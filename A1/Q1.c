#include <stdio.h>

void Create(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter The %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void Display(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int Insert(int* arr, int n, int pos, int addele) {
    if(pos > n + 1) {
        printf("Can't insert element at required position.\n");
        return n;
    } else {
        int ind = pos - 1;
        for(int i = n - 1; i >= ind; i--) {
            arr[i + 1] = arr[i];
        }
        arr[ind] = addele;
    }
    return n + 1;
}

int Delete(int* arr, int n, int pos) {
    int ind = pos - 1;
    for(int i = ind; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int Linear_Search(int* arr, int n, int ele) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == ele) {
            return i;
        }
    }
    return -1;
}

int Insert_by_element(int* arr, int n, int ele) {
    for(int i = 0; i < n; i++) {
        if(arr[0] > ele) {
            return Insert(arr, n, 1, ele);
        } else if(arr[n - 1] < ele) {
            return Insert(arr, n, n + 1, ele);
        }
        if(arr[i] <= ele && arr[i + 1] > ele) {
            return Insert(arr, n, i + 2, ele);
        }
    }
    return -1;
}

int main() {
    int arr[10];
    int Func;
    int size;
    printf("Enter The No. of Elements: ");
    scanf("%d", &size);
    Create(arr, size);
    printf("Press 1 to display Array\n");
    printf("Press 2 to Insert an element Array\n");
    printf("Press 3 to Delete an element Array\n");
    printf("Press 4 to Linear Search Array\n");
    printf("Press 5 to Insert By element Array\n");
    printf("Press 6 to Exit Array\n");
    scanf("%d", &Func);
while(Func!=6){
    switch(Func) {
        case 1: {
            Display(arr, size);
            break;
        }
        case 2: {
            int pos;
            int addele;
            printf("Enter the position where the element is to be added: ");
            scanf("%d", &pos);
            printf("Enter the element to be added: ");
            scanf("%d", &addele);
            size = Insert(arr, size, pos, addele);
            Display(arr, size);
            break;
        }
        case 3: {
            int pos;
            printf("Enter the Position of element to be deleted: ");
            scanf("%d", &pos);
            size = Delete(arr, size, pos);
            Display(arr, size);
            break;
        }
        case 4: {
            int ele;
            printf("Enter the element to be searched: ");
            scanf("%d", &ele);
            int index = Linear_Search(arr, size, ele);
            printf("%d\n", index);
            break;
        }
        case 5: {
            int ele;
            printf("Enter the element to be added: ");
            scanf("%d", &ele);
            size = Insert_by_element(arr, size, ele);
            Display(arr, size);
            break;
        }
        case 6: {
            break;
        }
        default: {
            printf("Invalid Argument\n");
            break;
        }
    }
    scanf("%d", &Func);
}
    return 0;
}
