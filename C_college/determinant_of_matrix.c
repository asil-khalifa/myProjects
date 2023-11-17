#include <stdio.h>
#include <math.h>

void cofactor_matrix(int N, int ini[N][N], int temp[N][N], int n, int p, int q){
    //N = size of input matrix; finds cofactor matrix for element ini[p][q], n is the size of current matrix
    int i, j, new_i=0, new_j=0;
    for (i=0;i<n;i++){
        new_j=0;
        for (j=0;j<n;j++){
            if (i!=p&&j!=q) {
                temp[new_i][new_j] = ini[i][j];
                new_j++;
            }
        }
        if (i!=p) new_i++;
    }
}

int determinant(int N, int a[N][N], int n){
    int i=0, temp[N][N], D =0, debug;
    if (n==1) return a[0][0];
    else{
        for (;i<n;i++) {
            cofactor_matrix(N, a, temp, n, 0, i);
            D += a[0][i]*determinant(N, temp, n-1) * pow(-1, i);
        }
        return D;
    }
}

int main(){
    int N, i, j;
    printf("Size: ");
    scanf("%d", &N);
    int a[N][N], b[N][N]={};
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            printf("Enter: ");
            scanf("%d", &a[i][j]);
        }
    }
    printf("Determinant = %d", determinant(N, a, N));
}
