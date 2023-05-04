#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,p;
    cin>>a>>p;

    for(int i=0; i<a.size(); i++)
    {
        if(a.substr(i,i+p.size())==p)
        {
            a.erase(a.begin()+i,a.begin()+p);
        
        }
    }
}