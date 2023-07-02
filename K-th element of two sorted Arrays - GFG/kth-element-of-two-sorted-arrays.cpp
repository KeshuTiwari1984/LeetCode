//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }
        
        int lo = max(0, k-m), hi = min(k, n);
        while (lo <= hi)
        {
            int mid = (lo+hi)/2;
            
            int l1 = (mid-1 >= 0 ? arr1[mid-1] : -1e9);
            int l2 = (k-mid-1 >= 0 ? arr2[k-mid-1] : -1e9);
            int r1 = (mid < n ? arr1[mid] : 1e9);
            int r2 = (k-mid < m ? arr2[k-mid] : 1e9);
            
            if (max(l1, l2) <= min(r1, r2)) return max(l1, l2);
            if (l1 > r2) hi = mid - 1;
            else lo = mid + 1;
        }
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends