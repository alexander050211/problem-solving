#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
const ll INF=(ll)1e9;
vector<pll> adj[100005];
vector<ll> aadj[100005];
void dijk(vector<ll>& dist,ll st)
{
  dist[st]=0;
  priority_queue<pll> pq;
  pq.push({0,st});
  while(!pq.empty())
  {
    auto temp=pq.top();
    pq.pop();
    ll cost=-temp.F,idx=temp.S;
    for(int i=0; i<adj[idx].size(); i++)
    {
      ll nxt=adj[idx][i].F,ncost=adj[idx][i].S;
      if(dist[nxt]<=cost+ncost) continue;
      dist[nxt]=cost+ncost;
      pq.push({-dist[nxt],nxt});
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  for(int i=0; i<m; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    adj[a-1].pb({b-1,c}); adj[b-1].pb({a-1,c});
  }
  vector<ll> dist1(n,INF);
  vector<ll> dist2(n,INF);
  dijk(dist1,0); dijk(dist2,n-1);
  vector<ll> brr;
  brr.pb(n-1);
  if(dist1[n-1]>=INF)
  {
    cout<<-1<<endl;
    return 0;
  }
  while(brr.back())
  {
    ll idx=brr.back();
    for(auto [x,y]:adj[idx])if(dist1[x]+y==dist1[idx])
    {
      aadj[x].pb(idx); aadj[idx].pb(x);
      brr.pb(x);
      break;
    }
  }
  for(int i=0; i<n; i++)sort(all(aadj[i]));
  ll ans=INF;
  for(int i=0; i<n; i++)for(int j=0; j<adj[i].size(); j++)if(!binary_search(all(aadj[i]),adj[i][j].F))
    ans=min(ans,dist1[n-1]+adj[i][j].S+min(dist1[i]+dist2[adj[i][j].F],dist2[i]+dist1[adj[i][j].F]));
  if(ans<INF) cout<<ans<<endl;
  else cout<<-1<<endl;
  return 0;
}