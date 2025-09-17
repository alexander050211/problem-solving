#include <bits/stdc++.h>
#define endl '\n'
#pragma gcc optimize("O3")
#pragma gcc optimize("OFast")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll rnk[105],cnt[105];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m,k;
  cin>>n>>m>>k;
  for(int i=1; i<=n; i++)
  {
    string s;
    cin>>s;
    for(int j=0; j<m; j++)if(s[j]=='P') cnt[i]++;
    rnk[i]=i;
  }
  ll tt=0;
  for(int i=1; i<=n; i++) tt+=cnt[i];
  while(tt--)
  {
    string s,t;
    cin>>s>>t;
    ll idx=1;
    while(!cnt[idx]) idx++;
    for(int i=idx+1; i<=n; i++) idx=(cnt[i] && rnk[idx]<rnk[i])?i:idx;
    cnt[idx]--;
    ll diff=0;
    if(t.back()=='!') diff=t.size()-9;
    for(int i=1; i<=n; i++)if(rnk[i]>=rnk[idx]-diff && rnk[i]<rnk[idx]) rnk[i]++;
    rnk[idx]-=diff;
  }
  cout<<rnk[k]<<endl;
  return 0;
}