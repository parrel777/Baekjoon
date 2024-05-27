#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	int dp[10002][3] = {0,};
	
	cin >> N;
	
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	for(int i=4; i<=10000; i++){
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i-2][1] + dp[i-2][2];
		dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
	}
	
	for(int i=0; i<N; i++){
		int M;
		cin >> M; 
		cout << dp[M][1] + dp[M][2] + dp[M][3] << '\n';
	}
	
	return 0;
}