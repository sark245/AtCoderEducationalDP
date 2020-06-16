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
    vi a(n);
    for(int &i: a)cin>>i;
 
    vi dp(x + 1);
    dp[0] = 1;
 
    for(int coin : a){
        for(int sum = 0; sum <= x; sum++){
            if(sum + coin <= x){
                dp[sum + coin] += dp[sum];
                if(dp[sum + coin] >= mod)
                    dp[sum + coin] -= mod;
            }
        }
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
