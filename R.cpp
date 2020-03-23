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

//Explanation is given here : https://cp-algorithms.com/graph/fixed_length_paths.html 

void add_self(int &a, int b){
    a += b;
    if(a>= mod)a-=mod;
}

int mul(int a, int b){
    return (ll)a*b%mod;
}

vector<vi> mul(const vector<vi>& A, const vector<vi>& B, int n){

    vector<vi> res(n,vi(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                add_self(res[i][j], mul(A[i][k],B[k][j]));
            }
        }
    }

    return res;
}

vector<vi> MatExp(ll K, int n, vector<vi> & A){

    vector<vector<int>>res(n,vi (n, 0));

    //Creating Identity Matrix of NxN size
    for(int i = 0; i < n ; i++)
        res[i][i] = 1;
        
    //Binary Exponentation
    while(K){
        if(K & 1ll)res = mul(res,A, n);
        A = mul(A,A,n);
        K >>= 1ll;
    }
    return res;
}


int main(){
   IOS

   int n; ll K;
   cin>>n>>K;

   vector<vi> A(n, vi(n,0));
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           cin>>A[i][j];
       }
   }


   vector<vi> res = MatExp(K, n, A);

   int ans = 0;



   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
                add_self(ans, res[i][j]);
       }
   }
   cout<<ans<<"\n";

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


