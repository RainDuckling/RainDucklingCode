#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
#define int long long
using namespace std;

const int P = 1e9 + 7, N = 2e5 + 5;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct edge{
    int to, nxt;
}e[N << 1];

int n, edge_cnt;
int head[N], siz[N], fact[N], f[N];

int qpow(int a, int k){
    int res = 1;
    while(k){
        if(k & 1)res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

int inv(int x){
    return qpow(x,P - 2);
}
void add_edge(int u, int v){
    e[++edge_cnt].to = v;
    e[edge_cnt].nxt = head[u];
    head[u] = edge_cnt;
}

void dfs(int v, int fa){
    siz[v] = 1;
    for(int i = head[v]; i; i = e[i].nxt){
        int to = e[i].to;
        if(to == fa)continue;
        dfs(to, v);
        siz[v] += siz[to];
    }
    f[1] = f[1] * siz[v] % P;
}

void dfs2(int v, int fa){
    for(int i = head[v]; i; i = e[i].nxt){
        int to = e[i].to;
        if(to == fa)continue;
        f[to] = (f[v] * (n - siz[to]) % P) * inv(siz[to]) % P;
        dfs2(to, v);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    fact[1] = 1;
    rep(i, 2, n){
        fact[i] = fact[i - 1] * i % P;
//        cerr << inv[i] << ' ' << fact[i] << '\n';
    }        
    rep(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    f[1] = 1;
    dfs(1, 0);
    dfs2(1, 0);
    rep(i, 1, n){
        /*cout << inv[f[i]] << ' ';
        */cout << fact[n] * inv(f[i]) % P << '\n';
    }
    return 0;
}