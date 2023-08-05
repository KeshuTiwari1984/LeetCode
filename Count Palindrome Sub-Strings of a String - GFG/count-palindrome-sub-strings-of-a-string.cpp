//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends

// recc(i, j) -> 1 if s[i..j] is a palindrome
int memo[510][510];
int rec(int l, int r, char s[])
{
    // base case
    if (l == r) return 1;
    if (r -l == 1)
    {
        if (s[l] == s[r]) return 1;
        return 0;
    }
    if (memo[l][r] != -1) return memo[l][r];
    
    if (s[l] == s[r]) return memo[l][r] = rec(l+1, r-1, s);
    return memo[l][r] = 0;
}

int CountPS(char S[], int N)
{
    memset(memo, -1, sizeof memo);
    int ans = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if (rec(i,j,S)) ans++;
        }
    }
    return ans;
}