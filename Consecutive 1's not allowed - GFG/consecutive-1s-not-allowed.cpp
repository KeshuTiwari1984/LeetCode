//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	#define ll long long
	ll countStrings(int n) {
	    
	    ll dp[n+1][2];
	    memset(dp, 0, sizeof dp);
	    
	    // dp[i][0] -> # of length i ending with 0
	    // dp[i][1] -> # of length i ending with 1
	    
	    // transitions : 
	    // dp[i][1] -> dp[i-1][0], we placed 1 at ith poition, then all the strings
	    //             ending at 0 of length (i-1) will contribute to dp[i][1]
	    // we made sure that string always contain < 2 consecutive 1's
	    
	    // dp[i][0] -> dp[i-1][1] + dp[i-2][0] + ... dp[0][0]
	    
	    // base case
	    dp[0][0] = 1;
	    ll pref = 1;
	    
	    for (int i=1; i<=n; i++)
	    {
	        dp[i][1] = dp[i-1][0];
	        dp[i][0] = pref;
	        pref = (dp[i][1] + pref) % 1000000007;
	    }
	    ll ans = (dp[n][0] + dp[n][1]) % 1000000007;
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends