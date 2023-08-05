//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int mod = 1e9+7;
vector<vector<int>> dp;
class Solution{
public:
    
    long long rec(int i, int sumSoFar, int n, int sum)
    {
        // base case
        if (i==n) 
        {
            if (sumSoFar == sum) return 1;
            return 0;
        }
        if (dp[i][sumSoFar] != -1) return dp[i][sumSoFar];
        
        long long ans = 0;
        for (int dig=0; dig<=9; dig++)
        {
            if (i==0 and dig == 0) continue;
            if (sumSoFar + dig <= sum)
                ans = (ans + rec(i+1, sumSoFar+dig, n, sum)) % mod;
        }
        return dp[i][sumSoFar] = ans;
    }

    long int countWays(int n, int Sum){
        dp.clear(); dp.resize(n+1, vector<int> (Sum + 1, -1));
        int ans = rec(0, 0, n, Sum);
        return ans > 0 ? ans : -1;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, Sum;
        cin>>n>>Sum;
        
        Solution ob;
        cout<<ob.countWays(n, Sum)<<endl;
    }
    return 0;
}
// } Driver Code Ends