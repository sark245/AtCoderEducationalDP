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

void add_self(int & a, int b){
    a += b;
    if(a>= mod)a-= mod;
}

//dp[i] = number of ways to do so with subset of women chosen is 
// represented using 'i'

int main(){
   IOS

    int n; cin>>n;

    int a[n+5][n+5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cin>>a[i][j];
        }
    }

    vi dp((1 << n));

    dp[0] = 1;

    for(int mask = 0; mask < (1 << n) - 1; ++mask){
        int cnt = __builtin_popcount(mask);

        for(int i = 0; i < n; i++){
            if(a[cnt][i] and !(mask & (1 << i))){
                int mask_new = (mask ^ (1 << i));
                add_self(dp[mask_new], dp[mask]);
            }
        }
    }

    cout<<dp[(1<<n)-1]<<"\n";








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

