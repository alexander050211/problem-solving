#include <iostream>

int main(){
  using namespace std;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, x, n;
  bool minus, flag;
  cin >> t;
  for (int i = 0; i < t; i++){
    cin >> x;
    minus = (x - 1 < 0);
    x = abs(x - 1);
    n = 1;
    while (n * (n + 1) / 2 - 1 < abs(x)) n++;
    while (1){
      flag = true;
      if (n * (n + 1) / 2 - 1 == x){
        cout << n << '\n' << 1;
        if (!minus){
          for (int j = 2; j <= n; j++) cout << '+' << j;
        }
        else{
          for (int j = 2; j <= n; j++) cout << '-' << j;
        }
        cout << '\n';
        flag = false;
      }
      if (!flag) break;
      for (int a = 2; a <= n; a++){
        if (n * (n + 1) / 2 - 1 - 2 * a == x){
          cout << n << '\n' << 1;
          if (!minus){
            for (int j = 2; j <= n; j++){
              if (j != a) cout << '+' << j;
              else cout << '-' << j;
            }
          }
          else{
            for (int j = 2; j <= n; j++){
              if (j != a) cout << '-' << j;
              else cout << '+' << j;
            }
          }
          cout << '\n';
          flag = false;
          break;
        }
      }
      if (!flag) break;
      for (int a = 2; a <= n; a++){
        for (int b = a + 1; b <= n; b++){
          if (n * (n + 1) / 2 - 1 - 2 * (a + b) == x){
            cout << n << '\n' << 1;
            if (!minus){
              for (int j = 2; j <= n; j++){
                if (j != a && j != b) cout << '+' << j;
                else cout << '-' << j;
              }
            }
            else{
              for (int j = 2; j <= n; j++){
                if (j != a && j != b) cout << '-' << j;
                else cout << '+' << j;
              }
            }
            cout << '\n';
            flag = false;
            break;
          }
        }
        if (!flag) break;
      }
      if (!flag) break;
      for (int a = 2; a <= n; a++){
        for (int b = a + 1; b <= n; b++){
          for (int c = b + 1; c <= n; c++){
            if (n * (n + 1) / 2 - 1 - 2 * (a + b + c) == x){
              cout << n << '\n' << 1;
              if (!minus){
                for (int j = 2; j <= n; j++){
                  if (j != a && j != b && j != c) cout << '+' << j;
                  else cout << '-' << j;
                }
              }
              else{
                for (int j = 2; j <= n; j++){
                  if (j != a && j != b && j != c) cout << '-' << j;
                  else cout << '+' << j;
                }
              }
              cout << '\n';
              flag = false;
              break;
            }
          }
          if (!flag) break;
        }
        if (!flag) break;
      }
      if (!flag) break;
      n++;
    }
  }
  return 0;
}