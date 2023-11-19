#include <iostream>
#include <cmath>

using namespace std;

int N;
int R, G, B;
int total = 0;
int arr[1001][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;
	
	for(int i=1; i<=N; i++){
		cin >> R >> G >> B;
		arr[i][0] = R + min(arr[i-1][1], arr[i-1][2]);
		arr[i][1] = G + min(arr[i-1][0], arr[i-1][2]);
		arr[i][2] = B + min(arr[i-1][0], arr[i-1][1]);
	}
	
	cout << min(arr[N][0], min(arr[N][1], arr[N][2]));
	
	return 0;
}