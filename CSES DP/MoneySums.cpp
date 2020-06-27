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
   vi a(n);
   
   int sum = 0;
   for(int &x : a)cin>>x, sum += x;
 
    vector<bool> dp(sum + 1);
 
   
 
   dp[0] = dp[a[0]] = true;
 
    for(int i = 1; i < n; i++){
        vector<bool> new_dp = dp;
        for(int s = 0; s <= sum; s++){
            if(s >= a[i])
                new_dp[s] = new_dp[s] | dp[s - a[i]];
        }
        dp = new_dp;
    }
 
 
 
    vi res;
    for(int j = 1; j <= sum; j++){
        if(dp[j])res.pb(j);
    }
 
    cout<<res.size()<<"\n";
    for(auto i : res)cout<<i<<" ";
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
