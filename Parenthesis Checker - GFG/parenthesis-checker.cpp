//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
   bool isbalanced(char c1,char c2)
    {
        return (c1=='(' && c2==')') || (c1=='{' && c2=='}') || (c1=='[' && c2==']');
    }
    bool ispar(string s)
    {
         stack<char>st;
        for(auto c:s)
        {
            if(c=='{' || c=='(' || c=='[')st.push(c);
            else{
                if(st.empty())return false;
                else{
                    if(isbalanced(st.top(),c)){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(st.empty())return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends