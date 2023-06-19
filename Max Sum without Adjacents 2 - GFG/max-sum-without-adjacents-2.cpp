//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    
    // rec(i) -> max sum in [i...n]
    // p1 -> 1 if (i-1) was taken, p2 -> 1 if (i-2) was taken
    
    int findMaxSum(vector<int>& a){
        
        int n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2, 0)));
        
        for (int i=n-1; i>=0; i--)
        {
            for (int p1=0; p1<=1; p1++)
            {
                for (int p2=0; p2<=1; p2++)
                {
                    int cnt = 0;
                    if (p1 == 1) cnt++;
                    if (p2 == 1) cnt++;
                    
                    int op1 = -1e9;
                    if (cnt < 2)
                    {
                        op1 = a[i] + (i+1 < n ? dp[i+1][1][p1] : 0);
                    }
                    
                    int op2 = (i+1 < n ? dp[i+1][0][p1] : 0);
                    dp[i][p1][p2] = max(op1, op2);
                }
            }
        }
        
        return dp[0][0][0];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends