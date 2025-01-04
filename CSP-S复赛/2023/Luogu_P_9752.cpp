#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;

const int P = 10;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int n, cnt;
int a[10][10], dp[10][10][10][10][10];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    rep(i, 1, n)
        rep(j, 1, 5)
            cin >> a[i][j];
    rep(d, 1, 9){
        rep(i, 1, n){
            int n1 = a[i][1], n2 = a[i][2], n3 = a[i][3], n4 = a[i][4], n5 = a[i][5];
            ++dp[add(n1, d)][n2][n3][n4][n5]; 
            ++dp[n1][add(n2, d)][n3][n4][n5]; 
            ++dp[n1][n2][add(n3, d)][n4][n5]; 
            ++dp[n1][n2][n3][add(n4, d)][n5]; 
            ++dp[n1][n2][n3][n4][add(n5, d)]; 
            ++dp[add(n1, d)][add(n2, d)][n3][n4][n5];
            ++dp[n1][add(n2, d)][add(n3, d)][n4][n5];
            ++dp[n1][n2][add(n3, d)][add(n4, d)][n5];
            ++dp[n1][n2][n3][add(n4, d)][add(n5, d)];

        }
    }
    rep(n1, 0, 9)
        rep(n2, 0, 9)
            rep(n3, 0, 9)
                rep(n4, 0, 9)
                    rep(n5, 0, 9){
                        if(dp[n1][n2][n3][n4][n5] == n)
                            ++cnt;
                    }
    cout << cnt << '\n';
    return 0;
}