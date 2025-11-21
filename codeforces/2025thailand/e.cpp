#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> line;
ll dist[105][105];
const ll INF=(ll)1e17;
vector<line> lines[10005];
vector<pll> q2s[105];
ll idxs[105];
string ans[100005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m,q;
  cin>>n>>m>>q;
  vector<ll> ps;
  vector<line> arr(m);
  for(int i=0; i<m; i++) {
    cin>>arr[i].F.F>>arr[i].F.S>>arr[i].S.F>>arr[i].S.S;
    ps.pb(arr[i].S.F);
  }
  sort(all(ps));
  ps.erase(unique(all(ps)),ps.end());
  for(auto& x:arr) x.S.F=lower_bound(all(ps),x.S.F)-ps.begin();
  for(auto x:arr) lines[x.S.F].pb(x);
  sort(all(arr),[&](const line& a,const line& b){
    return a.S.F<b.S.F;
  });
  for(int i=1; i<=n; i++)for(int j=1; j<=n; j++) dist[i][j]=(i==j)?0LL:INF;
  vector<pll> q1;
  vector<pair<pll,ll>> q2;
  for(int i=0; i<q; i++) {
    ll a,b,c;
    cin>>a>>b;
    if(a==1) {
      cin>>c;
      q2.pb({{b,c},i});
      q2s[b].pb({c,i});
      ans[i]="-1";
    } else {
      q1.pb({b,i});
      ans[i]="-1 -1";
    }
  }
  sort(all(q1),[&](const pll& a,const pll& b){
    return a.F>b.F;
  });
  sort(all(q2),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    return a.F.S>b.F.S;
  });
  for(int i=1; i<=n; i++) sort(all(q2s[i]),[&](const pll& a,const pll& b){
    return a.F>b.F;
  });
  ll idx1=0,idx2=0;
  for(int i=0; i<ps.size(); i++) {
    //add edges to floyd
    for(auto x:lines[i]) {
      for(int j=1; j<=n; j++)for(int k=1; k<=n; k++) {
        if(j==k) continue;
        dist[j][k]=min(dist[j][k],dist[j][x.F.F]+x.S.S+dist[x.F.S][k]);
      }
    }
    //q1
    priority_queue<pll> pq;
    vector<ll> temp(n+1,0);
    for(int j=1; j<=n; j++)for(int k=1; k<=n; k++) temp[j]=max(temp[j],dist[j][k]);
    for(int j=1; j<=n; j++) pq.push({-temp[j],-j});
    auto t=pq.top();
    while(idx1<q1.size() && -t.F<=q1[idx1].F) {
      ans[q1[idx1].S]=to_string(-t.S)+" "+to_string(ps[i]);
      idx1++;
    }
    //q2
    for(int j=1; j<=n; j++) {
      ll val=0;
      for(int k=1; k<=n; k++) val=max(val,dist[j][k]);
      while(idxs[j]<q2s[j].size() && val<=q2s[j][idxs[j]].F) {
        ans[q2s[j][idxs[j]].S]=to_string(ps[i]);
        idxs[j]++;
      }
    }
  }
  for(int i=0; i<q; i++) cout<<ans[i]<<endl;
  return 0;
}