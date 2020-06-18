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
    
 
inline void add(int &a, int b){
    a += b;
    if(a >= mod)a-= mod;
}
 
int main(){
   IOS
 
   int n, m; cin>>n>>m;
 
   vi a(n);
   for(int &x : a)cin>>x;
 
    //dp[i][j] = number of ways to get j at pos i
 
    int dp[n + 1][m + 1]; 
    memset(dp, 0, sizeof dp);
 
    if(a[0] == 0){
        for(int j = 1; j <= m; j++){
            dp[0][j] = 1;
        }
    }else{
        dp[0][a[0]] = 1;    
    }
 
    for(int i = 1; i < n; i++){
        if(a[i] != 0){
            int j = a[i];
            if(j != 1)add(dp[i][j], dp[i-1][j-1]);
            add(dp[i][j], dp[i-1][j]);
            if(j != m)add(dp[i][j], dp[i-1][j+1]);
        }else{
            for(int j = 1; j <= m; j++){
                if(j != 1)add(dp[i][j], dp[i-1][j-1]);
                add(dp[i][j], dp[i-1][j]);
                if(j != m)add(dp[i][j], dp[i-1][j+1]);
            }
        }
    }
 
 
    int ans = 0;
    for(int j = 1; j <= m; j++){
        add(ans, dp[n-1][j]);
    }
    cout<<ans<<"\n";
 
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
