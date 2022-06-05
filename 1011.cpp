#include <cstdio>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d%d", &x, &y);

        // find closest square number;
        int max_ = 0;
        while(y-x>=max_*max_) max_++;
        max_--;

        if(y-x==max_*max_){
            printf("%d\n", 2*(max_)-1);
        }

        else{
            if(y-x>max_*max_ && y-x<=(max_)*(max_+1)){
                printf("%d\n", 2*max_);
            }
            else printf("%d\n", 2*max_+1);
        }
    }
}