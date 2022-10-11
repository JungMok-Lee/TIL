#include <iostream>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n --){
        string str, ans, mini;
        bool flag = false, end = false;
        cin >> str;
        ans = str[0];
        for(int i = 1 ; i < str.length() ; i++){
            if(end){
                ans += mini;
            }
            else if(str[i] - str[i - 1] >= 0 and !flag){
                ans += str[i];
            }
            else if(!flag){
                flag = true;
                mini = str[i];
                ans += mini;
            }
            else if(flag && str[i - 1] - str[i] >= 0){
                mini = str[i];
                ans += mini;
            }
            else{
                end = true;
                ans += mini;
            }
        }
        cout << ans << endl;
    }

}