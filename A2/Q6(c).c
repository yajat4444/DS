
#include <stdio.h>
void sparse(int n, int m, int mat[n][m], int a, int sp[a][3]){
    int k = 1;
    sp[0][0] = n;
    sp[0][1] = m;
    sp[0][2] = a - 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] != 0){
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = mat[i][j];
                k++;
            }
        }
    }
}

void printmat(int n, int m, int mat[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

void scanmat(int n, int m, int mat[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

int multsparse(int n1, int m1, int sp1[n1][3], int n2, int m2, int sp2[n2][3], int n3, int m3, int sp3[n3][3]){
    if (sp1[0][1] != sp2[0][1]) {
        printf("Matrices cannot be multiplied\n");
        return 0;
    }
    sp3[0][0] = sp1[0][0]; 
    sp3[0][1] = sp2[0][0]; 
    int nnz1 = sp1[0][2];
    int nnz2 = sp2[0][2];
    int k = 1;

    for (int r = 0; r < sp1[0][0]; r++) {
        for (int c = 0; c < sp2[0][0]; c++) {
            int sum = 0;
            for (int i = 1; i <= nnz1; i++) {
                if (sp1[i][0] != r) continue;
                int colA = sp1[i][1];
                int valA = sp1[i][2];
                for (int j = 1; j <= nnz2; j++) {
                    if (sp2[j][0] != c) continue;
                    if (sp2[j][1] == colA) {
                        sum += valA * sp2[j][2];
                    }
                }
            }
            if (sum != 0) {
                sp3[k][0] = r;
                sp3[k][1] = c;
                sp3[k][2] = sum;
                k++;
            }
        }
    }
    sp3[0][2] = k - 1;
    return k;
}
int main()
{
    //declaration
    int n,m;
    printf("Enter the order of matrix A: n and m ");
    scanf("%d",&n);
    scanf("%d",&m);
    int A[n][m];
    printf("Enter the elements of first matrix\n");
    scanmat(n, m, A);
    printf("The entered matrix is:\n");
    printmat(n, m, A);
    int count=0;
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){
            if(A[i][j]!=0){
                count++;
            }
        }
    }
    int sp1[count+1][3];
    sparse(n, m, A, count+1, sp1);
    printf("The sparse matrix is:\n");
    printmat(count+1, 3, sp1);
    
    printf("Enter the order of matrix B: p and q ");
    int p ,q;
    scanf("%d",&p); 
    scanf("%d",&q);
    int B[p][q];
    printf("Enter the elements of first matrix\n");
    scanmat(p, q, B);
    printf("The entered matrix is:\n");
    printmat(p, q, B);
    int count2=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(B[i][j]!=0){
                count2++;
            }
        }
    }
    int sp2[count2+1][3];
    sparse(p, q, B, count2+1, sp2);
    printf("The sparse matrix is:\n");
    printmat(count2+1, 3, sp2);

    
    
    int temp;
    for(int i=0;i<count2+1;i++){
        temp=sp2[i][0];
        sp2[i][0]=sp2[i][1];
        sp2[i][1]=temp;
    }
    printf("\n");
    
    int swapped;
    for (int pass = 1; pass <= count2; pass++) {
        swapped = 0;
        for (int j = 1; j <= count2 - pass; j++) {
            if (sp2[j][0] > sp2[j+1][0]) {
                // swap entire triplet
                for (int t = 0; t < 3; t++) {
                    temp = sp2[j][t];
                    sp2[j][t] = sp2[j+1][t];
                    sp2[j+1][t] = temp;
                }
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    printf("\n");
    printf("The transposed sparse matrix B is:\n");
    
    printmat(count2+1, 3, sp2);

    int sp3[count+count2+1][3];
    int size=multsparse(count+1, 3, sp1, count2+1, 3, sp2, count+count2+1, 3, sp3);
    printf("The resultant sparse matrix after multiplication is:\n");
    printmat(size, 3, sp3);
    
    return 0;
}
