#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;

const int P = 998244353, N = 105, M = 2005;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int n,m;
int a[N][M], sum[N], g[N];
int f[2][N << 1];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    g[0] = 1;
    rep(i, 1, n){
        rep(j, 1, m){
            cin >> a[i][j];
            pls(sum[i], a[i][j]);
        }
        for(int j = i; j >= 1; --j)
            pls(g[j], 1ll * g[j - 1] * sum[i] % P);
    }
    int ans = 0;
    rep(i, 1, n){
        pls(ans, g[i]);
    }

    rep(ln, 1, m){
        memset(f, 0, sizeof(f));
        f[0][n] = 1;
        rep(i, 1, n){
            memset(f[i & 1], 0, sizeof(f[i & 1]));
            for(int j = n - i; j <= n + i; ++j){
                f[i & 1][j] = f[i & 1 ^ 1][j];
                
                pls(f[i & 1][j], 1ll * f[i & 1 ^ 1][j + 1] * dec(sum[i], a[i][ln]) % P);
                pls(f[i & 1][j], 1ll * f[i & 1 ^ 1][j - 1] * a[i][ln] % P);
            }
        }
        rep(i, 1, n){
            sub(ans, f[n & 1][n + i]);
        }
    }
    cout << ans << '\n';
    return 0;
}