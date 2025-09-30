#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int thr[7]={3,3,3,3,3,3,2};
int pos[21]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7};
int sz[8]={1680,566,188,62,20,6,2};
vector<int> arr[5005];

void init(int x,int st,int en)
{
  if(x==st) 
  {
    while(arr[x].size()<7) arr[x].pb(-1);
    return;
  }
  else if(x==en)
  {
    while(arr[x].size()<7) arr[x].pb(-2);
    return;
  }
  else
  {
    int tsz=sz[arr[x].size()];
    if(x<st+tsz) arr[x].pb(1);
    
  }
}

vector<vector<int>> devise_strategy(int n) {
  for(int i=1; i<=n; i++) init(i,1,n);
  vector<vector<int>> ret(21,vector<int>(n+1,0));
  return ret;
}

int main()
{
  devise_strategy(5000);
  return 0;
}