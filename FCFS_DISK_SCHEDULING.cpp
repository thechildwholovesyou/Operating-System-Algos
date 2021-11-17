#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t[20],n,tohm[20],tot=0;
    float avhm;

    cin>>n;
    for(int i=2;i<n+2;i++){
        cin>>t[;i]
    }
    for(int i=1;i<n+1;i++)
    {
        tohm[i]=t[i+1]-t[i];
        if(tohm[i]<0)
            tohm[i]=tohm[i]*-1;
    }
    for(int i=1;i<n;i++)
    {
        tot+=tohm[i];
    }
    avhm=(float)tot/n;

    cout<<avhm;

    return 0;
}