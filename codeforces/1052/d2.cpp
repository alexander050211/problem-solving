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
typedef vector<ll>::iterator iter;
const ll mod=(ll)1e9+7;
vector<ll> ans;
ll lv;
void sol(iter p1,iter p2,iter q1,iter q2,ll k)
{
  if(p1==p2) return;
  ll pivot=k;
  while(pivot>=0)
  {
    bool check=(*p1>>pivot)&1LL;
    bool flag=false;
    for(auto it=p1; it!=p2; ++it)if(((*it>>pivot)&1LL)!=check) { flag=true; break; }
    if(flag) break;
    for(auto it=q1; it!=q2; ++it)if(((*it>>pivot)&1LL)!=check) { flag=true; break; }
    if(flag) break;
    pivot--;
  }
  if(pivot<0)
  {
    for(auto pit=p1,qit=q1; pit!=p2; ++pit,++qit) ans[*pit-lv]=*qit;
    return;
  }
  ll msk=1LL<<pivot;
  auto pmid=partition(p1,p2,[&](ll val){ return !(val&msk);});
  auto qmid=partition(q1,q2,[&](ll val){ return !(val&msk);});
  ll psz=distance(p1,pmid);
  ll qsz=distance(qmid,q2);
  if(psz==qsz)
  {
    sol(p1,pmid,qmid,q2,pivot-1);
    sol(pmid,p2,q1,qmid,pivot-1);
  }
  else
  {
    sol(p1,pmid,q1,qmid,pivot-1);
    sol(pmid,p2,qmid,q2,pivot-1);
  }
}
void solve()
{
  ll l,r;
  cin>>l>>r;
  lv=l;
  ll n=r-l+1;
  ans.assign(n,0);
  vector<ll> p(n),q(n);
  iota(all(p),l); iota(all(q),l);
  sol(all(p),all(q),29);
  ll sum=0;
  for(int i=0; i<n; i++) sum+=(ll)(l+i)|ans[i];
  cout<<sum<<endl;
  for(int i=0; i<n; i++) cout<<ans[i]<<' ';
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