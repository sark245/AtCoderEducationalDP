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
 
   int n, x; cin>>n>>x;
 
   vi h(n), s(n);
   for(int &a : h)cin>>a;
   for(int &a : s)cin>>a;
   
 
    vi dp(x + 1);
 
    //dp[x] = max num of pages I can buy with amt = x
 
 
    for(int i = 0; i < n; i++){
        vi new_dp = dp;
        for(int amt = 0; amt <= x; amt++){
            if(amt >= h[i]){
                new_dp[amt] = max(dp[amt], s[i] + dp[amt - h[i]]);
            }
        }
        dp = new_dp;
    }
 
 
    cout<<dp[x]<<"\n";
 
 
 
 
 
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
 
