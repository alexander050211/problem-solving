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
  ll n,k;
  cin>>n>>k;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  ll ans=0;
  vector<ll> brr(k);
  for(int i=0; i<k; i++) cin>>brr[i];
  sort(all(arr)); sort(all(brr));
  reverse(all(arr));
  ll idx=0;
  for(int i=0; i<k; i++)
  {
    if(idx+brr[i]-1>=n) break;
    ll t=brr[i];
    for(int j=0; j<t-1; j++) ans+=arr[idx+j];
    idx+=brr[i];
  }
  for(int i=idx; i<n; i++) ans+=arr[i];
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