#include <bits/stdc++.h>
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
void solve()
{
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  ll st=0,en=n-1;
  for(int i=1; i<=n; i++)
  {
    if(arr[st]==i) st++;
    else if(arr[en]==i) en--;
    else
    {
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
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