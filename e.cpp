#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;

const ll INFL = 1e18L+5;

void min_self(ll &a, ll b){
    a = min(a, b);
}

//dp[i] = Min wt that can be collected if the value 
//          of the Knapsack is 'i'

int main(){
    IOS

    int n, W;
    cin>>n>>W;

    int w[n+5], v[n+5];
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin>>w[i]>>v[i], sum+= v[i];
    }

    ll dp[sum+5];

    for(int i = 0; i <= sum; i++){
        dp[i] = INFL;
    }

    dp[0] = 0;
    for(int j = 0; j < n; j++){
        for(int i = sum-v[j]; i >= 0; --i){
            min_self(dp[i+v[j]], w[j] + dp[i]);
        }
    }

    int ans = -1;
    for(int i = sum; i >= 0 ; --i){
        if(dp[i]<= W){
            ans = i;
            break;
        }
    }

    cout<<ans<<"\n";


}
