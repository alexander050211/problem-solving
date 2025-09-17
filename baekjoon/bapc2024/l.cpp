#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
ll n,m,tt;
typedef pair<pll,pll> road;//b l v1 v2
vector<road> adj[100005];
ld dist[100005];
const ld INF=(ld)1e17;
void dijk()
{
  priority_queue<pair<ld,ll>> pq;
  pq.push({0,1});
  while(!pq.empty())
  {
    auto temp=pq.top();
    pq.pop();
    ld cost=-temp.F;
    ll x=temp.S;
    if(dist[x]<cost) continue;
    for(int i=0; i<adj[x].size(); i++)
    {
      ll nxt=adj[x][i].F.F;
      ll len=adj[x][i].F.S;
      pll v=adj[x][i].S;
      ld ncost=0;
      if(cost>=tt) ncost=(ld)len/v.S;
      else if(cost+(ld)len/v.F>=tt)
      {
        ncost=tt-cost;
        ncost+=(ld)(len-(tt-cost)*v.F)/v.S;
      }
      else ncost=(ld)len/v.F;
      if(dist[nxt]>cost+ncost)
      {
        dist[nxt]=(ld)cost+ncost;
        pq.push({-dist[nxt],nxt});
      }
    } 
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cout<<setprecision(11);
  cin>>n>>m>>tt;
  for(int i=0; i<m; i++)
  {
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    adj[a].pb({{b,c},{d,e}});
    adj[b].pb({{a,c},{d,e}});
  }
  for(int i=1; i<=n; i++) dist[i]=INF;
  dist[1]=0;
  dijk();
  cout<<dist[n]<<endl;
  return 0;
}