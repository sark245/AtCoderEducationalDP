#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;



int main(){ 
    IOS

    int n; cin>>n;
    vector<int> h(n);

    for(int &x : h)cin>>x;

    //dp[i] - min possible cost incurred to
    //         get to stone i, ans = dp[n]
    //dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]))

    int dp[n+5];

    dp[0] = 0;
    if(n >= 2){
        
        dp[1] = abs(h[1]-h[0]);

        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),
            dp[i-2]+abs(h[i]-h[i-2]));
        }

    }
    cout<<dp[n-1]<<"\n";
    

}
