//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    string s, t;
    int n, m;
    const int mod = 1e9+7;
    
    int add(int x, int y) { int res = x + y; return (res >= mod ? res - mod : res); }
    
    int dp[8001][103];
    
    // distinct occ in [i...n] if we have matched j-1 characters of T till now
    int rec(int i, int j)
    {
        // base case
        if (j==m) return 1;
        if (i==n) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j])
        {
            return dp[i][j] = add(rec(i+1, (j+1)%(m+1)), rec(i+1, j));
        }
        
        return dp[i][j] = rec(i+1, j);
    }
    
    int subsequenceCount(string S, string T)
    {
        s = S, t = T; n = s.length(), m = t.length();
        memset(dp, -1, sizeof dp);
        int ans = rec(0,0);
        return ans;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends