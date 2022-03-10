#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int k;
    scanf("%d", &k);

    stack<int> s;
    for(int i=0;i<k;i++){
        int n;
        scanf("%d", &n);

        if(n==0) s.pop();
        else s.push(n);
    }
    int sum=0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    printf("%d\n", sum);
}