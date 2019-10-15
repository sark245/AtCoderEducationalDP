#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int nax = 2e5+10;
const  ll mod =  1e9+7;

const ll INFL = 1e18L + 5;

/*//Modular Addition
inline void add_self(ll& a, ll b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

//Modular Subtraction
inline void sub_self(int& a , int b){
    a -= b;
    if(a < 0)
        a+= mod;
}

inline void mul_self(ll& a, ll b){
    a *= b;
    if(a >= mod)
        a-= mod;
}*/

ll tree[4*nax];

void build(int v, int tl, int tr, ll a[]){
    if(tl == tr)
        tree[v] = a[tl];
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm, a);
        build(2*v+1, tm+1, tr, a);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }

}

ll best(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr){
        return tree[v];
    }
    int tm = (tl+tr)/2;
    return max(best(v*2, tl, tm, l, min(r,tm)),
            best(2*v+1, tm+1, tr, max(l,tm+1), r));
}

void update(int v, int tl, int tr, int pos, ll new_val){
    if(tl == tr)
        tree[v] = new_val;
    else{
        int tm = (tl+tr)/2;
        if(pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = max(tree[v*2], tree[2*v+1]);
    }
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    int h[n+5], a[n+5];

    for(int i = 1; i <= n; i++)cin>>h[i];
    for(int i = 1; i <= n; i++)cin>>a[i];

   ll dp[n+5];
   memset(dp,0,sizeof dp);

    build(1,1,n,dp);

    for(int flower = 1; flower <= n; flower++) {
        dp[h[flower]] = best(1, 1, n, 1, h[flower] - 1) + a[flower];
        update(1, 1, n, h[flower], dp[h[flower]]);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;


}
