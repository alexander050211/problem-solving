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
vector<ll> adj[300005];
vector<ll> arr,brr;
bool aadj[605][605];
bool check[300005];
ll aidx[300005];
vector<pll> aa,ab,bb;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  ll rm=(ll)2*floor(sqrt(m));
  for(int i=1; i<=m; i++) {
    ll a,b;
    cin>>a>>b;
    adj[a].pb(b); adj[b].pb(a);
  }
  for(int i=1; i<=n; i++) {
    sort(all(adj[i]));
    if(adj[i].size()>=rm) arr.pb(i),check[i]=true;
    else brr.pb(i);
  }
  sort(all(arr)); sort(all(brr));
  ll ans0=0,ans1=0,ans2=0,ans3=0;
  ll asz=arr.size(),bsz=brr.size();
  for(int i=1; i<=n; i++) aidx[i]=-1;
  for(int i=0; i<asz; i++) aidx[arr[i]]=i; 
  for(auto x:arr) {
    ll idx1=aidx[x];
    for(auto y:adj[x])if(check[y]) {
      ll idx2=aidx[y];
      aadj[idx1][idx2]=aadj[idx2][idx1]=true;
    }
  }
  //3
  for(int i=0; i<asz; i++)for(int j=i+1; j<asz; j++)for(int k=j+1; k<asz; k++)
    if(aadj[i][j] && aadj[j][k] && aadj[k][i])
      ans3++;
  for(int i=1; i<=n; i++)for(auto x:adj[i]) {
    if(i>x) continue;
    if(check[i] && check[x]) aa.pb({i,x});
    else if(!check[i] && !check[x]) bb.pb({i,x});
    else {
      if(check[i]) ab.pb({i,x});
      else ab.pb({x,i});
    }
  }
  //0 1
  for(auto temp:bb) {
    ll a=temp.F,b=temp.S;
    ll idx=0;
    for(auto x:adj[a]) {
      ll sz=adj[b].size();
      while(idx+1<sz && adj[b][idx]<x) idx++;
      if(x==adj[b][idx]) {
        if(check[x]) ans1++;
        else ans0++;
      }
    }
  }
  ans0/=3;
  //2
  for(auto temp:ab) {
    ll a=temp.F,b=temp.S;
    ll idx1=aidx[b];
    for(auto x:adj[a]) {
      if(!check[x]) continue;
      ll idx2=aidx[x];
      if(aadj[idx1][idx2]) ans2++;
    }
  }
  ans2/=2;
  cout<<(ans0+ans1+ans2+ans3)<<endl;
  return 0;
}