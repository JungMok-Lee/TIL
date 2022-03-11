#include <cstdio>
int a[128][128];

int blue=0;
int white=0;

void check(int y, int x, int size){
    bool flag = true;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(a[i][j]!=a[y][x]){
                flag = false;
                check(y, x, size/2);
                check(y, x+size/2, size/2);
                check(y+size/2, x, size/2);
                check(y+size/2, x+size/2, size/2);
                return;
            }
        }
    }
    if(flag && a[y][x]) blue++;
    else if(flag && !a[y][x]) white++;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }

    check(0, 0, n);
    printf("%d\n%d\n", white, blue);
}