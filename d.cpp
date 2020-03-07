#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;


//dp[i][j] - max value obtained if Taro picks
//    'j' weight in total and has the options of item numbers
//     [0, i]

ll dp[105][(int)1e5+10];


int main(){
    IOS

    int n, W;
    cin>>n>>W;

    vector<ll> w(n), v(n);

    memset(dp, 0ll, sizeof dp);
    

    for(int i = 0; i < n; i++){
        cin>>w[i]>>v[i];
    }

    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(j >= w[i-1])
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][W]<<"\n";

    
    
}
