#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;
typedef long long ll;

const int P = 998244353;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

const int N = 5e5 + 5;
int n;
ll sum, sum_div, ans, cnt;
int a[N];
ll s[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];   
    }
    sum = s[n];
    if(sum % 3){
        cout << "0\n";
        return 0;
    }
    sum_div = sum / 3;
    rep(i, 1, n - 1){
        if(s[i] == (sum_div << 1))ans += cnt;
        if(s[i] == sum_div)++cnt;
    }
    cout << ans << '\n';
    return 0;
}