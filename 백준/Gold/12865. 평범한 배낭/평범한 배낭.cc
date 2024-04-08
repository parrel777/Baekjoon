#include <iostream>
#include <cmath>

using namespace std;

int N, K;
int dp[101][100001] ={0,};

int main(){
	cin >> N >> K;
	
	for(int i=1; i<=N; i++){
		int W, V;
		cin >> W >> V;
		for(int j=1; j<=K; j++){
			dp[i][j] = j < W ? dp[i-1][j] : max(dp[i-1][j-W] + V, dp[i-1][j]);
		}
	}
	
	cout << dp[N][K];
	
	return 0;
}