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
ll sum[500005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,k,p,q;
  string s;
  cin>>n>>k>>p>>q>>s;
  for(int i=1; i<=n; i++) sum[i]=sum[i-1]+(s[i-1]=='Y');
  ll idx=k;
  ll cc=(ll)ceil((ld)k*p/q);
  ll ans=0;
  while(idx<=n)
  {
    while(idx<=n && sum[idx]-sum[idx-k]<cc) idx++;
    if(sum[idx]-sum[idx-k]>=cc) ans++;
    idx+=k;
  }
  cout<<ans<<endl;
  return 0;
}