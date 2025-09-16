#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> adj[200005];
ll arr[200005],brr[200005];
ll q[200005],st,en;
ll cnt[30];
ll nck[35][35];
ll ccnt[200005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b); adj[b].push_back(a);
  }
  ll k=0;
  while((ll)pow((ll)2,k)<n) k++;
  if(n!=(ll)pow(2,k)) { cout<<"no"; return 0; }
  if(2*m!=n*k) { cout<<"no"; return 0; }
  for(int i=1; i<=n; i++)if(adj[i].size()!=k) { cout<<"no"; return 0; }
  for(int i=1; i<=k; i++)for(int j=0; j<=i; j++)
  {
    if(!j || i==j)
    {
      nck[i][j]=1;
      continue;
    }
    nck[i][j]=nck[i-1][j]+nck[i-1][j-1];
  }
  arr[1]=1;
  q[en++]=1;
  for(int i=0; i<k; i++) brr[adj[1][i]]=(1<<i);
  while(st<en)
  {
    ll temp=q[st++];
    for(auto x:adj[temp])
    {
      if(arr[x]) continue;
      q[en++]=x;
      arr[x]=arr[temp]+1;
      if(brr[x]) continue;
      for(auto y:adj[x])if(brr[y]) brr[x]|=brr[y];
    }
  }
  for(int i=1; i<=n; i++)cnt[arr[i]]++;
  for(int i=1; i<=n; i++)ccnt[brr[i]]++;
  if(cnt[0]) { cout<<"no"; return 0; }
  for(int i=1; i<=k+1; i++)
  {
    if(cnt[i]!=nck[k][i-1])
    {
      cout<<"no";
      return 0;
    }
  }
  for(int i=0; i<n; i++)if(ccnt[i]!=1) { cout<<"no"; return 0; }
  for(int i=1; i<=n; i++)for(auto j:adj[i])
  {
    if(arr[j]!=arr[i]-1 && arr[j]!=arr[i]+1)
    {
      cout<<"no";
      return 0;
    }
  }
  cout<<"yes";
  return 0;
}