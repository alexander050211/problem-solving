#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll arr[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
ll brr[100005];
string crr[100005];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++)
  {
    cin>>crr[i];
    ll temp=0;
    for(int j=0; j<crr[i].size(); j++) temp=(temp*10+(arr[crr[i][j]-'a']));
    brr[i]=temp;
  }
  for(int i=0; i<m; i++)
  {
    ll temp;
    cin>>temp;
    vector<ll> ans;
    for(int j=0; j<n; j++)if(temp==brr[j]) ans.push_back(j);
    cout<<ans.size()<<' ';
    for(auto x:ans) cout<<crr[x]<<' ';
    cout<<endl;
  }
  return 0;
}