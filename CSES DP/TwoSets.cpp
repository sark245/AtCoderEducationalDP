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
    
 
void add(int &a, int b){
    a += b;
    if(a >= mod)a -= mod;
}
 
int main(){
   IOS
 
     int n;
     cin>>n;
     //dp[i] number of ways to make the sum = i
 
     int sum = (n * (n + 1))/2;
     if(sum & 1){
         cout<<0<<"\n";
         return 0;
     }
     sum >>= 1;
 
     int dp[n + 1][sum + 1];
     memset(dp, 0, sizeof dp);
     dp[1][0] = dp[1][1] = 1;
 
    for(int i = 2; i <= n; i++){
        for(int s = 0; s <= sum; s++){
            dp[i][s] = dp[i-1][s];
            if(s >= i){
                add(dp[i][s], dp[i-1][s-i]);
            }
        }
    }
 
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= sum; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
 
    cout<<((ll)dp[n][sum] * pwr(2, mod - 2))%mod<<"\n";
 
 
 
 
 
 
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
