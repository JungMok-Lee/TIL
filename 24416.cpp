#include <cstdio>

int c1=1;

int fib(int n) {
    if (n == 1 || n == 2) return 1;
    else {
        c1++;
        return (fib(n - 1) + fib(n - 2));
    }
}

int f[41];
int main(){
    int n;
    scanf("%d", &n);

    fib(n);
    printf("%d ", c1);
    printf("%d\n", n-2);

}