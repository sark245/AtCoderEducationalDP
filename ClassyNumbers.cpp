// https://codeforces.com/problemset/problem/1036/C

//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);

ll cache[20][5][3];

ll limit;
vi digs;

ll dp(int i, int cnt, bool sm_already){
    if(cnt > 3)return 0;
    if(i == digs.size()){
        if(cnt <= 3)return 1;
        return 0;
    }

    auto &res = cache[i][cnt][sm_already];
    if(res >= 0)return res;

    res = 0;
    int n; 
    if(sm_already){
        n = 9;
    }else{
        n = digs[i];
    }

     for(int dgt = 0; dgt<=n; dgt++){
        bool nf = sm_already;
        int ncnt = cnt;
        if(sm_already == 0 && dgt < n) nf = 1; /// The number is getting smaller at this position
        if(dgt > 0) ncnt++;
        if(ncnt <= 3) res += dp(i+1, ncnt, nf);
    }
    return res;
}

ll solve(ll r){
    limit = r;
    digs.clear();
    memset(cache, -1, sizeof cache);
    while(r){
        digs.pb(r % 10);
        r /= 10;
    }
    
    reverse(all(digs));

    return dp(0, 0, 0);
}


int main(){
   IOS
    ll l, r;
   int t; cin>>t;
   while(t--){
       cin>>l>>r;

       cout<<solve(r) - solve(l - 1)<<'\n';

   }
}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

