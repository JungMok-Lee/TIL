#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int n,k;
    char a[500001];
    scanf("%d%d", &n, &k);
    scanf("%s", a);

    stack<int> s;
    for(int i=0;i<n;i++){
        while(k && !s.empty() && s.top()<a[i]-48){
            s.pop();
            k--;
        }
        s.push(a[i]-48);
    }

    while(k--) s.pop();

    stack<int> s2;
    while(!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    while(!s2.empty()){
        printf("%d", s2.top());
        s2.pop();
    }

    printf("\n");
}