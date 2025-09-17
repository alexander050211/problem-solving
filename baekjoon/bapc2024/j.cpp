#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll a[105],b[105];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
  ll ta=a[1],tb=b[1];
  for(int i=2; i<=n; i++)
  {
    if(a[i]<ta || b[i]<tb)
    {
      cout<<"no";
      return 0;
    }
    ta=a[i],tb=b[i];
  }
  cout<<"yes";
  return 0;
}