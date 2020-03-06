#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;


// dp[i] = min cost to go from ith stone to nth stone
// dp[i] = min(dp[j] + abs(h[i]-h[j])) for all j = i+1 to i+k

int main(){
    IOS

    int n, k; cin>>n>>k;

    vector<int> h(n);
    for(int & x: h)cin>>x;

    vector<int> dp(n,INT_MAX);
    
    dp[n-1] = 0;
    dp[n-2] = abs(h[n-2]-h[n-1]);

    for(int i = n-3; i >= 0; --i){
        for(int j = i+1; j < n && j-i <= k; j++){
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
        }
    }

    cout<<dp[0];

}
