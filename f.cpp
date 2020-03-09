#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;


// dp[i][j] = longest common subsequence in 1...i and 1...j


int dp[3005][3005];

int main(){
    IOS

    string s, t;
    cin>>s>>t;

    int n = s.length(), m = t.length();

    memset(dp, 0 , sizeof dp);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // for(int i = 0; i <=n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }


    stack<char> ans;

    
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans.push(s[i-1]);
            i--, j--;
        }else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }

    cout<<endl;

}
