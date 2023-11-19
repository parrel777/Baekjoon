#include <iostream>

using namespace std;

int N, M;
int arr[1050][1050];
int dp[1050][1050];

int solve(int a, int b, int c, int d){
	int ans;
	
	ans = dp[c][d] + dp[a-1][b-1] - (dp[c][b-1] + dp[a-1][d]);
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	//init
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}
	
	// input
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> arr[i][j];
		}
	}
	//dp
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	
	//answer
	for(int i=0; i<M; i++){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << solve(y1, x1, y2, x2) << '\n';
	}
	
	return 0;
}