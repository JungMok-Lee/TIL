#include <cstdio>
#include <string>
using namespace std;

int arr[64][64];
int n;
string result="";

void print(int x_s, int y_s, int s){
    int now=arr[y_s][x_s]; // arr[x_s][y_s] 하면 (0,0), (0,-1),(1,0),(-1,1) 순서대로 흝는다(세로로 흝는다) 중요!!!
    for(int i=y_s;i<y_s+s;i++){
        for(int j=x_s;j<x_s+s;j++){
            if(arr[i][j]!=now){ // 하나라도 안 똑같으면(다똑같아야만 합칠 수 있다) 4개로 나눠서 재귀를 돌려라
                printf("(");
                print(x_s, y_s, s/2);
                print(x_s+s/2, y_s, s/2);
                print(x_s, y_s+s/2, s/2);
                print(x_s+s/2, y_s+s/2, s/2);
                printf(")");
                return;
            }
        }
    }
    printf("%d", now); // 다 똑같으면 맨 마지막에 이거 하나 출력
}


int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char one[64];
        scanf("%s", one);
        for(int j=0;j<n;j++) arr[i][j]=int(one[j])-48;
    }
    print(0, 0, n); 
    printf("\n");
    
}