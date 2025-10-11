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
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fin.open("warm_up_validation_input.txt");
  fout.open("a_output1.txt");
  ll tt=1;
  fin>>tt;
  for(int i=1; i<=tt; i++)
  {
    if(fin.eof()) break;
    cout<<"Case #"<<i<<": ";
    solve();
  }
  fin.close();
  fout.close();
  return 0;
}