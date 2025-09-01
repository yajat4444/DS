
#include <stdio.h>

/* Use C99 VLA parameter types so 2D arrays declared as int mat[n][m]
   can be passed directly. Size parameters must come before the VLA. */
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

int addsparse(int n1, int m1, int sp1[n1][3], int n2, int m2, int sp2[n2][3], int n3, int m3, int sp3[n3][3]){
    if(sp1[0][0]!=sp2[0][0] || sp1[0][1]!=sp2[0][1]){
        printf("Matrices cannot be added\n");
        return 0;
    }
    sp3[0][0]=sp1[0][0];
    sp3[0][1]=sp1[0][1];
    int i=1,j=1,k=1;
    while(i<=sp1[0][2] && j<=sp2[0][2]){
        if(sp1[i][0]<sp2[j][0]){
            sp3[k][0]=sp1[i][0];
            sp3[k][1]=sp1[i][1];
            sp3[k][2]=sp1[i][2];
            i++;
            k++;
        }
        else if(sp1[i][0]>sp2[j][0]){
            sp3[k][0]=sp2[j][0];
            sp3[k][1]=sp2[j][1];
            sp3[k][2]=sp2[j][2];
            j++;
            k++;
        }
        else{
            if(sp1[i][1]<sp2[j][1]){
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                i++;
                k++;
            }
            else if(sp1[i][1]>sp2[j][1]){
                sp3[k][0]=sp2[j][0];
                sp3[k][1]=sp2[j][1];
                sp3[k][2]=sp2[j][2];
                j++;
                k++;
            }
            else{
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2]+sp2[j][2];
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<=sp1[0][2]){
        sp3[k][0]=sp1[i][0];
        sp3[k][1]=sp1[i][1];
        sp3[k][2]=sp1[i][2];
        i++;
        k++;
    }
    while(j<=sp2[0][2]){
        sp3[k][0]=sp2[j][0];
        sp3[k][1]=sp2[j][1];
        sp3[k][2]=sp2[j][2];
        j++;
        k++;
    }
    sp3[0][2]=k-1;
    return k;
}

int main()
{
    int n,m;
    printf("Enter the order of matrix: n and m ");
    scanf("%d",&n);
    scanf("%d",&m);
    int mat[n][m], nat[n][m];
    printf("Enter the elements of first matrix\n");
    scanmat(n, m, mat);

    printf("The entered matrix is:\n");
    printmat(n, m, mat);
    int count=0;
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){
            if(mat[i][j]!=0){
                count++;
            }
        }
    }
    int sp1[count+1][3];
    sparse(n, m, mat, count+1, sp1);
    printf("The sparse matrix is:\n");
    printmat(count+1, 3, sp1);
    
    printf("Enter the elements of second matrix\n");
    scanmat(n, m, nat);
    printf("The entered matrix is:\n");
    printmat(n, m, nat);
    int count2=0;
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){
            if(nat[i][j]!=0){
                count2++;
            }
        }
    }
    int sp2[count2+1][3];
    sparse(n, m, nat, count2+1, sp2);
    printf("The sparse matrix is:\n");
    printmat(count2+1, 3, sp2);

    int sp3[count+count2+1][3];
    int size=addsparse(count+1, 3, sp1, count2+1, 3, sp2, count+count2+1, 3, sp3);
    printf("The resultant sparse matrix after addition is:\n");
    printmat(size, 3, sp3);
    
    return 0;
}
