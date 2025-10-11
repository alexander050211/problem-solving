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
ifstream fin;
ofstream fout;
void solve()
{
  ll n;
  fin>>n;
  vector<pair<pll,ll>> arr(n);
  for(int i=0; i<n; i++) fin>>arr[i].F.F;
  for(int i=0; i<n; i++) fin>>arr[i].F.S,arr[i].S=i+1;
  sort(all(arr));
  vector<pll> ans;
  vector<ll> idx(n+1,-1);
  for(int i=n-1; i>=0; i--)
  {
    idx[arr[i].F.F]=arr[i].S;
    if(arr[i].F.F==arr[i].F.S) continue;
    if(idx[arr[i].F.S]==-1)
    {
      fout<<-1<<endl;
      return;
    }
    ans.pb({arr[i].S,idx[arr[i].F.S]});
  }
  reverse(all(ans));
  fout<<ans.size()<<endl;
  for(auto x:ans) fout<<x.F<<' '<<x.S<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fin.open("warm_up_input.txt");
  fout.open("a_output2.txt");
  ll tt=1;
  fin>>tt;
  for(int i=1; i<=tt; i++)
  {
    if(fin.eof()) break;
    fout<<"Case #"<<i<<": ";
    solve();
  }
  fin.close();
  fout.close();
  return 0;
}