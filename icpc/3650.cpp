#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[1000];
vector<int> adj2[1000];

int main(){
    int k;
    string s1;
    string s2;

    cin>>k>>s1>>s2;

    // 0번째 숫자가 갈 수 있는 graph

    int bn = s1.length()/k;

    // 첫번째 블록
    for(int i=0;i<k;i++){
        // char tmp = s1[i];
        for(int j=0;j<k;j++){
            if(s1[i]-s2[j]==0) {
                cout<<"good"<<endl;
                adj[i].push_back(j);
            }
        }

        cout<<i<<" : ";
        for(int t=0;t<adj[i].size();t++){
            cout<<adj[i][t]<<",";
        }
        cout<<endl;
    }

    // 나머지 블록에서 체크
    for(int c=1;c<bn;c++){
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(s1[i+c*k]-s2[j+c*k]==0){
                    
                }
            }

            cout<<i<<" : ";
            for(int t=0;t<adj[i].size();t++){
                cout<<adj[i][t]<<",";
            }
            cout<<endl;
    }
    }
}