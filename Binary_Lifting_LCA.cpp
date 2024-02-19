#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000007;

int LOG, timer;

void binary_lift(vector<pair<int,int>> adj[], int u, int p,
vector<int> &in, vector<int> &out, vector<ll> &dis, vector<vector<int>>  &dp){
    dp[u][0] = p;
    for(int i=1; i<LOG; i++){
        int par = dp[u][i-1];
        if(par!=-1){
            dp[u][i] = dp[par][i-1];
        }
        if(dp[u][i]==-1){
            break;
        }
    }
    in[u] = timer++;
    for(auto it:adj[u]){
        int v = it.first;
        int w = it.second;
        if(v!=p){
            dis[v] = dis[u]+w;
            binary_lift(adj,v,u,in,out,dis,dp);
        }
    }
    out[u]=timer++;
}
bool is_ancestor(int u, int v, vector<int> &in, vector<int> &out){
    return (in[u]<in[v]) && (out[u]>=out[v]);
}
int LCA(int u, int v, vector<vector<int>>  &dp, vector<int> &in, vector<int> &out){
    if(is_ancestor(u,v,in,out)){
        return u;
    }
    if(is_ancestor(v,u,in,out)){
        return v;
    }
    else{
        int n = u;
        for(int i=LOG-1; i>=0; i--){
            if(dp[n][i]==-1){
                continue;
            }
            if(!is_ancestor(dp[n][i],v,in,out)){
                n = dp[n][i];
            }
        }
        return dp[n][0];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>  in(n+1,0);
    vector<int> out(n+1,0);
    vector<ll> dis(n+1,0);
    LOG = ceil(log2(n))+1;
    timer = 1;
    vector<vector<int>> dp(n+1,vector<int>(LOG,-1));
    binary_lift(adj,1,-1,in,out,dis,dp);
    int q;
    cin>>q;
    while(q--){
        ll u,v,w;
        cin>>u>>v>>w;
        int lca = LCA(u,v,dp,in,out);
        ll ans = dis[u]+dis[v]-(2*dis[lca])+(1ll*w);
        cout<<ans<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}