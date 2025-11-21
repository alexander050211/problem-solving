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
  vector<pll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i].F;
  for(int i=0; i<n; i++) cin>>arr[i].S;
  for(int i=0; i<n; i++)if(arr[i].F>arr[i].S)
  {
    cout<<-1<<endl;
    return;
  }
  sort(all(arr));
  vector<ll> brr(n);
  for(int i=0; i<n; i++) brr[i]=arr[i].S-arr[i].F;
  for(int i=1; i<n; i++)if(brr[i-1]>brr[i])
  {
    cout<<-1<<endl;
    return;
  }
  cout<<brr[n-1]<<endl;
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