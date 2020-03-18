//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    
const int nax = 305;
 double p[nax][nax][nax], ev[nax][nax][nax];

//p[a][b][c] - P-bability to go to (a, b, c) state
//ev[a][b][c] : Expected number of operations to get to this state

int main(){
   IOS

   int n; cin>>n;

    vi cnt(4);
   for(int i = 0; i < n; i++){
       int x; cin>>x;
       cnt[x]++;
   }

   //Initial State = (cnt[1], cnt[2], cnt[3])

    p[cnt[1]][cnt[2]][cnt[3]] = 1.0;
   for(int c = n; c >= 0; --c){
       for(int b = n; b >= 0; --b){
           for(int a = n; a >= 0; --a){
               
               if(a==0 and b == 0 and c ==0)
                    continue;
                if(a+b+c > n)   continue;

               double p_waste = (double)(n-a-b-c)/n;

               double ev_waste = 1 / (1 - p_waste );

               ev[a][b][c] += ev_waste * p[a][b][c];

                //remove 1 --> dp[a-1][b][c]

               if(a != 0){
                   double p_go = (double)a / (a+b+c);
                   p[a-1][b][c] += p[a][b][c] * p_go;
                   ev[a-1][b][c] += ev[a][b][c] * p_go;
               }
               
               if(b != 0){
                   double p_go = (double) b/ (a+b+c);
                   p[a+1][b-1][c] += p[a][b][c] * p_go;
                   ev[a+1][b-1][c] += ev[a][b][c]*p_go;
               }

               //Remove 3 -> dp[a][b+1][c-1]
               if(c != 0){
                   double p_go = (double)c / (a+b+c);
                   p[a][b+1][c-1] += p[a][b][c]*p_go;
                   ev[a][b+1][c-1] += ev[a][b][c] * p_go;
               }
            }
       }
   }

   cout<<fixed<<setprecision(10)<<ev[0][0][0]<<"\n";





  



}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

