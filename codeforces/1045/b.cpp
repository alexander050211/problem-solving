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
ll a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
void solve()
{
  ll n,k;
  cin>>n>>k;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<12; i++)
  {
    if(k%a[i]==0) continue;
    for(int j=0; j<n; j++)
    {
      while(arr[j]%a[i]) arr[j]+=k;
    }
    break;
  }
  for(int i=0; i<n; i++) cout<<arr[i]<<' ';
  cout<<endl;
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