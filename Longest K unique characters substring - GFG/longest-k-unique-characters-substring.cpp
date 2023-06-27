//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int n = s.length();
        vector<int> mp(128, 0);
        int cnt = 0, r= 0, lans = -1, rans = -1;
        
        for (r=0; r<n; r++)
        {
            if (mp[s[r]] == 0)
            {
                mp[s[r]]++;
                cnt++;
            }
            else mp[s[r]]++;
            
            if (cnt == k+1) {
                mp[s[r]] = 0;
                r--;
                cnt -= 1;
                break;
            }
        }
        if (cnt == k)
        {
            lans = 0;
            rans = min(r, n-1);
        }
        
        if (lans == -1) return -1;
        
        for (int i=1; i<n; i++)
        {
            mp[s[i-1]]--;
            if (mp[s[i-1]] == 0) cnt--;
            
            while (r+1 < n and cnt <= k)
            {
                r++;
                if (mp[s[r]] == 0) 
                {
                    mp[s[r]]++;
                    cnt++;
                }
                else mp[s[r]]++;
            }
            
            if (cnt == k+1)
            {
                mp[s[r]]=0;
                r--;
                cnt--;
            }
        
            if (cnt == k)
            {
                if (r-i+1 > rans-lans+1)
                {
                    lans = i;
                    rans = r;
                }
            }
        }
        return rans-lans+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends