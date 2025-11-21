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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m,l,x,y;
  cin>>m>>n>>l>>x>>y;

  vector<pll> arr(m);
  for(int i=0; i<m; i++) cin>>arr[i].F>>arr[i].S;
  sort(all(arr));
  vector<ld> crr(m);
  for(int i=0; i<m; i++) crr[i]=(ld)(arr[i].S-arr[i].F)/x+(ld)(l-arr[i].S)/y;

  vector<pll> brr(n);
  for(int i=0; i<n; i++) {
    cin>>brr[i].F;
    brr[i].S=i;
  }
  sort(all(brr));

  vector<ld> ans(n,INF);
  ll idx=0;
  ld temp=(ld)INF;
  for(int i=0; i<n; i++) {
    ans[brr[i].S]=(ld)(l-brr[i].F)/y;
    while(idx<m && arr[idx].F<=brr[i].F) {
      temp=min(temp,crr[idx]);
      idx++;
    }
    ans[brr[i].S]=min(ans[brr[i].S],temp);
  }
  cout<<fixed<<setprecision(10);
  for(int i=0; i<n; i++) cout<<ans[i]<<endl;
  return 0;
}