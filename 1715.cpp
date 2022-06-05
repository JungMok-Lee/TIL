#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int k; 
        scanf("%d", &k);
        pq.push(k);
    }

    int sum=0;
    
    while(pq.size()>1){
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        
        sum+= (a+b);
        pq.push(a+b);
    }
    printf("%d\n", sum);
}