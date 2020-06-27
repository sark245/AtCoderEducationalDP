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
    
const int N = 5010;
ll dp[N][N];
 
 
int main(){
   IOS
 
    int n; cin>>n;
    
    vi a(n);
    for(int &x : a)cin>>x;
 
    memset(dp, 0, sizeof dp);
 
    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
        if(i != n-1){
            dp[i][i + 1] = max(a[i], a[i + 1]);
        }
    }
    
 
    for(int l = 3; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            ll x = a[i] + min(dp[i + 1][j-1], dp[i + 2][j]);
            ll y = a[j] + min(dp[i + 1][j-1], dp[i][j - 2]);
            dp[i][j] = max(x, y);   
        }
    }
 
    cout<<dp[0][n-1]<<"\n";
 
 
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
