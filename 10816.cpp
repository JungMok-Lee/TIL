#include <cstdio>
#include <algorithm>
using namespace std;
int a[20000001];

int main(){
    int n, m;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d", &k);
        a[k+10000000]++;
    }

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int k;
        scanf("%d", &k);

        printf("%d ", a[k+10000000]);
    }
    printf("\n");

}