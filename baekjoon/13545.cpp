#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
deque<ll> adj[200005];
ll dp1[100005],dp2[100005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  ll rn=(ll)floor(sqrt(n));
  vector<ll> crr(n);
  for(int i=0; i<n; i++) cin>>crr[i];
  vector<ll> arr(n+1,0);
  for(int i=1; i<=n; i++) arr[i]=arr[i-1]+crr[i-1];
  for(int i=0; i<=n; i++) arr[i]+=(ll)1e5;
  n++;
  ll m;
  cin>>m;
  vector<pair<pll,ll>> brr(m);
  for(int i=0; i<m; i++)
  {
    ll a,b;
    cin>>a>>b;
    brr[i]={{a-1,b},i};
  }
  sort(all(brr),[&](const pair<pll,ll>& a,const pair<pll,ll>& b){
    ll ta=a.F.F/rn,tb=b.F.F/rn;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
  });  
  ll st=brr[0].F.F,en=brr[0].F.S;
  auto f1=[&](ll x,ll val){
    //cout<<"f1 "<<x<<' '<<val<<endl;
    if(val>0)
    {
      if(!adj[arr[x]].empty())
      {
        ll temp=adj[arr[x]].back()-adj[arr[x]].front();
        dp1[temp]--; dp2[temp/rn]--;
      }
      adj[arr[x]].push_front(x);
      ll temp=adj[arr[x]].back()-adj[arr[x]].front();
      dp1[temp]++; dp2[temp/rn]++;
    }
    else
    {
      ll temp=adj[arr[x]].back()-adj[arr[x]].front();
      dp1[temp]--; dp2[temp/rn]--;
      adj[arr[x]].pop_front();
      if(!adj[arr[x]].empty())
      {
        temp=adj[arr[x]].back()-adj[arr[x]].front();
        dp1[temp]++; dp2[temp/rn]++;
      }
    }
  };
  auto f2=[&](ll x,ll val){
    //cout<<"f2 "<<x<<' '<<val<<endl;
    if(val>0)
    {
      if(!adj[arr[x]].empty())
      {
        ll temp=adj[arr[x]].back()-adj[arr[x]].front();
        dp1[temp]--; dp2[temp/rn]--;
      }
      adj[arr[x]].push_back(x);
      ll temp=adj[arr[x]].back()-adj[arr[x]].front();
      dp1[temp]++; dp2[temp/rn]++;
    }
    else
    {
      ll temp=adj[arr[x]].back()-adj[arr[x]].front();
      dp1[temp]--; dp2[temp/rn]--;
      adj[arr[x]].pop_back();
      if(!adj[arr[x]].empty())
      {
        temp=adj[arr[x]].back()-adj[arr[x]].front();
        dp1[temp]++; dp2[temp/rn]++;
      }
    }
  };
  auto g=[&](){
    ll idx2=n/rn;
    while(idx2>=0 && !dp2[idx2]) idx2--;
    if(idx2==-1) return 0LL;
    ll idx1=rn*(idx2+1)-1;
    idx1=min(idx1,n-1);
    while(idx1>=rn*idx2 && !dp1[idx1]) idx1--;
    return idx1;
  };
  vector<ll> ans(m,0);
  for(int i=st; i<=en; i++) f2(i,1);
  ans[brr[0].S]=g();
  for(int i=1; i<m; i++)
  {
    while(brr[i].F.F<st) f1(--st,1);
    while(en<brr[i].F.S) f2(++en,1);
    while(st<brr[i].F.F) f1(st++,-1);
    while(brr[i].F.S<en) f2(en--,-1);
    st=brr[i].F.F,en=brr[i].F.S;
    ans[brr[i].S]=g();
  }
  for(auto x:ans) cout<<x<<endl;
  return 0;
}