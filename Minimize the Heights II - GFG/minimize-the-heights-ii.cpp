//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // we'll iterate over each element and consider it as the max element
        sort(arr, arr+n);
        // for (int i =0; i<n; i++) cout << arr[i] << ' '; cout << endl;
        int ans = 1e9;
        for (int i=n-1; i>=0; i--)
        {
            // check if it can be maximum or not
            // arr[i] + k
            if (i == n-1 or (arr[n-1]-k >= 0 and arr[n - 1] - k <= arr[i] + k))
            {
                int maxn = 0;
                if (i != 0)
                {
                    int cur = arr[i] + k - arr[0] - k;
                    maxn = max(maxn, cur);
                }
                // cout << i << ' ' << maxn << endl;
                if (i != n - 1)
                {
                    if (arr[i+1]-k >= 0)
                        maxn = max(maxn, abs(arr[i]+k - arr[i+1] + k));
                    else
                    {
                        // arr[i] + k cannot be maxima
                        break;
                    }
                }
                /                ans = min(ans, maxn);
            }
        }
        
        int maxn = 0;
        if (arr[n-1]-k >= 0)
        {
            for (int i=0; i<n-1; i++)
            {
                int mn = 1e9;
                if (arr[i]-k >= 0)
                    mn = min(mn, abs(arr[n-1] - k - arr[i] + k));
                else
                {
                    // arr[n-1] - k is no longer maxima
                    if (arr[i] + k > arr[n-1] - k) return ans;
                }
                if (arr[i] + k <= arr[n-1] - k)
                    mn = min(mn, abs(arr[n-1] - k - arr[i] - k));
                
                maxn = max(maxn, mn);
            }
            ans = min(ans, maxn);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends