//
// Created by sark2 on 19-10-2019.
//

#include "bits/stdc++.h"

#define pb push_back
using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;
const int mod = 1e9 + 7;


void add_self(int& a, int b);

int main() {
    IOS

    string k;
    cin>>k;

    int d; cin>>d;

    int n = k.length();

    vector<vector<int>> dp(d, vector<int>(2));
    
    dp[0][0] = 1;

    for(int where = 0; where < n; ++where){
        vector<vector<int>>new_dp(d, vector<int>(2));
        for(int sum = 0; sum < d; ++sum){
            for(bool sm_already : {false, true}){
                for(int digit = 0; digit <= 9; ++digit){
                    if(digit > k[where]-'0' && !sm_already)
                        break;
                    add_self(new_dp[(sum+digit)%d][sm_already || (digit < k[where]-'0')], dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }

    int ans = (dp[0][false]+dp[0][true])%mod;
    --ans;
    if(ans == -1)
        ans += mod;

    cout<<ans<<"\n";




}

void add_self(int& a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
}
