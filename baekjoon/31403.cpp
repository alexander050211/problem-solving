#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<a+b-c<<endl;
    ll n=0, bb=b;
    while(bb)
    {
        n++;
        bb/=10;
    }
    cout<<(ll)(a*pow(10,n)+b-c)<<endl;
    return 0;
}