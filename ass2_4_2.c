#include <stdio.h>

int n;
int A[1000000];

void quicksort(int s, int e){
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

    quicksort(s, j-1);
    quicksort(j+1, e);
}

long long k_sum(int k){ // O(n)
    int sum_=0;
    for(int i=0;i<n;i++){
        if(A[k]<A[i]) sum_+=(A[i]-A[k]);
        else sum_+=(A[k]-A[i]);
    }

    return sum_;
}

int main(){
    scanf("%d", &n);

    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
        sum+=A[i];
    }

    quicksort(0, n-1);

    int l=0, r=n-1;
    int mid=(l+r)/2;

    int ans=0;

    while(l<=r){
        mid=(l+r)/2;
        long long left=k_sum(l);
        long long right=k_sum(r);

        if(left==right) {
            ans=mid;
            break;
        }

        else if(left<right){
            r=mid;
        }

        else if(left>right){
            l=mid;
        }

        if(l==mid || r==mid) break;
    }

    printf("%lld\n", k_sum(mid));
}