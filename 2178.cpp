#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int adj[101][101];
int visit[101][101] = {0,};
int shortest = 1000001;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void dfs(int sx, int sy, int depth){
    if(sx>n || sy>m) return;
    if(sx<1 || sy<1) return;
    
    if(sx==n && sy==m){
        if(depth<shortest) {
            shortest = depth;
        }
        return;
    }

    for(int i=0;i<4;i++){
        int nx = sx+dx[i];
        int ny = sy+dy[i];

        if(visit[nx][ny]==0 && adj[nx][ny]==1){
            visit[nx][ny]=1;
            dfs(nx, ny, depth+1);
            visit[nx][ny]=0; // 이게 중요
        }
    }
    //cout<<depth<<endl;

}

int main(){
    string s;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            adj[i][j]=s[j-1]-'0';
            //cout<<i<<" "<<j<<" , "<<adj[i][j]<<endl;
        }
    }
    dfs(1, 1, 1);
    cout<<shortest<<endl;

}