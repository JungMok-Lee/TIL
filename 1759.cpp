#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
/*
    backtracking 도 너무 어렵다 ...
*/
int l, c; // l: 비밀번호 자릿수, c: 쓰일 만한 알파벳 수
char a[16];

void backtrack(int pos, string s, int j, int m){
    if(s.size()==l){ // 입력받은 string이 완성되었을 때
        if(j<2 || m<1) return; // 자음, 모음의 조건을 만족해야만 
        cout<<s<<endl; // 출력
    }

    for(int i=pos;i<c;i++){ // 현재 위치부터 c 전까지
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') backtrack(i+1, s+a[i], j, m+1); // i번째가 모음이면 모음 넣고 다시 backtrack
        else backtrack(i+1, s+a[i], j+1, m); //자음이면 자음 넣고 다시 backtrack
    }
}

int main(){
    scanf("%d%d", &l, &c);

    for(int i=0;i<c;i++) cin>>a[i];
    sort(a, a+c); // 알파벳이 증가하는 순서대로 생성되었기 때문에 처리
    backtrack(0, "", 0, 0);
}