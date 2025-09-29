#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
int par[500005],cost[500005],tcost[500005];
int dp[500005][3];
int n=1;

void init()
{
  for(int i=2; i<=500000; i++) par[i]=i;
  tcost[1]=1;
}
void observation(int P)
{
  par[++n]=P;
  tcost[n]=1;
  int idx=n;
  while(par[idx]>0)
  {
    int nxt=par[idx];
    int nc=tcost[nxt];
    if(idx!=dp[nxt][0] && idx!=dp[nxt][1] && idx!=dp[nxt][2])
    {
      if(tcost[idx]>tcost[dp[nxt][0]])
      {
        dp[nxt][2]=dp[nxt][1];
        dp[nxt][1]=dp[nxt][0];
        dp[nxt][0]=idx;
      }
      else if(tcost[idx]>tcost[dp[nxt][1]])
      {
        dp[nxt][2]=dp[nxt][1];
        dp[nxt][1]=idx;
      }
      else if(tcost[idx]>tcost[dp[nxt][2]])
      {
        dp[nxt][2]=idx;
      }
      else break;
    }
    else if(idx==dp[nxt][1])
    {
      if(tcost[idx]>tcost[dp[nxt][0]]) swap(dp[nxt][0],dp[nxt][1]);
    }
    else if(idx==dp[nxt][2])
    {
      if(tcost[idx]>tcost[dp[nxt][1]]) swap(dp[nxt][1],dp[nxt][2]);
      if(tcost[dp[nxt][1]]>tcost[dp[nxt][0]]) swap(dp[nxt][0],dp[nxt][1]);
    }
    tcost[nxt]=max(tcost[dp[nxt][0]],tcost[dp[nxt][1]]+1);
    if(tcost[nxt]==nc) break;
    idx=nxt;
  }
  idx=n;
  while(par[idx]>0)
  {
    int nxt=par[idx];
    int nc=cost[nxt];
    cost[nxt]=max({nc,cost[idx],tcost[dp[nxt][0]]+tcost[dp[nxt][1]]-1,tcost[dp[nxt][1]]+tcost[dp[nxt][2]]});
    if(cost[nxt]==nc) break;
    idx=nxt;
  }
}
int analyze(int R)
{
  return cost[R];
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int qtype, u;
        scanf("%d %d", &qtype, &u);
        if(qtype==1)observation(u);
        if(qtype==2)printf("%d\n", analyze(u));
    }
    return 0;
}
