#include <stdio.h>
#include <vector>
#define N 1005
using namespace std;


vector<pair<int, int> > adj[N]; // i노드가 출발지인 간선, first는 목적지 second는 비용
int dist[N]; // 선택된 노드들과 i 노드가 연결되어 있는 간선의 비용 중 최소비용
bool selected[N]; // i가 선택된 노드인가?

long long prim(int pn){
    long long ret = 0;
    for(int i=1;i<=pn;i++){
        dist[i]=2140000000;
        selected[i]=false;
    }

    dist[1]=0;
    printf("got here!\n");
    for(int i=1;i<=pn;i++){
        printf("%d\n", i);
        int now=-1;
        int min_dist=2140000000;
        for(int j=1;i<=pn;j++){
            //printf("%d\n", j);
            if(!selected[j] && min_dist>dist[j]){
                min_dist = dist[j];
                now=j;
            }
        }
        printf("%d\n", i);
        if(now<0) return (long long)2140000000; 
        ret+=min_dist;
        selected[now]=true;
        for(int j=0;j<adj[now].size();j++){
            dist[adj[now][j].first]=(dist[adj[now][j].first]>adj[now][j].second)?adj[now][j].second:dist[adj[now][j].first];
        }
    }
    return ret;
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    while(m--){
        int v1, v2, c;
        scanf("%d%d%d", &v1, &v2, &c);
        adj[v1].push_back(make_pair(v2, c));
        adj[v2].push_back(make_pair(v1, c));
    }
    printf("good!\n");

    printf("%lld\n", prim(n));
    return 0;
}