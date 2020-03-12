#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;

#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9+7;

const int N = 3005;

//dp[i] = probability that there are i heads out of some number of tosses

//There seems to be two states on the first look
// which are num_heads and num_tails
//but num_tails = num_tosses - num_heads
//Therefore, dp[i] = p_head * dp[i-1] + (1-p_head) * dp[i]
//ie. now we need only one state


 
int main(){
   IOS

   int n; cin>>n;

   vector<double> dp(N);

   dp[0] = 1;

   for(int coin  = 0; coin < n; ++coin){
       double p_heads;
       cin>>p_heads;

    
       for(int i  = coin + 1; i >= 0; --i){
           dp[i] = (i==0 ? 0 : dp[i-1])*p_heads + dp[i]*(1-p_heads);
       }
   }

   double ans = 0.0;
   for(int h = 0; h <= n; h++){
       int t = n-h;
       if(h > t){
           ans += dp[h];
       }
   }

   printf("%.10lf\n", ans);



   
}
