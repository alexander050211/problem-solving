#include <bits/stdc++.h>
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
void solve()
{
  ll n;
  cin>>n;
  string s;
  cin>>s;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) arr[i]=s[i]-'0';
  bool check=true;
  vector<ll> brr;
  for(int i=0; i<n; i++) if(!arr[i]) brr.pb(i);
  for(int st=0; st<brr.size() && check;)
  {
    ll en=st;
    while(en+1<brr.size() && brr[en+1]-brr[en]==2) en++;
    ll cnt=0;
    bool c1=brr[st]>0 && brr[st]+1<n && arr[brr[st]-1] && arr[brr[st]+1];
    bool c2=brr[en]>0 && brr[en]+1<n && arr[brr[en]-1] && arr[brr[en]+1];
    for(int j=st; j<=en; j++)
      if(brr[j]>0 && brr[j]+1<n && arr[brr[j]-1] && arr[brr[j]+1])
        cnt++;
    if(c1 && c2 && (cnt%2)) check=false;
    st=en+1;
  }
  if(check) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
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