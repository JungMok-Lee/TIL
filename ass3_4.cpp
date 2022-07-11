#define MAX 1000

#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;


// int나중에 다 float로 바꾸기!!!!!!!
//vector<pair<float, int> > edge[MAX]; // 간선대로 pq 담겨야되서 float 간선비용이 먼저 오도록.
pair<float, int> edge[MAX][MAX];
int visited[MAX];

float prim(){

    // for(int i=1;i<=5;i++){
    //     printf("%d => ", i);
    //     for(int j=0;edge[i][j].first!=0;j++){
    //         printf("%d:%f ", edge[i][j].second, edge[i][j].first);
    //     }
    //     printf("\n\n");
    // }

    float ans=0;
    priority_queue<pair<float, int> > pq;
    // , vector<pair<float, int> >, greater<pair<float, int> > 

    pq.push(make_pair(0, 1)); // 1번째 노드에서 시작! (0은 비용 1은 노드 이름임. 거꾸로넣었다!!!!!)

    while(!pq.empty()){
        int cur_node = pq.top().second;
        float cur_cost = pq.top().first;
        //printf("%d %f\n", cur_node, cur_cost);
        pq.pop();

        if(!visited[cur_node]){
            visited[cur_node]=1;
            ans+=cur_cost;
            //printf("cost: %f\n", cur_cost);

            //for(int i=0;i<edge[cur_node].size();i++){
            for(int i=0;edge[cur_node][i].first!=0;i++){
                if(!visited[edge[cur_node][i].second]) pq.push(edge[cur_node][i]);
            }
        }
    }
    if(ans==0) return 0;
    return -ans;
}

float min_distance(float points[MAX][2], int n){
    float distance = 0.0;

    // adj list 생성
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                float distance = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
                
                int k=0;
                while(edge[i][k].first!=0 && edge[i][k].second!=0) k++;
                //edge[i].push_back(make_pair(distance, j));
                edge[i][k].first=-distance; // 오름차순으로 담겨야되는데 pq는 내림차순이라서. 벡터 빼려면 이렇게 해야 함.
                edge[i][k].second=j;
            }
        }
    }

    //distance = prim();
    float ans=0;
    priority_queue<pair<float, int> > pq;
    // , vector<pair<float, int> >, greater<pair<float, int> > 

    pq.push(make_pair(0, 1)); // 1번째 노드에서 시작! (0은 비용 1은 노드 이름임. 거꾸로넣었다!!!!!)

    while(!pq.empty()){
        int cur_node = pq.top().second;
        float cur_cost = pq.top().first;
        //printf("%d %f\n", cur_node, cur_cost);
        pq.pop();

        if(!visited[cur_node]){
            visited[cur_node]=1;
            ans+=cur_cost;
            //printf("cost: %f\n", cur_cost);

            //for(int i=0;i<edge[cur_node].size();i++){
            for(int i=0;edge[cur_node][i].first!=0;i++){
                if(!visited[edge[cur_node][i].second]) pq.push(edge[cur_node][i]);
            }
        }
    }
    if(ans==0) distance=0;
    else distance = -ans;

    return distance;
}


vector<pair<int, float> > adj;
int main(){
    float points[MAX][2];
    int n;
    scanf("%d", &n); // n은 노드 개수

    for(int i=1;i<=n;i++){
        float x,y;
        scanf("%f%f", &x, &y);
        points[i][0]=x; // i가 node이름, x, y는 i 노드의 위치 정보
        points[i][1]=y;
    }

    printf("%f\n", min_distance(points, n));

}