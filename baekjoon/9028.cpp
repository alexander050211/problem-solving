#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
void solve()
{
  string arr;
  cin >> arr;
  cin.ignore();
  for (int i = 0; i < arr.size(); i++)
    if ('A' <= arr[i] && arr[i] <= 'Z')
      arr[i] = (arr[i] - 'A' + 'a');
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); i++)
    if ('A' <= str[i] && str[i] <= 'Z')
      str[i] = (str[i] - 'A' + 'a');
  vector<ll> ans = vector<ll>();
  ll brr[10] = {
      0,
  };
  for (int i = 0; i < str.size(); i++)
    for (int j = 0; j < arr.size(); j++)
      if (str[i] == arr[j])
      {
        if (j && brr[j - 1] <= brr[j])
          continue;
        brr[j]++;
        if (j == arr.size() - 1)
          ans.emplace_back(i + 1);
      }

  cout << ans.size() << ' ';
  for (int i = 0; i < min((int)ans.size(), (int)3); i++)
    cout << ans[i] << ' ';
  cout << endl;
  return;
}
int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}