#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  string s, t;
  cin >> n >> s >> t;
  ll a, b;
  cin >> a >> b;
  string temp = "";
  for (int i = 0; i < a; i++)
    temp += s[i];
  for (int i = a + 1; i < b; i++)
    temp += s[i];
  for (int i = b + 1; i < n; i++)
    temp += s[i];

  string temp2 = "";
  temp2 += s[a];
  temp2 += s[b];
  temp2 += temp;
  if (temp2 == t)
  {
    cout << "YES" << endl;
    return 0;
  }
  ll idx = 0;
  while (idx < n - 2 && temp[idx] == t[idx])
    idx++;
  if (t[idx] != s[a])
  {
    cout << "NO" << endl;
    return 0;
  }
  idx++;
  while (idx < n - 1 && temp[idx - 1] == t[idx])
    idx++;
  if (t[idx] != s[b])
  {
    cout << "NO" << endl;
    return 0;
  }
  idx++;
  while (idx < n && temp[idx - 2] == t[idx])
    idx++;
  if (idx < n)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}