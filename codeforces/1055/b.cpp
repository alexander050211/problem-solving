#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
void solve()
{
  ll n;
  cin>>n;
  ll x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  ll ans1=1,ans2=1;
  if(x1<x2)
  {
    ans1=x1;
    ll dy=llabs(y1-y2);
    if(dy<=ans1) ans1=x2;
    else
    {
      if(y1<=y2) ans1+=max(x2-x1,y1);
      else ans1+=max(x2-x1,n-y1);
    }

  }
  else if(x1>x2)
  {
    ans1=n-x1;
    ll dy=llabs(y1-y2);
    if(dy<=ans1) ans1=n-x2;
    else
    {
      if(y1<=y2) ans1+=max(x1-x2,y1);
      else ans1+=max(x1-x2,n-y1);
    }
  }
  if(y1<y2)
  {
    ans2=y1;
    ll dx=llabs(x1-x2);
    if(dx<=ans2) ans2=y2;
    else
    {
      if(x1<=x2) ans2+=max(y2-y1,x1);
      else ans2+=max(y2-y1,n-x1);
    }
  }
  else if(y1>y2)
  {
    ans2=n-y1;
    ll dx=llabs(x1-x2);
    if(dx<=ans2) ans2=n-y2;
    else
    {
      if(x1<=x2) ans2+=max(y1-y2,x1);
      else ans2+=max(y1-y2,n-x1);
    }
  }
  cout<<max(ans1,ans2)<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}