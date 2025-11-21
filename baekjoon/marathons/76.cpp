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
  ll b,n;
  while(1)
  {
    cin>>b>>n;
    if(!b) return 0;
    vector<pll> ans;
    for(int m=1; m<=2*n; m++) {
      if(m==n) continue;
      ll t1=b*m*(2*n-m),t2=n*n;
      if(t1%t2) continue;
      ans.pb({t1/t2,m});
    }
    sort(all(ans),[&](const pll& t1,const pll& t2){
      return t1.F*t2.S<t1.S*t2.F;
    });
    for(auto x:ans) cout<<x.F<<'/'<<x.S<<' ';
    cout<<endl;
  }
  return 0;
}