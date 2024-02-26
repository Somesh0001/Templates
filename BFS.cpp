vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int> vis(V, 0); 
        queue<int> q; 
        q.push(0); 
        vis[0] = 1; 
        vector<int> ans;  
        
        while (!q.empty()) 
        {
            auto node = q.front(); 
            q.pop(); 
            ans.push_back(node); 
            for (auto it : adj[node]) 
            {
                if (vis[it] == 0) 
                {
                    q.push(it); // Corrected line
                    vis[it] = 1;  
                }
            }
        }  
        return ans;  
    }