#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll,ll> pll;
ll n,m,w,h;
ll wrr[2005],arr[2005];
priority_queue<pll> pq;
vector<ll> ans[2005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>m>>n>>w>>h;
  for(int i=1; i<=m; i++) cin>>wrr[i];
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=m; i++) pq.push({wrr[i],i});
  for(int i=1; i<=n; i++)
  {
    if(arr[i]<=0) continue;
    for(int j=1; j<=arr[i]; j++)
    {
      pll temp=pq.top();
      pq.pop();
      ans[temp.S].push_back(i);
      for(int k=i; k<i)
    }
  }
  return 0;
}