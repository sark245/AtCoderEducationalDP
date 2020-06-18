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
    
const int N = 510;
int cache[N][N];
 
int dp(int a, int b){
    if(a == b)return 0;
    
    int &res = cache[a][b];
 
    if(res > 0)return res;
 
    if(a > b)swap(a, b);
 
    res = 1e9;
 
    for(int i = 1; i <= a; i++){
        res = min(res, 1 + dp(a,i) + dp(b-i, a));
    }
 
    for(int i = 1; i <= a; i++){
        res = min(res, 1 + dp(b, i) + dp(a - i, b));
    }
   
 
 
    return res;
}
 
 
 
int main(){
   IOS
 
    int a,b; cin>>a>>b;
    memset(cache, -1, sizeof cache);
 
    cout<<dp(a, b)<<"\n";
 
 
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
