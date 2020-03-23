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
    
//DP on Trees : Standard Problem

//No two adjacent vertices be painted black
//dp[i][0] : number of ways to paint ith vertex black
//dp[i][1] : number of ways to paint ith vertex white

//dp[i][0] = product of dp[child][1]
//dp[i][1] = product of (dp[child][0] + dp[child][1])


const int N = 1e5 + 10;

ll dp[N][2];
vi g[N];

inline void mul_self(ll &a, ll b){
    a *= b;
    a %= mod;
}

void dfs(int v, int p){

    dp[v][0] = 1ll, dp[v][1] = 1ll;

    for(int child : g[v]){
        if(child != p){
            dfs(child, v);
            mul_self(dp[v][0], dp[child][1]);
            mul_self(dp[v][1], (dp[child][0] + dp[child][1])%mod);
        }
    }

  
}

int main(){
   IOS

   int n; cin>>n;

   for(int i = 0; i < n-1; i++){
       int u, v;
       cin>>u>>v; u--, v--;

       g[u].pb(v), g[v].pb(u);
   }



   dfs(0, -1);


    cout<<(dp[0][0] + dp[0][1])%mod<<"\n";

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

