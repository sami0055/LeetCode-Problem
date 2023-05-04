#include<bits/stdc++.h>
using namespace std;
int len(char name[])
{
    int i=0;
    int c=0;
    while(name[i]!='\0')
    {
        c++;
        i++;

    }
    return c;
}
void reversechar(char name[],int n)
{
    int l=0;
    int h=n-1;
    while(l<h)
    {
        swap(name[l],name[h]);
        l++;
        h--;
    }

}
int main()
{
    char name[20];

    cin>>name;
    int n=len(name);
    cout<<len(name)<<endl;

    reversechar(name,n);
    cout<<name<<endl;

    
}