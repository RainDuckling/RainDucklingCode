#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
#define ls(p) p << 1
#define rs(p) p << 1 | 1
using namespace std;
typedef ll long long;

const int P = 998244353, N = 2e5 + 5;
inline int mod(int x) { return x + (x >> 31 & P); }
inline void pls(int &x, int y) { x = mod(x + y - P); }
inline void sub(int &x, int y) { x = mod(x - y); }
inline int  add(int x, int y) { return mod (x + y - P); }
inline int  dec(int x, int y) { return mod (x - y); }
template <typename T> inline void chmin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int n, m;
ll w[N], f[N];
vector<pair<int, int> > lnk[N];

//segment_tree
ll mx[N], tag[N];
#define ls(p) p << 1
#define rs(p) p << 1 | 1
void push_up(int p){
    mx[p] = max(mx[ls(p)], mx[rs(p)]);
}

void push_down(int p){
    t[ls(p)] = t[rs(p)] = t[p];
    mx[ls(p)] += t[p];
    mx[rs(p)] += t[p];
    t[p] = 0;
}

void build(int p, int l, int r){
    if(l == r){
        mx[p] = t[p] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void modify(int p, int cl, int cr, int x, int k){
    if(cl == cr){
        mx[p] = k;
        return ;
    }
    push_down(p);
    int mid = (cl + cr) >> 1;
    if(x <= mid)modify(ls(p), cl, mid, x, k);
    else modify(rs(p), mid + 1, cr, x, k);
}

void update(int p, int cl, int cr, int ul, int ur, int k){
    if(cl <= ul && cr >= ur){
        mx[p] += k;
        t[p] += k;
        return ;
    }
    push_down(p);
    int mid = (cl + cr) >> 1;
    if(ul <= mid)update(ls(p), cl, mid, ul, ur, k);
    if(ur > mid)update(rs(p), mid + 1, cr, ul, ur, k);
    push_up(p);
}

ll query(int p, int cl, int cr, int ql, int qr){
    if(ql <= cl && qr >= cr){
        return mx[p];
    }
    push_down(p);
    int mid = (cl + cr) >> 1, ret = 0;
    if(ql <= mid)ret += query(ls(p), cl, mid, ql, qr);
    if(qr > mid)ret += query(rs(p), mid + 1, cr, ql, qr);
    return ret;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //input
    cin >> n >> m;
    build(1, 0, n);
    rep(i, 1, n)cin >> w[i];
    rep(i, 1, m){
        int x, l, r;
        cin >> l >> r >> x;
        lnk[r].push_back( {l, x} );
    }
    f[0] = 0;
    rep(i, 1, n){
        for(auto [l, x] : lnk[i]){
            update(1, 0, n, 0, l - 1, x);
            //val[j + 1, i]
        }
        update(1, 0, n, 0, i - 1, -w[i]);
        //cost[j + 1, i]
        f[i] = query(1, 0, n, 0, i - 1);
        chmax(f[i], f[i - 1]);
        modify(1, 0, n, i, f[i]);
    }
    cout << f[n] << '\n';
    return 0;
}