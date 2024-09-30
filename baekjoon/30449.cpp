#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma target("avx,avx2,fma")
#pragma target("unroll-loops")
#define endl '\n'
using namespace std;
typedef int ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
ll n, k;
struct comp
{
  bool operator()(pll a, pll b)
  {
    return a.F * b.S > a.S * b.F;
  }
};
ll gcd(ll a, ll b)
{
  if (!b)
    return a;
  return gcd(b, a % b);
}
priority_queue<pll, vector<pll>, comp> pq;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    pq.push({1, i});

  for (int i = 1; i < k - 1; i++)
  {
    pll temp = pq.top();
    temp.F++;
    while (gcd(temp.F, temp.S) > 1)
      temp.F++;
    if (temp.F < temp.S && gcd(temp.F, temp.S) == 1)
      pq.push(temp);
    pq.pop();
  }
  pll temp;
  if (!pq.empty())
    temp = pq.top();
  else
    temp = {1, 1};
  cout << temp.F << ' ' << temp.S << endl;
  return 0;
}