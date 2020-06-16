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
 
    char a[n + 5][n + 5];
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
 
    int dp[n + 5][n + 5];
    memset(dp, 0, sizeof dp);
 
    dp[0][0] = a[0][0] != '*';
    
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0]; dp[0][i] = dp[0][i-1];
        if(a[i][0] == '*')dp[i][0] = 0;
        if(a[0][i] == '*')dp[0][i] = 0;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(a[i][j] == '*')dp[i][j] = 0;
            else{
                dp[i][j] += dp[i-1][j];
                if(dp[i][j] >= mod)dp[i][j] -= mod;
                dp[i][j] += dp[i][j-1];
                if(dp[i][j] >= mod)dp[i][j] -= mod;
            }
        }
    }
 
    cout<<dp[n-1][n-1]<<"\n";

 
 
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
