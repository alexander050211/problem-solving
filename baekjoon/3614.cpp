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
ll gcd(ll a,ll b)
{
  if(!b) return a;
  return gcd(b,a%b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  ll ans=0;
  for(int i=1; i<=n; i++)
  {
    if(n%i) continue;
    ll temp=n/i+1;
    for(int j=1; j<=temp/2; j++)if(gcd(j,temp-j)==1) ans++;
  }
  cout<<ans<<endl;
  return 0;
}