//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    vector<vector<int>> dp;
    int rec(int i, int prevTaken, vector<vector<int>> &a)
    {
        // BC
        if (i==a.size()) return 0;
        
        if (dp[i][prevTaken + 1] != -1) return dp[i][prevTaken + 1];
        
        int op1 = 0;
        if (prevTaken == -1 or a[i][1] > a[prevTaken][1])
        {
            op1 = a[i][2] + rec(i+1, i, a);
        }
        
        int op2 = rec(i+1, prevTaken, a);
        return dp[i][prevTaken + 1] = max(op1, op2);
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
         vector<vector<int>> v;
         for (int i=0; i<n; i++)
         {
             vector<int> temp;
             temp.push_back(height[i]);
             temp.push_back(width[i]);
             temp.push_back(length[i]);
             sort(temp.begin(), temp.end());
             do
             {
                 v.push_back(temp);
             } while (next_permutation(temp.begin(), temp.end()));
         }
         
         sort(v.begin(), v.end(), [&](vector<int> &a1, vector<int> &a2) {
             if (a1[0] == a2[0]) return a1[1] > a2[1];
             return a1[0] < a2[0];
         });
         dp = vector<vector<int>> (v.size()+1, vector<int> (v.size()+1, -1));
         return rec(0,-1,v);
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends