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
typedef pair<ll,ll> pll;
vector<pair<pll,ll>> arr;
ll tree1[400005],tree2[400005];
priority_queue<pair<pll,ll>> pq1,pq2;
vector<pair<pll,ll>> ans;
void upd1(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree1[node]+=v;
    return;
  }
  ll mid=(st+en)>>1;
  upd1(node<<1,st,mid,idx,v); upd1(node<<1|1,mid+1,en,idx,v);
  tree1[node]=tree1[node<<1]+tree1[node<<1|1];
}
void upd2(ll node,ll st,ll en,ll idx,ll v)
{
  if(idx<st || en<idx) return;
  if(st==en)
  {
    tree2[node]+=v;
    return;
  }
  ll mid=(st+en)>>1;
  upd2(node<<1,st,mid,idx,v); upd2(node<<1|1,mid+1,en,idx,v);
  tree2[node]=tree2[node<<1]+tree2[node<<1|1];
}
ll query1(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree1[node];
  ll mid=(st+en)>>1;
  return query1(node<<1,st,mid,l,r)+query1(node<<1|1,mid+1,en,l,r);
}
ll query2(ll node,ll st,ll en,ll l,ll r)
{
  if(r<st || en<l) return 0;
  if(l<=st && en<=r) return tree2[node];
  ll mid=(st+en)>>1;
  return query2(node<<1,st,mid,l,r)+query2(node<<1|1,mid+1,en,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout.tie(0);
  ll n;
  cin>>n;
  vector<ll> brr;
  for(int i=0; i<n; i++)
  {
    string s,t;
    ll a,b;
    cin>>s>>t>>a>>b;
    ll c=(s[0]=='b')?(t[0]=='n'?1:3):(t[0]=='n'?2:4);
    arr.pb({{c,a},b});
    brr.pb(a);
  }
  sort(all(brr));
  brr.erase(unique(all(brr)),brr.end());
  for(int i=0; i<n; i++) arr[i].F.S=lower_bound(all(brr),arr[i].F.S)-brr.begin();
  ll m=brr.size();
  for(int i=0; i<n; i++)
  {
    if(arr[i].F.F==1)
    {
      while(arr[i].S>0 && !pq2.empty() && -pq2.top().F.F<=arr[i].F.S)
      {
        auto temp=pq2.top();
        pq2.pop();
        upd2(1,0,m-1,-temp.F.F,-temp.S);
        ll cnt=min(arr[i].S,temp.S);
        arr[i].S-=cnt; temp.S-=cnt;
        ans.pb({{-temp.F.S,i+1},cnt});
        if(temp.S>0)
        {
          pq2.push(temp); 
          upd2(1,0,m-1,-temp.F.F,temp.S);
        }
      }
      if(arr[i].S>0)
      {
        pq1.push({{arr[i].F.S,-i-1},arr[i].S});
        upd1(1,0,m-1,arr[i].F.S,arr[i].S);
      }
    }
    else if(arr[i].F.F==2)
    {
      while(arr[i].S>0 && !pq1.empty() && pq1.top().F.F>=arr[i].F.S)
      {
        auto temp=pq1.top();
        pq1.pop();
        upd1(1,0,m-1,temp.F.F,-temp.S);
        ll cnt=min(arr[i].S,temp.S);
        arr[i].S-=cnt; temp.S-=cnt;
        ans.pb({{i+1,-temp.F.S},cnt});
        if(temp.S>0)
        {
          pq1.push(temp);
          upd1(1,0,m-1,temp.F.F,temp.S);
        }
      }
      if(arr[i].S>0)
      {
        pq2.push({{-arr[i].F.S,-i-1},arr[i].S});
        upd2(1,0,m-1,arr[i].F.S,arr[i].S);
      }
    }
    else if(arr[i].F.F==3)
    {
      ll tcnt=query2(1,0,m-1,0,arr[i].F.S);
      if(tcnt<arr[i].S) continue;
      while(arr[i].S>0)
      {
        auto temp=pq2.top();
        pq2.pop();
        upd2(1,0,m-1,-temp.F.F,-temp.S);
        ll cnt=min(arr[i].S,temp.S);
        arr[i].S-=cnt; temp.S-=cnt;
        ans.pb({{-temp.F.S,i+1},cnt});
        if(temp.S>0)
        {
          pq2.push(temp);
          upd2(1,0,m-1,-temp.F.F,temp.S);
        }
      }
    }
    else
    {
      ll tcnt=query1(1,0,m-1,arr[i].F.S,m-1);
      if(tcnt<arr[i].S) continue;
      while(arr[i].S>0)
      {
        auto temp=pq1.top();
        pq1.pop();
        upd1(1,0,m-1,temp.F.F,-temp.S);
        ll cnt=min(arr[i].S,temp.S);
        arr[i].S-=cnt; temp.S-=cnt;
        ans.pb({{i+1,-temp.F.S},cnt});
        if(temp.S>0)
        {
          pq1.push(temp);
          upd1(1,0,m-1,temp.F.F,temp.S);
        }
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans) cout<<x.F.F<<' '<<x.F.S<<' '<<x.S<<endl;
  return 0;
}