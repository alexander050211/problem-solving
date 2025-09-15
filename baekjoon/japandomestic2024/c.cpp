#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    if(!x) ans=llabs(y);
    else if(x>0)
    {
      if(y>=0) ans=x+y;
      else ans=max(x,-y);
    }
    else if(x<0)
    {
      if(y<=0) ans=-x-y;
      else ans=max(-x,y);
    }
    cout<<ans<<endl;
  }
  return 0;
}