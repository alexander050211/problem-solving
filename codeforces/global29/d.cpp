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
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  map<ll,ll> mp;
  for(auto x:arr) mp[x]++;
  priority_queue<pll> pq;
  for(auto& x:mp) pq.push({x.S,-x.F});
  ll ans1=0,ans2=0;
  bool check=true;
  while(!pq.empty())
  {
    auto temp=pq.top(); pq.pop();
    ll cnt=temp.F,v=-temp.S;
    auto pos=mp.find(v);
    if(pos==mp.end() || pos->S!=cnt) continue;

    ll idx=0,midx=0;
    auto it=mp.lower_bound(v);
    if(it!=mp.begin())
    {
      auto pr=prev(it);
      idx=pr->F;
      midx=pr->S;
    }
    if(idx>0 && midx>=cnt)
    {
      pq.push(temp);
      continue;
    }
    ll cc=v-idx;
    ll ta=cnt*((cc+1)/2);
    ll tb=cnt*(cc/2);
    if(check) ans1+=ta,ans2+=tb;
    else ans1+=tb,ans2+=ta;
    if(cc%2) check=!check;
    mp.erase(pos);
    if(idx>0)
    {
      ll nxt=cnt+mp[idx];
      mp[idx]=nxt;
      pq.push({nxt,-idx});
    }
  }
  cout<<ans1<<' '<<ans2<<endl;
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