#include <cstdio>

int main(){
    int N, X, V;
    scanf("%d%d%d", &N, &X, &V);

    int l[101];
    int r[101];
    int v[101];

    for(int i=0;i<N;i++){
        scanf("%d%d%d", &l[i], &r[i], &v[i]);
    }

    int cur = 0;
    int ci = 0;
    float time=0;

    for(int i=0;i<N;i++){
        // 직진구간
        int bcur = cur;
        if(l[i]>cur){
            time+=float((l[i]-cur)/V);
            printf("straight: %f\n", time);
        }

        cur=l[i];
        // 움직이는 구간
        time+=float((r[i]-l[i])/V);
        cur=r[i];
        printf("tilt: %f\n", time);
    }

    printf("%d\n", cur);
    if(X>cur){
        time+=float((X-cur)/V);
        printf("%f\n", time);
    }
}