#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int visited[100001];
vector<pair<int , int> > edge[100001];

long long prim(int n){
    long long ans=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, 1)); // 0이 가중치 1이 노드이름

    while(!pq.empty()){
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(!visited[cur_node]){
            visited[cur_node]=1;
            ans+=cur_cost;
            printf("%d ", ans);

            for(int i=0;i<edge[cur_node].size();i++){
                if(!visited[edge[cur_node][i].second]) pq.push(edge[cur_node][i]);
            }
        }
    }
    return ans;
}

int main(){
    int v, e;
    scanf("%d%d", &v, &e);

    for(int i=0;i<e;i++){
        int v1, v2, c;
        scanf("%d%d%d", &v1, &v2, &c);
        edge[v1].push_back(make_pair(c, v2));
        edge[v2].push_back(make_pair(c, v1));
    }

    long long result = prim(v);
    printf("%lld", result);
    return 0;
}