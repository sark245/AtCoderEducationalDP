//
// Created by sark2 on 17-07-2019.
//
 
#include "bits/stdc++.h"
 
using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
typedef long long ll;
#define mod 1000000007
ll solve(vector<vector<int>>&a, int m , int n){
 
    ll dp[m][n];
    memset(dp,0,sizeof dp);
 
    for(int i = m-1; i >= 0; i--){
        if(a[i][n-1] == 0) dp[i][n-1] = 1;
        else{
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(a[m-1][i] == 0) dp[m-1][i] = 1;
        else{
            break;
        }
    }
 
    for(int i = m-2; i >=0; i--){
        for(int j = n-2; j >=0; j--){
            if(a[i+1][j] != -1){
                dp[i][j] += dp[i+1][j]%mod;
            }
            if(a[i][j+1] != -1){
                dp[i][j] += dp[i][j+1]%mod;
            }
            dp[i][j]%=mod;
        }
    }
    return dp[0][0];
 
}
 
int main() {
    IOS
 
    int m,n;
    cin>>m>>n;
    char c;
    vector<vector<int>>a(m,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>c;
            if(c =='#') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }
 
    cout<<solve(a,m,n);
 
 
}
