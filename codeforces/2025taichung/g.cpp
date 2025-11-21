#include <bits/stdc++.h>
#include <tuple>
using namespace std;
typedef long long ll;

ll dp[200001][8]={0};

tuple<ll,ll,ll> arr[8] = {{-1,-1,-1}, {-1,-1,1}, {-1,1,1}, {-1,1,-1}, {1,-1,1}, {1,-1,-1}, {1,1,-1},{1,1,1}};


void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj, vector<tuple<ll,ll,ll>> & points){
    ll a1 = get<0>(points[node]);     ll a2 = get<1>(points[node]);     ll a3 = get<2>(points[node]);
    for(auto &[next, w]: adj[node]){
      if(next==parent) continue;
      dfs(next, node, adj, points);
    }

    for(int k=0;k<8;k++){
    
    ll m = 0 + get<0>(arr[k]) * a1 + get<1>(arr[k]) * a2 + get<2>(arr[k]) *a3;

    for(auto &[next, w] : adj[node]){
        if(next==parent) continue;
        m = max(m, w + dp[next][k]);
    }

    dp[node][k]=m;
    }
}


ll result = -1e9;

void dfs2(int node, int parent, vector<vector<pair<int,int>>>& adj, vector<tuple<ll,ll,ll>> & points){


    ll a1 = get<0>(points[node]);     ll a2 = get<1>(points[node]);     ll a3 = get<2>(points[node]);

    //case1
    for(int k=0;k<8;k++){
    ll m = 0 + get<0>(arr[k]) * a1 + get<1>(arr[k]) * a2 + get<2>(arr[k]) *a3;
    for(auto &[next, w] : adj[node]) if(next!=parent) result = max(result, m + w + dp[next][7-k]);
    }

    //case2
    for(int k=0;k<4;k++){
        vector<pair<ll,ll>> m1;
        for(auto &[next, w] : adj[node]){
          if(next==parent) continue;
          m1.push_back(make_pair(w + dp[next][k],next));
        }
        sort(m1.begin(), m1.end());

        vector<pair<ll,ll>> m2;

        for(auto &[next, w] : adj[node]){
          if(next==parent) continue;
          m2.push_back(make_pair(w + dp[next][7-k],next));
        }
        sort(m2.begin(), m2.end());
        int n1 = m1.size()-1;
        int n2 = m2.size()-1;
        if(n1<0 || n2<0) continue;
        if(m1[n1].second!=m2[n2].second){
            result = max(result, m1[n1].first + m2[n2].first);
        }else{
            if(m2.size()>1){
              result = max(result, m1[n1].first + m2[n2-1].first);
            }
            if(m1.size()>1){
                result = max(result, m1[n1-1].first + m2[n2].first);
            }
        }
    }


    for(auto &[next, w] : adj[node]) if(next!=parent) dfs2(next, node, adj, points);

  }


int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int N;
  cin>>N;
  vector<vector<pair<int,int>>> adj(N+1);
  vector<tuple<ll,ll,ll>> points(N+1);

  for(int i=0;i<N-1;i++){
    int a,b,w;
    cin>>a>>b>>w;
    adj[a].push_back(make_pair(b,w));
    adj[b].push_back(make_pair(a,w));
  }

  for(int i=1;i<=N;i++){
      ll a,b,c;
      cin>>a>>b>>c;
      points[i] = make_tuple(a,b,c);
  }

  dfs(1, -1, adj, points);
  dfs2(1, -1, adj, points);
  cout<<result;


  
  return 0;
}