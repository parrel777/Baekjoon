#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a;

  cin >> a;

  for (int i = 0; i < a; i++) {
    int b, c, ans=0;
    int arr[22] = {0,};
    int bag[10001] = {0,};

    cin >> b;
    for (int j = 1; j < b + 1; j++) {
      cin >> arr[j];
    }
    cin >> c;

    for (int k=1; k < b + 1; k++) {
      for (int j=0; j <= c; j++) {
        if(j >= arr[k]){
          bool isDiv = (j % arr[k]) == 0;
          // 나머지 있을때, 나머지 없을때
          bag[j] = max(bag[j-arr[k]] + bag[j], bag[j] + isDiv);
        }
        
      }
      
    }
    cout << bag[c] << '\n';
  }

  return 0;
}