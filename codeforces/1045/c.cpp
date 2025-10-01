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
  vector<ll> arr(n+2,0);
  for(int i=1; i<=n; i++) cin>>arr[i];
  ll ans=0;
  for(int i=2; i<=n; i+=2)
  {
    if(arr[i]<arr[i-1])
    {
      ans+=arr[i-1]-arr[i];
      arr[i-1]=arr[i];
    }
    if(arr[i]<arr[i-1]+arr[i+1])
    {
      ll temp=arr[i-1]+arr[i+1]-arr[i];
      ans+=temp;
      arr[i+1]-=temp;
    }
  }
  cout<<ans<<endl;
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