#include <stdio.h>

int n; 
int A[1000];
int sum[1000]={0};

void quick_sort(int s, int e){
    if(s>=e) return;

    int pivot = s;
    int i=pivot+1;
    int j=e;

    while(i<=j){
        while(i<=e && A[i]<=A[pivot]) i++;
        while(j>s && A[j]>=A[pivot]) j--;

        if(i>j){
            int temp = A[j];
            A[j]=A[pivot];
            A[pivot]=temp;
        }
        else{
            int temp = A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }

    quick_sort(s, j-1);
    quick_sort(j+1, e);
}

int binary_search(){
    int l=0;
    int r=n-1;
    int pos = n-1;
    int mid;
    int bsum=sum[n-1];

    while(l<=r){
        mid = (l+r)/2;
        printf("mid: %d, l: %d, r: %d\n", mid, l, r);
        int left_sum = sum[mid];
        int right_sum = sum[n-1] - sum[mid];
        if(left_sum>=right_sum){
            r = mid-1;
            printf("pos: %d, mid: %d, left_sum: %d, right_sum: %d\n", pos, mid, left_sum, right_sum);
            if(left_sum-right_sum<bsum){
                pos = mid;
                bsum = left_sum-right_sum;
            }
        }
        else{
            l = mid+1;
            printf("pos: %d, mid: %d, left_sum: %d, right_sum: %d\n", pos, mid, left_sum, right_sum);
            if(right_sum-left_sum<bsum){
                pos = mid;
                bsum = right_sum-left_sum;
            }
        }
    }
    printf("mid: %d, pos: %d\n", mid, pos);
    return mid;
}


int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    quick_sort(0, n-1);

    for(int i=0;i<n;i++){
        if(i) sum[i]=sum[i-1]+A[i];
        else sum[i]=A[i];
    }

    int p = binary_search();

    int sum=0;
    for(int i=0;i<n;i++){
        if(A[p]<A[i]) sum+=(A[i]-A[p]);
        else sum+=(A[p]-A[i]);
    }

    printf("%d %d\n", p, sum);
}