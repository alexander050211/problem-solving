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
const ll mod=(ll)1e9+7;
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> arr(n);
  vector<ll> cnt(m+1,0);
  for(int i=0; i<n; i++)
  {
    ll x;
    cin>>x;
    arr[i].resize(x);
    for(int j=0; j<x; j++)
    {
      cin>>arr[i][j];
      cnt[arr[i][j]]++;
    }
  }
  for(int i=1; i<=m; i++)
  {
    if(cnt[i]) continue;
    cout<<"NO"<<endl;
    return;
  }
  ll count=0;
  for(int i=0; i<n; i++)
  {
    bool check=false;
    for(auto x:arr[i])if(cnt[x]==1) check=true;
    if(!check) count++;
  }
  if(count>=2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

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