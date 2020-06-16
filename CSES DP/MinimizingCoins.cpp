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
 
    int n, s; cin>>n>>s;
 
    vi a(n);
    for(int &x : a)cin>>x;
 
    //dp[i] = min(dp[i - coin] + 1)
 
    vi dp(s + 1);
 
    dp[0] = 0;
    
    for(int i = 1; i <= s; i++){
        dp[i] = 1e9;
        for(auto j : a){
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
 
    if(dp[s] == 1e9)cout<<-1;
    else cout<<dp[s]<<"\n";
 
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
