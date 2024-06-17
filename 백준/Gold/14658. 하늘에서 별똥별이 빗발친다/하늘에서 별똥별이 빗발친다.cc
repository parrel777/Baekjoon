#include <iostream>
#include <cmath>

using namespace std;

int N, M, L, K;
int ans = 0;
int arr_x[101];
int arr_y[101];

int main(){
	cin >> N >> M >> L >> K;
	
	for(int i=0; i<K; i++){
		cin >> arr_x[i] >> arr_y[i];
	}
	
	for(int i=0; i<K; i++){
		for(int j=0; j<K; j++){
			int cnt = 0;
			int nx = arr_x[i];
			int ny = arr_y[j];
			int mx = arr_x[i] + L;
			int my = arr_y[j] + L;
			
			for(int p=0; p<K; p++){
				if(arr_x[p] >= nx && arr_x[p] <= mx && arr_y[p] >= ny && arr_y[p] <= my){
					cnt++;
				}
			}
			
			ans = max(ans, cnt);
		}
	}
	
	cout << K - ans;
	
	
	return 0;
}