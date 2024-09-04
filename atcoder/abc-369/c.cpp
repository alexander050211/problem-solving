#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    ll ans=1;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    ll idx=0;
    ll temp=1;
    ll d=arr[1]-arr[0];
    while(idx<n)
    {
        while(idx+temp<n && arr[idx+temp]-arr[idx+temp-1]==d) temp++;
        ans+=temp*(temp+1)/2-1;

        idx+=temp-1;
        temp=1;
        if(idx+1==n) break;
        d=arr[idx+1]-arr[idx];
    }
    cout<<ans<<endl;
    return 0;
}