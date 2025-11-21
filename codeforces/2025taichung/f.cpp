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
ll gcd(ll x,ll y) {
  if(!y) return x;
  return gcd(y,x%y);
}
ll brr[200005],crr[200005];
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<ll> arr(n+1,0);
  for(int i=1; i<=n; i++) cin>>arr[i];
  brr[1]=arr[1];
  for(int i=2; i<=n; i++) brr[i]=gcd(brr[i-1],arr[i]);
  crr[n]=arr[n];
  for(int i=n-1; i>0; i--) crr[i]=gcd(crr[i+1],arr[i]);
  ll ans=brr[n];
  for(int i=2; i<n; i++) ans+=min(brr[i],crr[i]);
  cout<<ans<<endl;
  return 0;
}