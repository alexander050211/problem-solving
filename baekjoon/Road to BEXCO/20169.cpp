#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> line;
vector<line> hrr,vrr;
vector<pll> hh[505],vv[505];
vector<line> cycle;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,t;
  cin>>n>>t;
  pll st;
  ll dir;
  for(int i=0; i<n; i++)
  {
    pll a,b;
    cin>>a.F>>a.S>>b.F>>b.S;
    if(!i)
    {
      st=a;
      if(a.F==b.F && a.S<b.S) dir=0;
      else if(a.S==b.S && a.F<b.F) dir=1;
      else if(a.F==b.F) dir=2;
      else if(a.S==b.S) dir=3;
    }
    if(a.F>b.F || a.S>b.S) swap(a,b);
    if(a.F==b.F) vrr.pb({a,b});
    else hrr.pb({a,b});
  }
  sort(all(hrr),[&](const line& a,const line& b){
    return (a.F.S==b.F.S)?(a.F.F<b.F.F):(a.F.S<b.F.S);
  });
  sort(all(vrr),[&](const line& a,const line& b){
    return (a.F.F==b.F.F)?(a.F.S<b.F.S):(a.F.F<b.F.F);
  });
  for(int i=0; i<hrr.size(); i++) hh[i].pb({hrr[i].F.F,-1}),hh[i].pb({hrr[i].S.F,-1});
  for(int i=0; i<vrr.size(); i++) vv[i].pb({vrr[i].F.S,-1}),vv[i].pb({vrr[i].S.S,-1});
  for(int i=0; i<hrr.size(); i++)for(int j=0; j<vrr.size(); j++)
  {
    if(hrr[i].F.F<=vrr[j].F.F && vrr[j].F.F<=hrr[i].S.F && vrr[j].F.S<=hrr[i].F.S && hrr[i].F.S<=vrr[j].S.S)
    {
      hh[i].pb({vrr[j].F.F,j});
      vv[j].pb({hrr[i].F.S,i});
    }
  }
  for(int i=0; i<hrr.size(); i++) sort(all(hh[i]));
  for(int i=0; i<vrr.size(); i++) sort(all(vv[i]));
  pll temp=st;
  ll idx=0;
  if(dir%2==0)while(idx<vrr.size() && vrr[idx].F!=st && vrr[idx].S!=st) idx++;
  else while(idx<hrr.size() && hrr[idx].F!=st && hrr[idx].S!=st) idx++;
  vector<line> ans;
  while(ans.empty() || temp!=st)
  {
    pll nxt;
    if(dir==0)
    {
      ll pos=lower_bound(all(vv[idx]),mp(temp.S,-1LL))-vv[idx].begin();
      nxt={temp.F,vv[idx][pos+1].F};
      if(pos==vv[idx].size()-2) dir=2;
      else dir=3,idx=vv[idx][pos+1].S;
      ans.pb({temp,nxt});
      temp=nxt;
    }
    else if(dir==1)
    {
      ll pos=lower_bound(all(hh[idx]),mp(temp.F,-1LL))-hh[idx].begin();
      nxt={hh[idx][pos+1].F,temp.S};
      if(pos==hh[idx].size()-2) dir=3;
      else dir=0,idx=hh[idx][pos+1].S;
      ans.pb({temp,nxt});
      temp=nxt;
    }
    else if(dir==2)
    {
      ll pos=lower_bound(all(vv[idx]),mp(temp.S,-1LL))-vv[idx].begin();
      nxt={temp.F,vv[idx][pos-1].F};
      if(pos==1) dir=0;
      else dir=1,idx=vv[idx][pos-1].S;
      ans.pb({temp,nxt});
      temp=nxt;
    }
    else
    {
      ll pos=lower_bound(all(hh[idx]),mp(temp.F,-1LL))-hh[idx].begin();
      nxt={hh[idx][pos-1].F,temp.S};
      if(pos==1) dir=1;
      else dir=2,idx=hh[idx][pos-1].S;
      ans.pb({temp,nxt});
      temp=nxt;
    }
  }
  ll len=0;
  for(auto [p1,p2]:ans) len+=llabs(p2.F-p1.F)+llabs(p2.S-p1.S);
  if(!len)
  {
    cout<<st.F<<' '<<st.S<<endl;
    return 0;
  }
  t%=len;
  for(auto [p1,p2]:ans)
  {
    ll tlen=llabs(p2.F-p1.F)+llabs(p2.S-p1.S);
    if(tlen<=t)
    {
      t-=tlen;
      continue;
    }
    pll p={t*p2.F+(tlen-t)*p1.F,t*p2.S+(tlen-t)*p1.S};
    p={p.F/tlen,p.S/tlen};
    cout<<p.F<<' '<<p.S<<endl;
    break;
  }
  return 0;
}