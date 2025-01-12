#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;

const int P = 998244353;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    return 0;
}