#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("avx,avx2,fma")
#pragma gcc optimize("unroll-loops")
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t, x[4];
  vector<vector<int>> ans;
  string s;
  cin >> t;
  for (int i = 0; i < t; i++){
    cin >> s;
    ans.clear();
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    while (1){
      while (s[x[0]] != 'I' && x[0] < s.length()) x[0]++;
      x[1] = max(x[1], x[0] + 1);
      while (s[x[1]] != 'C' && x[1] < s.length()) x[1]++;
      x[2] = max(x[2], x[1] + 1);
      while (s[x[2]] != 'P' && x[2] < s.length()) x[2]++;
      x[3] = max(x[3], x[2] + 1);
      while (s[x[3]] != 'C' && x[3] < s.length()) x[3]++;
      if (x[3] >= s.length()) break;
      ans.push_back({x[0] + 1, x[1] + 1, x[2] + 1, x[3] + 1});
      for (int j = 0; j < 4; j++) s[x[j]] = ' ';
    }
    cout << ans.size() << '\n';
    for (int j = 0; j < ans.size(); j++){
      for (int k = 0; k < 4; k++) cout << ans[j][k] << ' ';
      cout << '\n';
    }
  }
  return 0;
}