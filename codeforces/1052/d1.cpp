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
  ll a,b;
  cin>>a>>b;
  vector<ll> ans(b+1,0);
  ll msk=1;
  ll bb=b;
  while(2*msk+1<=2*b-1) msk=2*msk+1;
  while(msk)
  {
    ll st=msk-bb;
    for(int i=st; i<=bb; i++) ans[i]=msk-i;
    bb=st-1;
    if(bb<=0) break;
    while(msk>bb*2-1) msk>>=1;
  }
  ll sum=0;
  for(int i=0; i<=b; i++) sum+=(i|ans[i]);
  cout<<sum<<endl;
  for(int i=0; i<=b; i++) cout<<ans[i]<<' ';
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