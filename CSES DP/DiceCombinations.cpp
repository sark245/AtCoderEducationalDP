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
    
 
 
 
int main(){
   IOS
 
 
    int n; cin>>n;
 
    vi dp(n + 1);
    dp[0] = 1;
 
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 6; j++){
            if(i + j <= n){
                dp[i + j] += dp[i];
                if(dp[i + j] >= mod)dp[i + j] -= mod;
            }
        }
    }
    cout<<dp[n]<<"\n";
 
 
 
 
 
 
 
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
