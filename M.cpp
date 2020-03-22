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
    

void add_self(int &a, int &b){
    a += b;
    if(a >= mod)
        a-=mod;
}

void sub_self(int& a, int &b){
    a -= b;
    if(a < 0)
        a += mod;
}

int n, k;

//dp[i] = Number of ways to share candies if i candies are distributed 
// so far.

int main(){
   IOS

   cin>>n>>k;

   vi dp(k+1);

    dp[0] = 1;
   for(int i = 0; i < n; i++){
       int up_to; cin>>up_to;

        vi helper(k+1);
        //O(k)
       for(int used = k; used >= 0; --used){
           int L = used + 1;
           int R = used + min(up_to , k - used);
           if(L <= R){
                add_self(helper[L], dp[used]);
                if(R+1 <= k)
                    sub_self(helper[R+1], dp[used]);
           }
       }
    //O(k)
       int prefix_sum = 0;
        for(int j = 0; j <= k; j++){
           add_self(prefix_sum,helper[j]);
           add_self(dp[j], prefix_sum);
       }
    }

    cout<<dp[k]<<"\n";
      
    //Time Complexity : O(nk)




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

