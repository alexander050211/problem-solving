#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(1)
  {
    ll n;
    cin>>n;
    if(!n) return 0;
    ll ret=0;
    vector<ll> arr(n),brr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>brr[i];
    ll sa=arr[0],sb=brr[0];
    ll check=(sa==sb)?0:(sa>sb?1:2);
    for(int i=1; i<n; i++)
    {
      sa+=arr[i],sb+=brr[i];
      if(!check)
      {
        if(sa>sb) check=1;
        else if(sa<sb) check=2;
      }
      else if(check==1)
      {
        if(sa<sb) ret++,check=2;
      }
      else if(check==2)
      {
        if(sa>sb) ret++,check=1;
      }
    }
    cout<<ret<<endl;
  }
  return 0;
}