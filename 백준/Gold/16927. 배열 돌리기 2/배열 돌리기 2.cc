#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, R, p;
int arr[301][301];

void spin(int start, int r){
	int q = R % r;
	
	for(int i=0; i<q; i++){
		int tmp = arr[start][start];
		
		for(int j=start+1; j<M-start; j++) // high
			arr[start][j-1] = arr[start][j];
		for(int j=start+1; j<N-start; j++) // right
			arr[j-1][M - start - 1] = arr[j][M - start - 1];
		for(int j=M-start-2; j>=start; j--) // bottom
			arr[N - start - 1][j+1] = arr[N - start - 1][j];
		for(int j=N-start-2; j>=start; j--) // right
			arr[j+1][start] = arr[j][start];
		
		arr[start+1][start] = tmp;
	}
}

int main(){
	
	cin >> N >> M >> R;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}
	
	p = min(N, M) / 2;
	int n = N, m = M;
	
	for(int i=0; i<p; i++){
		spin(i, 2*n + 2*m - 4);
		n -= 2;
		m -= 2;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	return 0;
}