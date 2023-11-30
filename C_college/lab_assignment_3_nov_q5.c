#include <stdio.h>

int a_less_b_replace(int a, int b, int *p){
    // for an array arr, if a[a]<a[b], they get interchanged and returns 1 else returns 0
    int t;
    if (*(p+a)<*(p+b)){
        t = *(p+a);
        *(p+a) = *(p+b);
        *(p+b) = t;
        return 1;
    }
    return 0;
}

int main(){
    int n, i, j, t, done, k, min;
    printf("Enter how many elements: ");
    scanf("%d", &n);
    int a[n];
    for (i=0;i<n;i++){
        printf("Enter: ");
        scanf("%d", &a[i]);
    }

    printf("You entered: ");
    for (i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Enter k: ");
    scanf("%d", &k);

    for (i=0; i<n-1;i++){
        done = 1;
        min = (n-i<k)?(n-i):(k-1);
        for(j=0;j<min;j++) {   // goes till <min (n-i, k)
            // if j = k, we check with last element, for j>k we go in decrementing loop
            if (a_less_b_replace(j+1, j, a)) done = 0;
        }
        if (min == k-1){
            if (a_less_b_replace(n-1, j, a)) done = 0;
            for (j=n-1;j>k+i;j--){
                if (a_less_b_replace(j-1, j, a)) done = 0;
            }
        }
        if (done) break;
    }
    for (i=0;i<n;i++)
        printf("%d ", a[i]);
}
