#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
ll n, k;
vector<ll> arr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(all(arr));
  arr.erase(unique(all(arr)), arr.end());
  vector<ll> brr(arr.size() - 1);
  ll ans = arr.back() - arr[0];
  for (int i = 1; i < arr.size(); i++)
    brr.push_back(arr[i] - arr[i - 1]);
  sort(all(brr));
  reverse(all(brr));
  for (int i = 0; i < min(k - 1, (ll)brr.size()); i++)
    ans -= brr[i];
  cout << ans << endl;
  return 0;
}