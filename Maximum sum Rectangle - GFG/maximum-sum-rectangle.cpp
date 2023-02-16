//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int n, int m, vector<vector<int>> mat) {
        
        // we need to find the largest sum rectangle, so we'll fix
        // either height or width of the rectangle
        // let's say we fixed the width
        
        int ans = -1e7;
        for (int i=0; i<m; i++)
        {
            vector<int> cur_sum(n, 0);
            for (int j=i; j<m; j++)
            {
                // we have fixed the width of the rectangle
                // now for this fixed width, we need to find the
                // max possible length of the submatrix
                
                // for every row, calculate sum[i...j]
                // then we'll have n such sums and we need to find
                // then max sum subarray among these n sums
                
                vector<int> a, dp(n+1, -1e7);
                int sum = 0;
                for (int k=0; k<n; k++)
                {
                    cur_sum[k] += mat[k][j];
                    a.push_back(cur_sum[k]);
                }
                
                for (int k=1; k<=n; k++)
                {
                    dp[k] = max(dp[k-1]+a[k-1], a[k-1]);
                    ans = max(ans, dp[k]);
                }
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends