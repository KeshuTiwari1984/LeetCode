//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int r = 0, ans = 0, cur_sum = 0;
        for (r=0; r<n; r++)
        {
            cur_sum += arr[r];
            if (cur_sum > x)
            {
                ans = r+1;
                break;
            }
        }
        
        // smallest subarry with sum > x starting at index i
        for (int i=1; i<n; i++)
        {
            cur_sum -= arr[i-1];
            while (cur_sum <= x and r+1 < n)
            {
                r++;
                cur_sum += arr[r];
            }
            if (cur_sum > x) ans = min(ans, r-i+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends