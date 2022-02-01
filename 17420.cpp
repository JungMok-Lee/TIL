#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > v;
int a[1000001];
int b[1000001];

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) scanf("%d", &b[i]);
    for(int i=0;i<n;i++) v.push_back(make_pair(a[i], b[i]));

    sort(v.begin(), v.end(), cmp);

    unsigned long long ans=0;

    /*
    while(v.size()){
        bool is_all_okay=true;
        for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                a[i]+=30;
                is_all_okay=false;
                ans++;
            }
        }
        if(is_all_okay) v.erase(v.begin());   
    }*/

    int max = v[0].second;
    int cmax = -1;

    for(int i=0;i<n;i++){
        if(max>v[i].first){
            if(max<v[i].second) max=v[i].second;

            int cnt=((max-v[i].first)+29)/30;
            v[i].first+=30*cnt;
            ans+=cnt;
        }

        cmax = (cmax<v[i].first)?v[i].first:cmax;

        if((i+1)<n && v[i].second!=v[i+1].second) max = cmax;
    }

    printf("%llu\n", ans);
}