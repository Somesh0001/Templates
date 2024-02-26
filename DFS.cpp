class Solution {
    public:
      // Function to return a list containing the DFS traversal of the graph. 
      void dfs(vector<int> adj[] , vector<int> &ans , int node , vector<int> &vis) 
      {
          if(vis[node] == 0) 
          {
              vis[node] = 1 ; 
              ans.push_back(node) ;  
              for(auto it : adj[node]) 
              {
                  if(!vis[it]) 
                  dfs(adj,ans,it,vis) ; 
              } 
          }  
      }
      vector<int> dfsOfGraph(int V, vector<int> adj[]) 
      {
          // Code here
          vector<int> ans ; 
          vector<int> vis(V , 0) ;  
          for(int i =0 ; i < V ; i ++) 
          {
              if (vis[i] == 0) 
              dfs(adj,ans,i,vis); 
          }  
          return ans  ;  
      }
  };