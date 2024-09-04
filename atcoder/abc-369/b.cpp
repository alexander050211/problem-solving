#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    ll t1=-1,t2=-1;
    for(int i=0; i<n; i++)
    {
        ll x;
        char c;
        cin>>x>>c;
        if(c=='L')
        {
            if(t1!=-1) ans+=abs(t1-x);
            t1=x;
        }
        else
        {
            if(t2!=-1) ans+=abs(t2-x);
            t2=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}