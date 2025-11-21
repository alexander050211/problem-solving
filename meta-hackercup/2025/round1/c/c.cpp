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
typedef __int128_t lll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
ifstream fin;
ofstream fout;
void solve()
{
  ll n;
  fin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) fin>>arr[i];
  unordered_map<ll,ll> mp;
  ll temp=0;
  mp[temp]++;
  for(int i=0; i<n; i++)
  {
    temp^=arr[i];
    mp[temp]++;
  }
  auto f=[&](lll x){
    return (lll)x*(x-1)/(lll)2;
  };
  auto g=[&](lll x){
    return (lll)x*(x-1)*(x-2)/(lll)6;
  };
  lll ans1=(lll)g(n+2);
  lll ans2=0,ans3=0;
  for(auto& x:mp)
  {
    ll t=x.S;
    if(t>=2) ans2+=f(t);
    if(t>=3) ans3+=g(t);
  }
  ans1-=ans2+ans3;
  ll ret=(ll)ans1;
  fout<<ret<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fin.open("narrowing_down_input.txt");
  fout.open("out2.txt");
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