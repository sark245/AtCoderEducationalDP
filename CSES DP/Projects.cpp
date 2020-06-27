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
 
const int inf = 1e9 + 100;
ll pwr(ll a, ll b);
    
 
 
 
int main(){
   IOS
 
    int n; cin>>n;
    vector<pair<pii, int>> v(n);
    
    for(int i = 0; i < n; i++){
        cin>>v[i].first.first>>v[i].first.second>>v[i].second;
    }
 
    sort(all(v));
    v.pb({{inf, inf}, 0});
 
 
    vector<ll> dp(n + 1);
    dp[n] = 0;
 
    for(int i = n-1; i >= 0; --i){
        int lo = i + 1, hi = n, mid, j = n;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
 
            if(v[mid].first.first > v[i].first.second){
                j = mid;
                hi = mid - 1;
            }else 
                lo = mid + 1;
        }
 
        dp[i] = max(dp[i + 1], dp[j] + v[i].second);
    }
    cout<<dp[0]<<"\n";
 
 
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
