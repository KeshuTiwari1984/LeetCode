//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    #define vi vector<int>
    bool dfs_for_cycle(int x, vi G[], vi &color)
    {
        color[x] = 1;
        for (auto nb : G[x])
        {
            if (color[nb] == 0) 
            {
                bool ans = dfs_for_cycle(nb, G, color);
                if (ans == true) return true;
            }
            
            // if we encounter an already visited vertex
            else if (color[nb] == 1) return true;
        }
        color[x] = 2;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        
        bool ans = 0; vi color(v, 0);
        for (int i=0; i<v; i++)
        {
            if (color[i] == 0)
            {
                ans |= dfs_for_cycle(i, adj, color);
            }
        }
        return ans;
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