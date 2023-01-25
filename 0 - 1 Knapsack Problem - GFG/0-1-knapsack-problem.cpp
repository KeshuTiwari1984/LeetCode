//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1001][1001];
    int n;
    
    int rec(int i, int left, int b[], int val[])
    {
    	if (i==n) return 0;
    
    	if (dp[i][left] != -1) return dp[i][left];
    
    	int op1 = 0, op2;
    	if (left-b[i] >= 0) op1 = val[i] + rec(i+1, left-b[i], b, val);
    
    	op2 = rec(i+1, left, b, val);
    	return dp[i][left] = max(op1, op2);
    }
    
    int knapSack(int W, int wt[], int val[], int N) 
    { 
       // Your code here
       n = N;
       memset(dp, -1, sizeof dp);
       return rec(0,W,wt,val);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends