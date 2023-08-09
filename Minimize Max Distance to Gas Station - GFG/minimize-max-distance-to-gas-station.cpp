//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k){
      int maxn = 0;
    	int n = arr.size();
    	for (int i=1; i<n; i++)
    	{
    		maxn = max(maxn, arr[i] - arr[i-1]);
    	}
    	double lo = 0.0, hi = 1.0*maxn; int iterations = 30;
    
    	while (hi - lo > 1e-6)
    	{
    		double mid = (lo + hi) / 2;
    		int leftK = k;
    		for (int i=1; i<n; i++)
    		{
    			int count = ceil(1.0 * (arr[i]-arr[i-1]) / mid) - 1;
    			leftK -= count;
    		}
    		if (leftK >= 0) hi = mid;
    		else lo = mid;
    	}
    	return hi + 0.000001;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends