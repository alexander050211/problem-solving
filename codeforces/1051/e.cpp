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
struct Fenwick
{
  ll sz;
  vector<ll> bit;
  void init(ll x) { sz=x+1; bit.assign(sz+1,0); }
  void add(ll x,ll v)
  {
    ll temp=(v%mod+mod)%mod;
    for(int i=x+1; i<=sz; i+=i&-i)
    {
      bit[i]+=temp;
      if(bit[i]>=mod) bit[i]-=mod;
    }
  }
  inline ll sum(ll x)
  {
    if(x<0) return 0;
    ll ret=0;
    for(int i=x+1; i>0; i-=i&-i)
    {
      ret+=bit[i];
      if(ret>=mod) ret-=mod;
    }
    return ret;
  }
  ll query(ll l,ll r)
  {
    if(r<l) return 0;
    ll ret=sum(r)-sum(l-1);
    if(ret<0) ret+=mod;
    return ret;
  }
};
void solve()
{
  ll n;
  string s;
  cin>>n>>s;
  if(n%2)
  {
    cout<<-1<<endl;
    return;
  }
  ll cnt=0;
  for(int i=0; i<n; i++)if(s[i]=='(') cnt++;
  if((n/2 - cnt)%2)
  {
    cout<<-1<<endl;
    return;
  }
  ll sum=(s[0]=='(')?1:-1;
  for(int i=1; i<n; i++)
  {

  }
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