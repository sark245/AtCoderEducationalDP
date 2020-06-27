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
    
const int inf = 1e9 + 100;
 
 
int main(){
   IOS
   int n; cin>>n;
   vi a(n);
   for(int &x : a)cin>>x;
   
   vi b(n, inf);
   int ans = 1;
 
   for(int i = 0; i < n; i++){
       int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
       b[idx] = a[i];
       ans = max(ans, idx + 1);
   }
   cout<<ans<<"\n";
 
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
