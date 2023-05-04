#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);

         transform(s.begin(),s.end(),s.begin(),::tolower);

         int l=0;
     int h=s.size()-1;
     while(l<h)
     {
         if(s[l]==' '){
            l++;
            continue;
         }
         if(s[h]==' ')
         {
            h--;
            continue;
         }
         if(s[l]!=s[h]){
            cout<<"NOt palindroem"<<endl;
            break;
         }
         l++;
         h--;
     }

    
    }
     cout<<"Palindrome"<<endl;
}