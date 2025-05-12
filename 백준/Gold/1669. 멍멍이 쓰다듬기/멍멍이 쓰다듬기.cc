#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int distance = b - a;

    if (distance == 0){
      cout << 0 << '\n';
      return 0;
    }

    int n = (int)sqrt(distance); // n^2 <= distance
    if (n * n == distance) {
        cout << 2 * n - 1 << '\n';
    } else if (distance <= n * n + n) {
        cout << 2 * n << '\n';
    } else {
        cout << 2 * n + 1 << '\n';
    }

    return 0;
}
