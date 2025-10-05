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
ll cp[2005],ppow[2005];
ll fin(ll x)
{
  if(cp[x]==x) return x;
  return cp[x]=fin(cp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) cp[i]=i;
  ppow[0]=1;
  for(int i=1; i<m; i++) ppow[i]=(ppow[i-1]*3)%mod;
  vector<pll> arr(m);
  for(int i=0; i<m; i++) cin>>arr[i].F>>arr[i].S;
  ll ans=0;
  for(int i=m-1; i>=0; i--)
  {
    auto temp=arr[i];
    if(fin(temp.F)==fin(temp.S)) continue;
    if(fin(0)==fin(temp.F) && fin(n-1)==fin(temp.S)) ans=(ans+ppow[i])%mod;
    else if(fin(0)==fin(temp.S) && fin(n-1)==fin(temp.F)) ans=(ans+ppow[i])%mod;
    else cp[fin(temp.F)]=fin(temp.S);
  }
  cout<<ans<<endl;
  return 0;
}