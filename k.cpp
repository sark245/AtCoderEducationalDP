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
    
//dp[i] - True if first player has i stones and wins the game


int main(){
   IOS


   int n, k; cin>>n>> k;

   vi a(n);
   for(int & x : a)cin>>x;

   vector<bool> dp(k+1, false);

    for(int stones = 0; stones <= k; stones++){
        for(int  i : a){
            if(stones - i >= 0 && !dp[stones-i])
                dp[stones] = true;
        }
    }



   cout<<(dp[k] ? "First" : "Second")<<"\n";















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

