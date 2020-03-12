#include<bits/stdc++.h>

using namespace std;
#define IOS cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;

#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9+7;

const int hax = 1005;
char a[hax][hax];
int dp[hax][hax];

void add_self(int & a, int b){
    a += b;
    if(a >= mod)
         a-=mod;
}



int main(){
    IOS

    int h, w; cin>>h>>w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 1; i <= h; i++){
        if(a[i][1] != '#')
            dp[i][1] = 1;
        else break;
    }

    for(int i = 2; i <= w; i++){
        if(a[1][i] != '#')
            dp[1][i] = 1;
        else break;
    }

    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            if(a[i][j] != '#'){
                if(a[i][j-1] != '#')
                    add_self(dp[i][j], dp[i][j-1]);
                if(a[i-1][j] != '#')
                    add_self(dp[i][j], dp[i-1][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }

    // for(int i = 1; i <= h; i++){
    //     for(int j =1; j <= w; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    

    
    cout<<dp[h][w]<<"\n";


    


    
}
