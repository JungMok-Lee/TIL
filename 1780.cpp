#include <cstdio>

int a[2190][2190];
int zero, one, minusone;

void count(int y, int x, int size){
    bool flag = true;

    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(a[y][x]!=a[i][j]){
                flag = false;
                count(y, x, size/3);
                count(y+size/3, x, size/3);
                count(y+2*size/3, x, size/3);

                count(y, x+size/3, size/3);
                count(y+size/3, x+size/3, size/3);
                count(y+2*size/3, x+size/3, size/3);

                count(y, x+2*size/3, size/3);
                count(y+size/3, x+2*size/3, size/3);
                count(y+2*size/3, x+2*size/3, size/3);
                return;
            }
        }
    }
    if(flag && a[y][x]==1) one++;
    else if(flag && a[y][x]==0) zero++;
    else if(flag && a[y][x]==-1) minusone++;
}
int main(){
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }

    count(0, 0, n);
    printf("%d\n%d\n%d\n", minusone, zero, one);
}