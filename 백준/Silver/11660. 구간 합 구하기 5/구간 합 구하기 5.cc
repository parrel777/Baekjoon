#include <iostream>

using namespace std;

int N, M;
int arr[1050][1050];
int dp[1050][1050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	// input + dp
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> arr[i][j];
			dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	
	//answer
	for(int i=0; i<M; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = dp[c][d] + dp[a-1][b-1] - (dp[c][b-1] + dp[a-1][d]);
		cout << ans << '\n';
	}
	
	return 0;
}