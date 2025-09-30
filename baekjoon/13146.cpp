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
const ll mod=(ll)10007;
const ll INF=(ll)4e16;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector<ll> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  vector<ll> brr;
  brr.pb(arr[0]);
  for(int i=1; i<n; i++)if(arr[i]!=arr[i-1]) brr.pb(arr[i]);
  ll ans=0;
  stack<ll> st;
  st.push(brr[0]);
  for(int i=1; i<brr.size(); i++)
  {
    if(brr[i]<st.top())
    {
      st.push(brr[i]);
      continue;
    }
    if(brr[i]==st.top()) continue;
    ll t1=st.top();
    st.pop();
    while(1)
    {
      if(st.empty())
      {
        ans+=brr[i]-t1;
        st.push(brr[i]);
        break;
      }
      ll t2=st.top();
      st.pop();
      if(t2>brr[i])
      {
        ans+=brr[i]-t1;
        st.push(t2);
        st.push(brr[i]);
        break;
      }
      else if(t2==brr[i])
      {
        ans+=brr[i]-t1;
        st.push(t2);
        break;
      }
      else
      {
        ans+=t2-t1;
        t1=t2;
        continue;
      }
    }
  }
  ll t1=st.top();
  st.pop();
  while(!st.empty())
  {
    ll t2=st.top();
    st.pop();
    ans+=t2-t1;
    t1=t2;
  }
  cout<<ans<<endl;
  return 0;
}