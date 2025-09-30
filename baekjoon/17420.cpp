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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<ll> arr(n),brr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n; i++) cin>>brr[i];
  vector<pll> crr(n);
  for(int i=0; i<n; i++) crr[i]={brr[i],arr[i]};
  sort(all(crr));
  ll ans=0;
  ll temp=0,temp2=0;
  for(int i=0; i<n; i++)
  {
    if(i && crr[i].F>crr[i-1].F) temp=max(temp,temp2);
    ll temp3=max(temp,crr[i].F);
    ll cnt=(ll)ceil((double)(temp3-crr[i].S)/30);
    cnt=max(cnt,0LL);
    ans+=cnt;
    crr[i].S+=30*cnt;
    temp2=max(temp2,crr[i].S);
  }
  cout<<ans<<endl;
  return 0;
}