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
    
const int N = 2e5+5;

ll dp[N];

const ll INF = 1e18+5;

//dp[i] = max possible sum of beauties if last i taken is ith

int n;

//Template for Segment Tree
ll T[2*N];

void build(){
    //From n to 2*n-1 we have the array values
    //We basically create the rest of the tree in [0,n-1]

    for(int i = n-1; i >= 0; --i){
        T[i] = max(T[i<<1], T[i<<1 | 1]);
    }
}

void modify(int p, ll val){
    //p+=n is done to make the p reach it's real location in Tree
    for(T[p+=n]= val; p > 1; p >>= 1){
        T[p>>1] = max(T[p],T[p^1]);
    }
}

//Answer the query on [l,r)
ll query(int l, int r){
    ll res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1)res= max(res,T[l++]);//If l is odd it is the right child and it is added, left child isn't
                                    //added bcoz it's parent will be included
        if(r&1)res= max(res, T[--r]);   //If this is right child it is not added but it's left node is a parent node
                                        //and thus added
    }
    return res;
}

//*******************************************


int main(){
   IOS

    cin>>n;

   vi h(n), a(n);

   for(int & x : h)cin>>x, x--;
   for(int & x : a)cin>>x;


    for(int i  = 0; i < n; i++){ 
        ll best = query(0, h[i]);
        dp[h[i]] = best + a[i];
        modify(h[i], dp[h[i]]);
    }

    ll ans = 0;
   for(int i = 0; i <= n; i++){
       ans = max(ans, dp[i]);
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

