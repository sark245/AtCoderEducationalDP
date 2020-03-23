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
    
const int N = 405;
const ll INF = 1e18L + 5;
ll dp[N][N];

//dp[i][j] = min cost to combine [i....j] segment into one


int main(){
   IOS

   int n; cin>>n;

   vector<ll> a(n);

   for(auto & i : a)cin>>i;

   for(int i = 0; i < n; i++)dp[i][i] = 0;

    auto sum = [&](int l, int r){
        ll res = 0;
        for(int i = l ; i <= r; i++)
            res += a[i];
        return res;
    };

    for(int i = 0; i < n; i++)dp[i][i] = 0;

   for(int l = 2; l <= n; l++){
       for(int i = 0; i < n-l+1; i++){
           int j = i + l- 1;
           ll s= sum(i,j);
           dp[i][j] = INF;
            for(int k = i; k < j; k++){
               dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s);
           }
       }
   }

   cout<<dp[0][n-1];



   

    







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

