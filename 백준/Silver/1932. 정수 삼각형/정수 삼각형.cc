#include <iostream>
#include <cmath>

using namespace std;

int N;
int dp[501][501];
int ans = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i=2; i<N+2; i++){
		for(int j=1; j<i; j++){
			int M;
			cin >> M;
			dp[i-j][j] = M + max(dp[i-j][j-1], dp[i-j-1][j]);
		}
	}
	
	for(int i=N; i>0; i--){
		for(int j=1; j<=N; j++){
			if(i+j == N+1 && ans < dp[i][j])
				ans = dp[i][j];
		}
	}
	
	cout << ans;
	
	return 0;
}