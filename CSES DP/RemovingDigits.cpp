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
    
const int N = 1e6 + 10;
int cache[N];
 
int dp(int x){
    if(x == 0)return 0;
 
    int &res = cache[x];
    if(res > 0)
        return res;
 
    res = 1e9;    
    int temp = x;
    while(temp){
        int r = temp % 10;
        temp /= 10;
        res = min(res, dp(x - r) + 1);
    }
    return res;
}
 
 
int main(){
   IOS
 
   int n; cin>>n;
   memset(cache, -1, sizeof cache);
       
   
   cout<<dp(n)<<"\n";
 
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
