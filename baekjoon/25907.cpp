#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ll st = 2, en = n;
  while (st < en)
  {
    ll mid = (st + en) / 2;
    if (mid % 2)
    {
      if (mid - st < en - mid)
        mid++;
      else
        mid--;
    }
    cout << "? " << mid << endl;
    cout << flush;
    ll temp;
    cin >> temp;
    if (temp * 2 == mid)
    {
      cout << "! " << mid << endl;
      cout << flush;
      return 0;
    }
    if (temp * 2 < mid)
      en = mid - 1;
    else
      st = mid + 1;
  }
  return 0;
}