//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs_cycle(int x, int p, int par[], vector<int> g[], int color[])
    {
        if (color[x] == 2) return 0;
        if(color[x] == 1)
        {
            return true;
        }
        
        par[x] = p;
        color[x] = 1;
        for (auto nb:g[x])
        {
            // if (nb==p) continue;
            if (dfs_cycle(nb,x,par,g,color)) return 1;
        }
        color[x] = 2;
        return 0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int par[V], color[V];
        memset(color,0,sizeof color);
        for (int i=0; i<V; i++)
        {
            if (color[i] == 0)
            {
                if (dfs_cycle(i,-1,par,adj,color)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends