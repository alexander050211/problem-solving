#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector<ll> ans = vector<ll>();
  ll cnt = 0;
  ll temp = 0;
  while (n)
  {
    for (int i = 0; i < n % 3; i++)
      ans.push_back(temp);
    cnt += n % 3;
    n /= 3;
    temp++;
  }
  cout << cnt << endl;
  for (auto x : ans)
    cout << x << ' ';
  return 0;
}