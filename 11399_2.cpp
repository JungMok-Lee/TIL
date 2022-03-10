#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first>b.first;
}

int main(){
    int n;
    int p[1001];
    
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &p[i]);
    
    sort(p, p+n);

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(n-i)*p[i];
    }

    printf("%d\n", ans);
}