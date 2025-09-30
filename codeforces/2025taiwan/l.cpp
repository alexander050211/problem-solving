#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<stack>
#include<algorithm>
#include<iomanip>
#include<queue>

using namespace std;
typedef long long ll;

int ccw(int x1, int y1, int x2, int y2){
    return x1*y2 - x2*y1;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;


    while(T--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int x3,y3,x4,y4;
        cin>>x3>>y3>>x4>>y4;
        if((x1<=x3 && x3<=x2 && y1<=y3 && y3<=y2) || (x1<=x4 && x4<=x2 && y1<=y4 && y4<=y2)){
            cout<<"STOP"<<'\n';
            continue;
        }
        vector<pair<int,int>> v;
        v.push_back(make_pair(x1, y1));
        v.push_back(make_pair(x1, y2));
        v.push_back(make_pair(x2, y2));
        v.push_back(make_pair(x2, y1));
        v.push_back(make_pair(x1, y1));
        bool thr = true;
        for(int i=0;i<=3;i++){
            vector<pair<int,int>> v2;
            v2.push_back(v[i]);
            v2.push_back(v[i+1]);
            v2.push_back(make_pair(x3, y3));
            v2.push_back(make_pair(x4, y4));
            int a = ccw(v[i+1].first-v[i].first,v[i+1].second-v[i].second, x3-v[i].first,y3-v[i].second) * ccw(v[i+1].first-v[i].first,v[i+1].second-v[i].second, x4-v[i].first,y4-v[i].second);
            int b = ccw(x4-x3, y4-y3, v[i].first-x3, v[i].second- y3) * ccw(x4-x3, y4-y3, v[i+1].first-x3, v[i+1].second- y3);
            if(a==0 && b==0){
                sort(v2.begin(), v2.end());
                if(v2[0]==make_pair(v[i].first, v[i].second) || v2[0]==make_pair(v[i+1].first, v[i+1].second)){
                    if(v2[1]==make_pair(v[i].first, v[i].second) || v2[1]==make_pair(v[i+1].first, v[i+1].second)){
                    }else{
                        thr=false;
                        break;
                    }
                }else{
                    if(v2[1]==make_pair(x3, y3) || v2[1]==make_pair(x4, y4)){}
                    else{
                        thr=false;
                        break;
                    }
                }
                continue;
            }

            if(a<=0 && b<=0){
                thr=false;
                break;
            }
            
        }
        if(thr){
            cout<<"OK"<<'\n';
        }else{
            cout<<"STOP"<<'\n';
        }
    


    }
    return 0;
}