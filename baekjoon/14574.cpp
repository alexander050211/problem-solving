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
const ll mod=(ll)10007;
const ll INF=(ll)4e16;
bool adj[1005][1005];
vector<pll> arr;
ll cp[1005],deg[1005];
ll q[4005];
ll fin(ll x)
{
  if(cp[x]==x) return x;
  return cp[x]=fin(cp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  for(int i=0; i<n; i++) cp[i]=i;
  arr.resize(n);
  for(int i=0; i<n; i++) cin>>arr[i].F>>arr[i].S;
  priority_queue<pair<ll,pll>> pq;
  for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)
  {
    ll cost=(ll)floor((double)(arr[i].S+arr[j].S)/(llabs(arr[i].F-arr[j].F)));
    pq.push({cost,{i,j}});
  }
  ll ans=0;
  for(int i=1; i<n; i++)
  {
    pair<ll,pll> temp;
    while(!pq.empty())
    {
      temp=pq.top();
      pq.pop();
      if(fin(temp.S.F)!=fin(temp.S.S)) break;
    }
    ans+=temp.F;
    adj[temp.S.F][temp.S.S]=adj[temp.S.S][temp.S.F]=true;
    deg[temp.S.F]++; deg[temp.S.S]++;
    cp[fin(temp.S.F)]=fin(temp.S.S);
  }
  cout<<ans<<endl;
  ll st=0,en=0;
  for(int i=0; i<n; i++)if(deg[i]==1) q[en++]=i;
  while(st<en)
  {
    ll temp=q[st++];
    if(deg[temp]!=1) continue;
    ll temp2;
    for(int i=0; i<n; i++)if(adj[temp][i] && deg[i]) temp2=i;
    cout<<temp2+1<<' '<<temp+1<<endl;
    deg[temp]--; deg[temp2]--;
    if(deg[temp2]==1) q[en++]=temp2;
  }
  return 0;
}