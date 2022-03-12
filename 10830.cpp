#include <cstdio>

int a[5][5];

int arr[100000000001];

int mul(k){
    if(k==1) return x=arr[1];
    else if(k==2){

    }
    else{
        if(k%2==0) return arr[k]=mul(k/2)*mul(k/2);
        else return arr[k]=mul(k/2)*mul(k/2)
    }
}

int main(){
    int n, b;
    scanf("%d%d", &n, &b);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", a[i][j]);
        }
    }

    int fb = 1;
    int newa[5][5];
}