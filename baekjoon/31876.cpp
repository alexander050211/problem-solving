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
typedef __uint128_t ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll mod=(ll)1e9+7;
const ll INF=(ll)4e18;
const ll pin=10000000000000000000ULL;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  unsigned long long n,m;
  string s,t;
  cin>>n>>m>>s>>t;
  ll len=s.size();
  if(len>21)
  {
    if(n>m) cout<<"ras"<<endl;
    else if(n<m) cout<<"auq"<<endl;
    else
    {
      for(int i=0; i<len; i++)
      {
        if(s[i]<t[i])
        {
          cout<<"auq"<<endl;
          return 0;
        }
        if(s[i]>t[i])
        {
          cout<<"ras"<<endl;
          return 0;
        }
      }
      cout<<"rasauq"<<endl;
    }
    return 0;
  }
  bool check=false;
  if(n>m)
  {
    check=true;
    swap(n,m);
    swap(s,t);
  }
  ld t1=(ld)len*log(n),t2=(ld)(len-1)*log(m);
  if(t1<t2)
  {
    if(check) cout<<"ras"<<endl;
    else cout<<"auq"<<endl;
    return 0;
  }
  ll temp1=0,temp2=0;
  for(int i=0; i<len; i++)
  {
    temp1=(ll)temp1*n+(ll)(s[i]-'0');
    temp2=(ll)temp2*m+(ll)(t[i]-'0');
    if(temp1<temp2)
    {
      if(check) cout<<"ras"<<endl;
      else cout<<"auq"<<endl;
      return 0;
    }
  }
  if(temp1<temp2)
  {
    if(check) cout<<"ras"<<endl;
    else cout<<"auq"<<endl;
  }
  else if(temp1>temp2)
  {
    if(!check) cout<<"ras"<<endl;
    else cout<<"auq"<<endl;
  }
  else cout<<"rasauq"<<endl;
  return 0;
}