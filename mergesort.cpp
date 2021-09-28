#include <iostream>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];
int *arr2;

void merge(int l, int r){
    int mid=(l+r)/2;
    int i=l;
    int j=mid+1;
    int k=l;
    
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]) arr2[k++]=arr[i++];
        else arr2[k++]=arr[j++];
    }
    
    //나머지쪽에 남아있는 것들 정리
    if(j>r) j=i; // 오른쪽 리스트가 다 채워지면 b=s, 왼쪽이 다 채워지면 냅둬
    while(k<=r) arr2[k++]=arr[j++];
    for(int i=l;i<=r;i++) arr[i]=arr2[i];
}

void apart(int l, int r){
    int mid;
    if(l<r) {
        mid=(l+r)/2;
    apart(l, mid);
    apart(mid+1, r);
    merge(l,r);
    }
}
int main(){
    scanf("%d", &n);
    arr2=new int[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    apart(0, n-1);
    for(int i=0;i<n;i++) printf("%d\n", arr[i]);
}