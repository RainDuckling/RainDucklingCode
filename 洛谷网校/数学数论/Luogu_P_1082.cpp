#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; ++a)
using namespace std;
typedef long long ll;

ll x,y,tx;

void exgcd(ll a,ll b){
    if(b == 0){
        x = 1;
        y = 0;
        return ;
    }
    exgcd(b, a % b);
    tx = x;
    x = y;
    y = tx - a / b * y;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll a,b;
    cin >> a >> b;
    exgcd(a,b);
    x = (x % b + b) % b;
    cout << x << '\n';
    return 0;
}