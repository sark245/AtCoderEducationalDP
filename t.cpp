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
const int nax = 3005;

int dp[nax][nax];
int n;

void add_self(int& a, int b);

int sub_mod(int a, int b){
    int ret = a-b;
    if(ret < 0)
        ret += mod;
    return ret;
}

int main() {
    IOS

    cin>>n;
    string s;
    cin>>s;

    dp[1][1] = 1;
    for(int l = 2; l <= n; l++){
        vector<int>pre(l+1);

        for(int i = 1; i <= l-1; ++i){
            pre[i] = (pre[i-1] + dp[l-1][i])%mod;
        }

        for(int b = 1; b <= l; b++){
            int L, R;
            if(s[l-2] == '<'){
                L = 1, R = b-1;
            }else{
                L = b, R = l-1;
            }

            if(L <= R){
                add_self(dp[l][b], sub_mod(pre[R], pre[L-1]));
            }
            
        }
    }

    int ans = 0;
    for(int b = 1; b <= n; b++)
        add_self(ans, dp[n][b]);

    cout<<ans;



}

void add_self(int& a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
}
