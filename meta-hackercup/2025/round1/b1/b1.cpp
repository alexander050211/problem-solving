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
  ll n,a,b;
  fin>>n>>a>>b;
  for(int i=1; i<2*n; i++) fout<<1<<' ';
  fout<<b<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  fin.open("final_product_chapter_1_input.txt");
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