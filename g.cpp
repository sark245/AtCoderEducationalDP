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


const int N = 1e5+ 10;

vector<int> g[N];
int in_deg[N], dist[N];
bool visited[N];

void dfs(int v){
    visited[v] = true;

    for(int c : g[v]){
        dist[c] = max(dist[c], dist[v] + 1);
        --in_deg[c];
        if(in_deg[c] == 0){
            dfs(c);
        }
    }
}


int main(){
    IOS

    int n, m; cin>>n>>m;

    for(int i = 0; i < m; i++){
        int x, y; cin>>x>>y; 
        g[x].pb(y);
        ++in_deg[y];
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i] && in_deg[i]==0)
            dfs(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dist[i]);
    }


    cout<<ans<<"\n";



    
}
