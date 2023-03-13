//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        const int inf = 1e9;
        vector<int> d(n, 1e9), mark(n, 0);
        d[S] = 0;
        
        for (int i=0; i<n; i++)
        {
            int mind = inf, v;
            for (int j=0; j<n; j++)
            {
                if (mark[j]==0 and d[j]<mind)
                {
                    mind = d[j];
                    v = j;
                }
            }
            mark[v] = 1;
            for (int j=0; j<adj[v].size(); j++)
            {
                d[adj[v][j][0]] = min(d[adj[v][j][0]], d[v]+adj[v][j][1]);
            }
        }
        return d;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends