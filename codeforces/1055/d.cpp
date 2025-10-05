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
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
void solve()
{
  ll n,q;
  cin>>n>>q;
  vector<ll> arr(n+1);
  for(int i=1; i<=n; i++) cin>>arr[i];
  vector<ll> brr(n+1,0),crr(n+1,0),drr(n+1,0);
  for(int i=1; i<=n; i++)
  {
    brr[i]=brr[i-1];
    crr[i]=crr[i-1];
    drr[i]=drr[i-1];
    ll temp=arr[i];
    vector<ll> t;
    while(temp)
    {
      t.pb(temp%2);
      temp>>=1;
    }
    reverse(all(t));
    brr[i]+=t.size()-1;
    ll cnt=0;
    ll flag=0;
    for(int j=1; j<t.size(); j++)
    {
      cnt+=t[j];
      if(!flag && t[j]) flag=j;
    }
    if(!flag) continue;
    if(flag==t.size()-1) crr[i]++;
    else drr[i]++;
  }
  while(q--)
  {
    ll a,b;
    cin>>a>>b;
    ll ans=brr[b]+crr[b]+drr[b]-brr[a-1]-crr[a-1]-drr[a-1];
    ans-=(crr[b]-crr[a-1]+1)/2;
    cout<<ans<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll tt=1;
  cin>>tt;
  while(tt--)
  {
    solve();
  }
  return 0;
}