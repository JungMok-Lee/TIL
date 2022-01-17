#include <iostream>

int main(){
    int n, m;
    char b[51][51];
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%s", b[i]);
    }

    int min=10000000;
    for(int sx=0;sx<=n-8;sx++){
        for(int sy=0;sy<=m-8;sy++){
            int wrong=0;
            for(int i=sx;i<sx+8;i++){
                for(int j=sy;j<sy+8;j++){
                    if((i+j)%2==0 && b[i][j]=='B') wrong++;
                    else if((i+j)%2==1 && b[i][j]=='W') wrong++;
                }
            }
            wrong=(wrong<64-wrong)?wrong:64-wrong;
            if(wrong<min) min=wrong;
        }
    }
    printf("%d\n", min);

}
