//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int N=2e5;
vector<bool>isPrime(N+5,true);
class Solution {
  public:
    void Seive()
    {
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2; i*i<=N; i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i; j<=N; j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        
    }
    int countPrimes(int L, int R) {
        Seive();
        int count=0;
        for(int i=L; i<=R; i++)
        {
            if(isPrime[i])
            count++;
        }
        return count;
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends