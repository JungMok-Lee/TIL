#include <iostream>
using namespace std;

int stack[10001];
int size=0;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin>>n;

    int stack[10001];
    int s=0;


    while(n--){
        string o;
        cin>>o;

        if(o=="push"){
            int k;
            cin>>k;
            stack[s]=k;
            s++;
        }
        else if(o=="pop"){
            if(s==0) cout<<-1<<"\n";
            else{
                cout<<stack[s-1]<<"\n";
                s--;
            }
        }
        else if(o=="size") cout<<s<<"\n";
        else if(o=="empty") cout<<((s==0)?1:0)<<"\n";
        else if(o=="top") {
            if(s==0) cout<<-1<<"\n";
            else cout<<stack[s-1]<<"\n";
        }
    }
}