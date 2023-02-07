//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	typedef long long ll;

	public:
	long long maxProductSubarrayOfSizeK(int a[], int n, int k) 
	{
	    vector<int> sign(n, 0);
	    for (int i=0; i<n; i++)
	    {
	        if (a[i] > 0) sign[i] = 1;
	        if (a[i] < 0) sign[i] = -1;
	    }
	    vector<pair<int, int>> vp;
	    for (int i=0; i<n; i++)
	    {
	        vp.push_back({abs(a[i]), i});
	    }
	    sort(vp.begin(), vp.end());
	    
	    int sz = k, lst_neg=-1, lst_pos=-1, st, fst_neg = -1;
	    ll ans = 1;
	    ll ans1 = -1e8, ans2 = -1e8, ans3 = -1e8;
	    
	    // 1 -1 2 -3 -4 -6
	    
	    for (int i=n-1; i>=0; i--)
	    {
	        if (sz == 0) break;
	        ans *= vp[i].first * sign[vp[i].second];
	        sz--;
	        if (sign[vp[i].second] == -1) 
	        {
	            lst_neg = vp[i].second;
	            if (fst_neg == -1) fst_neg = vp[i].second;
	        }
	        if (sign[vp[i].second] == 1) lst_pos = vp[i].second;
	        st = i;
	    }
	    
	    // remove the smallest -ve and replace with maxn pos left
	    // or remove smallest +ve and replace it with maxn neg left
	    // or if both not available, then remove biggest -ve with 
	    // smallest -ve left
	    
	    if (ans < 0)
	    {
	        int mn = -1e8, maxn = -1e8, mnn = 1e8;
	        for (int i=st-1; i>=0; i--)
	        {
	            if (sign[vp[i].second] == -1) 
	            {
	                mn = max(mn, vp[i].first);
	                mnn = min(mnn, vp[i].first);
	            }
	            else maxn = max(maxn, vp[i].first);
	        }
	        
	        if (maxn != -1e8 and lst_neg != -1) 
    	    {
    	        ans1 = ans;
    	        ans1 /= a[lst_neg];
    	        ans1 *= maxn;
    	    }
    	    if (mn != -1e8 and lst_pos != -1)
    	    {
    	        ans2 = ans;
    	        ans2 /= a[lst_pos];
    	        ans2 *= -mn;
    	    }
    	    
    	    if (mnn != 1e8)
    	    {
    	        ans3 = ans/a[fst_neg];
    	        ans3 *= -mnn;
    	    }
	    }
	    
	    ll res = max(max(ans, ans3), max(ans1, ans2));
	    return res;
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
        cin>>n;
        int k;
        cin>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];

        

        Solution ob;
        cout<<ob.maxProductSubarrayOfSizeK(a,n,k);
        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends