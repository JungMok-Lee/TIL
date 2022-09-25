#include<iostream>
#include <queue>
#include <map>

# pragma GCC optimize ("O3")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define pii pair<int, int>
#define ll long long
#define lld long double
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    lld ans[n];
    ll p = 0; ll mult = 1; ll tot = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        p += a[i]*mult;
        mult *= 51;
        tot += a[i];
        ans[i] = 0;
    }

    map<ll, lld> dp;
    dp[p] = 100;
    queue<pll> s1;
    s1.push({p, 0});
    while(!s1.empty()) {
        pll t = s1.front();
        s1.pop();
        ll tempx = t.x;
        for (int i=0; i<n; i++) {
            a[i] = tempx%51;
            tempx /= 51;
        }
        ll mult = 1;
        for (int i=0; i<n; i++) {
            if (dp.find(t.x+mult) == dp.end()) {
                dp[t.x+mult] = 0;
                if (t.y < k - tot) s1.push({t.x+mult, t.y+1});
            }
            if (tot+t.y == k) {
                int m = 0; int cnt = 0;
                for (int j=0; j<n; j++) {
                    if (a[j] > m ) {
                        cnt = 1;
                        m = a[j];
                    } else if (a[j]==m) cnt++;
                }
                for (int j=0; j<n; j++) {
                    if (a[j]==m) {
                        ans[j] += dp[t.x]/(n*cnt);
                    }
                }
            } else {
                dp[t.x+mult] += ((lld)(a[i])/((tot+t.y))) * dp[t.x];
            }
            mult *= 51;
        }
    }
    for (int i=0; i<n; i++) {
        cout << "pub " << i+1 << ": " << fixed << setprecision(2) << ans[i] << " %\n";
    }
    return 0;
}