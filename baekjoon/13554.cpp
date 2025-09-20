#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n;
ll arr[100005],brr[100005],ans[100005];
vector<pair<pll,pll>> crr;
struct Fenwick
{
  ll sz;
  vector<ll> bit;
  void init(ll x) { sz=x+1; bit.assign(sz+1,0); }
  void add(ll i,ll v) { for(; i<=sz; i+=i&-i)bit[i]+=v; }
  ll psum(ll i) { ll ret=0; for(; i>0; i-=i&-i)ret+=bit[i]; return ret; }
  ll query(ll l,ll r) { if(r<l)return 0; return psum(r)-psum(l-1); }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  ll rn=(ll)floor(sqrt(n));
  for(int i=0; i<n; i++) cin>>arr[i];
  for(int i=0; i<n; i++) cin>>brr[i];
  ll q;
  cin>>q;
  for(int i=0; i<q; i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    crr.push_back({{a-1,b-1},{c,i}});
  }
  sort(all(crr),[&](const pair<pll,pll>& a,const pair<pll,pll>& b){
    ll ta=a.F.F/rn,tb=b.F.F/rn;
    return (ta==tb)?(a.F.S<b.F.S):(ta<tb);
    return true;
  });
  Fenwick fw1,fw2;
  fw1.init(100000); fw2.init(100000);
  ll st=crr[0].F.F,en=crr[0].F.S;
  ll temp=0;
  for(int i=st; i<=en; i++)
  {
    fw1.add(arr[i],1); fw2.add(brr[i],1);
    temp+=fw1.query(1,(ll)floor((double)crr[0].S.F/brr[i]));
    temp+=fw2.query(1,(ll)floor((double)crr[0].S.F/arr[i]));
    if(arr[i]*brr[i]<=crr[0].S.F) temp--;
  }
  ans[crr[0].S.S]=temp;
  auto f1=[&](ll x,ll k){
    fw1.add(arr[x],1); fw2.add(brr[x],1);
    temp+=fw1.query(1,(ll)floor((double)k/brr[x]));
    temp+=fw2.query(1,(ll)floor((double)k/arr[x]));
    if(arr[x]*brr[x]<=k) temp--;
  };
  auto f2=[&](ll x,ll k){
    temp-=fw1.query(1,(ll)floor((double)k/brr[x]));
    temp-=fw2.query(1,(ll)floor((double)k/arr[x]));
    if(arr[x]*brr[x]<=k) temp++;
    fw1.add(arr[x],-1); fw2.add(brr[x],-1);
  };
  for(int i=1; i<=10; i++) cout<<fw1.psum(i)<<' ';
  cout<<endl;
  for(int i=1; i<=10; i++) cout<<fw2.psum(i)<<' ';
  cout<<endl;
  for(int i=1; i<q; i++)
  {
    ll k=crr[i].S.F;
    cout<<crr[i].F.F<<' '<<crr[i].F.S<<' '<<crr[i].S.F<<' '<<crr[i].S.S<<endl;
    while(crr[i].F.F<st) f1(--st,k);
    while(en<crr[i].F.S) f1(++en,k);
    while(st<crr[i].F.F) f2(st++,k);
    while(crr[i].F.S<en) f2(en--,k);
    ans[crr[i].S.S]=temp;
    for(int i=1; i<=10; i++) cout<<fw1.psum(i)<<' ';
    cout<<endl;
    for(int i=1; i<=10; i++) cout<<fw2.psum(i)<<' ';
    cout<<endl;
  }
  for(int i=0; i<q; i++) cout<<ans[i]<<endl;
  return 0;
}