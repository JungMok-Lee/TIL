#define MAX 1000

#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

float min_distance(float points[MAX][2], int n){
    float distance = 0.0;

    //vector<pair<int, float> > adj[MAX];
    float adj[n][n];
    
    // adj list 생성
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[j][0];
            int y2=points[j][1];
            float distance = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
            adj[i][j]=distance;
        }
    }

    // 여기서부터 다익스트라!
    float d[n+1];
    memset(d, MAX, sizeof(d));
    d[1]=0;

    priority_queue<pair<float, int> > pq; // 거리, 노드

    pq.push(make_pair(1, d[1]));

    while(!pq.empty()){
        int cur = pq.top().second;

        float dis = -pq.top().first;

        pq.pop();

        if(d[cur]<dis) continue;

        for(int i=1;i<=n;i++){
            if(adj[cur][i]!=0){
                int next = i;

                float dist = dis + adj[cur][i];

                if(d[next]>dist){
                    d[next]=dist;
                    pq.push(make_pair(-dist, next));
                }
            }
        }
    }

    for(int i=1;i<n+1;i++){
        printf("%f\n", d[i]);
    }

    



    

    return distance;
}

// points[i][0]=x, points[i][1]=y

// 그래프 노드(x,y) 기억하기

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