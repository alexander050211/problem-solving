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
string a[3]={"","12","21"};
string b[7]={"","123","132","213","231","312","321"};
string c[25]={"","1234","1243","1324","1342","1423","1432",
  "2134","2143","2314","2341","2413","2431",
  "3124","3142","3214","3241","3412","3421",
  "4123","4132","4213","4231","4312","4321"};
string f(string s,string t) {
  ll cnt=0;
  for(int i=0; i<s.size(); i++)if(s[i]==t[i]) cnt++;
  string ans=to_string(cnt)+"A"+to_string(s.size()-cnt)+"B";
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll t;
  cin>>t;
  while(t--) {
    string s;
    ll x,y;
    cin>>s>>x>>y;
    if(s=="12") cout<<f(a[x],a[y])<<endl;
    else if(s=="123") cout<<f(b[x],b[y])<<endl;
    else if(s=="1234") cout<<f(c[x],c[y])<<endl;
  }
  return 0;
}