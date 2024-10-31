#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
vector<pair<double, pll>> arr;
ll n;
ll buy[100005], sell[100005];
double price, ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i].F >> arr[i].S.F >> arr[i].S.S;
  sort(arr.begin(), arr.end());
  buy[n - 1] = arr[n - 1].S.F;
  for (int i = n - 2; i >= 0; i--)
    buy[i] = buy[i + 1] + arr[i].S.F;
  sell[0] = arr[0].S.S;
  for (int i = 1; i < n; i++)
    sell[i] = sell[i - 1] + arr[i].S.S;
  bool check = false;
  for (int i = 0; i < n; i++)
  {
    if (!buy[i] || !sell[i])
      continue;
    double temp = (double)arr[i].F * min(buy[i], sell[i]);
    if (ans < temp)
    {
      check = true;
      ans = temp;
      price = arr[i].F;
    }
  }
  if (!check)
    cout << "impossible" << endl;
  else
    printf("%.2lf %.2lf", price, ans);
  return 0;
}