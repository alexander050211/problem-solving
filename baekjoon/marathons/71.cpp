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
  auto f=[&](const string& s) {
    ll ret=(s[0]-'0')*100000000+(s[1]-'0')*10000000+(s[3]-'0')*1000000+(s[4]-'0')*100000+(s[6]-'0')*10000
    +(s[7]-'0')*1000+(s[9]-'0')*100+(s[10]-'0')*10+(s[11]-'0');
    return ret;
  };
  ll n;
  cin>>n;
  vector<pll> arr(n);
  for(int i=0; i<n; i++)
  {
    string s,t;
    cin>>s>>t;
    arr[i]={f(s),f(t)};
  }
  sort(all(arr));
  ll ans=0;
  priority_queue<ll> pq;
  for(int i=0; i<n; i++)
  {
    while(!pq.empty() && -pq.top()<=arr[i].F) pq.pop();
    pq.push(-arr[i].S);
    ans=max(ans,(ll)pq.size());
  }
  cout<<ans<<endl;
  return 0;
}