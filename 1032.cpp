#include <iostream>
using namespace std;

int main(){
    int n;
    char f[51][51];
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", f[i]);
    }

    int len=0;
    while(f[0][len]) len++;

    char ans[51];
    
    for(int i=0;i<len;i++){
        for(int j=0;j<n;j++){
            if(j==0) ans[i]=f[j][i];
            else if(ans[i]!=f[j][i]) ans[i]='?';
        }

        printf("%c", ans[i]);
    }
    printf("\n");
}
