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
ll mod = 1e9 + 7;
int n;

void add_self(int &a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
}

int mul(int a, int b)  {
    return (ll) a*b % mod;
}

struct M{
    vector<vector<int>>t;
    M(){
        t.resize(n,vector<int>(n));
    }
    M operator*(const M& b)const{
        M c = M();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    add_self(c.t[i][k], mul(t[i][j], b.t[j][k]));
                }
            }
        }
        return c;
    }
};

int main() {
    IOS

    cin>>n;
    ll k; cin>>k;

    vector<vector<int>>mat(n, vector<int>(n,0));

    for(auto &row : mat){
        for(auto& e : row){
            cin>>e;
        }
    }

    M ans = M();
    for(int i = 0; i < n; i++)
        ans.t[i][i]  = 1;

    M m = M();
    m.t = mat;

    while(k){
        if(k % 2 ){
            ans = ans*m;
        }
        m = m*m;
        k /= 2;
    }

    int total = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            add_self(total, ans.t[i][j]);
        }
    }

    cout<<total<<"\n";

}
