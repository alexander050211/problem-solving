#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n;
ll arr[1005];
vector<pll> v0;
vector<pair<vector<pll>,vector<pll>>> v1,v2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  pll temp={arr[0],arr[0]};
  for(int i=1; i<n; i++)
  {
    if(abs(arr[i]-temp.S)==1) temp.S=arr[i];
    else
    {
      v0.pb(temp);
      temp={arr[i],arr[i]};
    }
  }
  v0.pb(temp);
  if(v0.size()==1 && v0[0].F==1)
  {
    cout<<1<<' '<<1<<endl;
    cout<<1<<' '<<1<<endl;
    cout<<1<<' '<<1<<endl;
    return 0;
  }
  for(int i=0; i<v0.size(); i++)for(int j=i; j<v0.size(); j++)
  {
    vector<pll> temp;
    for(int k=0; k<i; k++) temp.pb(v0[k]);
    for(int k=j; k>=i; k--) temp.pb({v0[k].S,v0[k].F});
    for(int k=j+1; k<v0.size(); k++) temp.pb(v0[k]);
    vector<pll> temp2;
    ll st=0,en=0;
    while(en<temp.size())
    {
      while(en+1<temp.size() && abs(temp[en].S-temp[en+1].F)==1) en++;
      temp2.pb({temp[st].F,temp[en].S});
      st=en+1;
      en=st;
    }
    if(temp2.size()<=5)
    {
      ll cnt1=1;
      for(int k=0; k<i; k++) cnt1+=abs(temp[k].S-temp[k].F)+1;
      ll cnt2=cnt1-1;
      for(int k=i; k<=j; k++) cnt2+=abs(temp[k].S-temp[k].F)+1;
      v1.pb({temp2,{{cnt1,cnt2}}});
    }
    if(temp2.size()==1 && temp2[0].F==1)
    {
      ll cnt1=1;
      for(int k=0; k<i; k++) cnt1+=abs(temp[k].S-temp[k].F)+1;
      ll cnt2=cnt1-1;
      for(int k=i; k<=j; k++) cnt2+=abs(temp[k].S-temp[k].F)+1;
      cout<<cnt1<<' '<<cnt2<<endl;
      cout<<1<<' '<<1<<endl;
      cout<<1<<' '<<1<<endl;
      return 0;
    }
  }
  for(int i=0; i<v1.size(); i++)
    for(int j=0; j<v1[i].F.size(); j++)for(int k=j; k<v1[i].F.size(); k++)
    {
      vector<pll> temp;
      for(int l=0; l<j; l++) temp.pb(v1[i].F[l]);
      for(int l=k; l>=j; l--) temp.pb({v1[i].F[l].S,v1[i].F[l].F});
      for(int l=k+1; l<v1[i].F.size(); l++) temp.pb(v1[i].F[l]);
      vector<pll> temp2;
      ll st=0,en=0;
      while(en<temp.size())
      {
        while(en+1<temp.size() && abs(temp[en].S-temp[en+1].F)==1) en++;
        temp2.pb({temp[st].F,temp[en].S});
        st=en+1;
        en=st;
      }
      if(temp2.size()<=3)
      {
        v2.pb({temp2,v1[i].S});
        ll cnt1=1;
        for(int l=0; l<j; l++) cnt1+=abs(temp[l].S-temp[l].F)+1;
        ll cnt2=cnt1-1;
        for(int l=j; l<=k; l++) cnt2+=abs(temp[l].S-temp[l].F)+1;
        v2.back().S.pb({cnt1,cnt2});
      }
      if(temp2.size()==1 && temp2[0].F==1)
      {
        for(auto y:v1[i].S) cout<<y.F<<' '<<y.S<<endl;
        ll cnt1=1;
        for(int l=0; l<j; l++) cnt1+=abs(temp[l].S-temp[l].F)+1;
        ll cnt2=cnt1-1;
        for(int l=j; l<=k; l++) cnt2+=abs(temp[l].S-temp[l].F)+1;
        cout<<cnt1<<' '<<cnt2<<endl;
        cout<<1<<' '<<1<<endl;
        return 0;
      }
    }
  for(int i=0; i<v2.size(); i++)
    for(int j=0; j<v2[i].F.size(); j++)for(int k=j; k<v2[i].F.size(); k++)
    {
      vector<pll> temp;
      for(int l=0; l<j; l++) temp.pb(v2[i].F[l]);
      for(int l=k; l>=j; l--) temp.pb({v2[i].F[l].S,v2[i].F[l].F});
      for(int l=k+1; l<v2[i].F.size(); l++) temp.pb(v2[i].F[l]);
      vector<pll> temp2;
      ll st=0,en=0;
      while(en<temp.size())
      {
        while(en+1<temp.size() && abs(temp[en].S-temp[en+1].F)==1) en++;
        temp2.pb({temp[st].F,temp[en].S});
        st=en+1;
        en=st;
      }
      if(temp2.size()==1 && temp2[0].F==1)
      {
        for(auto y:v2[i].S) cout<<y.F<<' '<<y.S<<endl;
        ll cnt1=1;
        for(int l=0; l<j; l++) cnt1+=abs(temp[l].S-temp[l].F)+1;
        ll cnt2=cnt1-1;
        for(int l=j; l<=k; l++) cnt2+=abs(temp[l].S-temp[l].F)+1;
        cout<<cnt1<<' '<<cnt2<<endl;
        return 0;
      }
    }
  return 0;
}