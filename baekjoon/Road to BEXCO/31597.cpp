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
ll arr[105][105];
ll cntx[105][105],cnty[105][105];
bool cx[105],cy[105];
bool vx[105],vy[105];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    ll cnt1=0,cnt2=0;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++) cin>>arr[i][j];
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++) cntx[i][arr[i][j]]++;
      for(int j=1; j<=n; j++)if(cntx[i][j]!=1) { cnt1++,cx[i]=true; break; }
      for(int j=0; j<n; j++) cnty[i][arr[j][i]]++;
      for(int j=1; j<=n; j++)if(cnty[i][j]!=1) { cnt2++,cy[i]=true; break; }
    }
    vector<pll> temp;
    if(cnt1==n)
    {
      for(int i=0; i<n; i++)if(!cy[i]) temp.pb({i,i});
    }
    else if(cnt2==n)
    {
      for(int i=0; i<n; i++)if(!cx[i]) temp.pb({i,i});
    }
    else
    {
      for(int i=0; i<n; i++)for(int j=0; j<n; j++)
      {
        if(cx[i] || cy[j]) continue;
        if(!vx[i] || !vy[j])
        {
          temp.pb({i,j});
          vx[i]=vy[j]=true;
        }
      }
    }
    vector<pair<pll,ll>> ans;
    for(auto p:temp)
    {
      ll x=arr[p.F][p.S];
      for(int i=1; i<=n; i++)
      {
        cntx[p.F][x]--; cntx[p.F][i]++;
        cnty[p.S][x]--; cnty[p.S][i]++;
        bool f1=false,f2=false;
        for(int j=1; j<=n; j++)if(cntx[p.F][j]!=1) { f1=true; break; }
        for(int j=1; j<=n; j++)if(cnty[p.S][j]!=1) { f2=true; break; }
        if(f1 && f2)
        {
          ans.pb({p,i});
          break;
        }
        cntx[p.F][x]++; cntx[p.F][i]--;
        cnty[p.S][x]++; cnty[p.S][i]--;
      }
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x.F+1<<' '<<x.S+1<<' '<<y<<endl;
    for(int i=0; i<n; i++) cx[i]=cy[i]=vx[i]=vy[i]=0;
    for(int i=0; i<=n; i++)for(int j=0; j<=n; j++) arr[i][j]=cntx[i][j]=cnty[i][j]=0;
  }
  return 0;
}