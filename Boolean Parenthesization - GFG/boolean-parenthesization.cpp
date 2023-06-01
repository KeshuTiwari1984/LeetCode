//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // DP(l, r) -> # ways to paranthesise [l, r]
    // l and r must either be T or F
    int dp[110][110][2];
    int rec(int l, int r, int want, string &s)
    {
        // BC
        if (l==r)
        {
            if (s[l] == 'T' and want == 1) return 1;
            if (s[l] == 'F' and want == 0) return 1;
            return 0;
        }
        if (dp[l][r][want] != -1) return dp[l][r][want];
        int ans = 0;
        
        for (int mid=l+1; mid<r; mid++)
        {
            int cur = 0;
            if (s[mid]=='&') 
            {
                if (want == 1)
                    cur = (rec(l,mid-1,1,s) * rec(mid+1,r,1,s)) % 1003;
                else
                {
                    int op1 = (rec(l,mid-1,1,s) * rec(mid+1,r,0,s)) % 1003;
                    int op2 = (rec(l,mid-1,0,s) * rec(mid+1,r,1,s)) % 1003;
                    int op3 = (rec(l,mid-1,0,s) * rec(mid+1,r,0,s)) % 1003;
                    cur = (op1+op2+op3)%1003;
                }
            }
            else if (s[mid]=='|')
            {
                if (want == 1)
                {
                    int op1 = (rec(l,mid-1,1,s) * rec(mid+1,r,1,s)) % 1003;
                    int op2 = (rec(l,mid-1,0,s) * rec(mid+1,r,1,s)) % 1003;
                    int op3 = (rec(l,mid-1,1,s) * rec(mid+1,r,0,s)) % 1003;
                    cur = (op1+op2+op3)%1003;
                }
                else cur = (rec(l,mid-1,0,s) * rec(mid+1,r,0,s));
            }
            else if (s[mid]=='^')
            {
                if (want == 1)
                {
                    int op1 = (rec(l,mid-1,0,s) * rec(mid+1,r,1,s)) % 1003;
                    int op2 = (rec(l,mid-1,1,s) * rec(mid+1,r,0,s)) % 1003;
                    cur = (op1+op2)%1003;
                }
                else
                {
                    int op1 = (rec(l,mid-1,0,s) * rec(mid+1,r,0,s)) % 1003;
                    int op2 = (rec(l,mid-1,1,s) * rec(mid+1,r,1,s)) % 1003;
                    cur = (op1+op2)%1003;
                }
            }
            ans = (ans + cur) % 1003;
        }
        
        return dp[l][r][want] = ans;
    }

    int countWays(int N, string S){
        memset(dp, -1, sizeof dp);
        return rec(0,N-1,1,S);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends