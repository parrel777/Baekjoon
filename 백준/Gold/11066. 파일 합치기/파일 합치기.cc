#include <iostream>
#include <cmath>
#define INF 987654321

using namespace std;

int T, K;
int dp[501][501] = {0,};
int sum[501];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while(T--){
		cin >> K;
		for(int i=1; i<=K; i++){
			int temp;
			cin >> temp;
			sum[i] = sum[i-1] + temp;
		}
		
		for(int len=1; len<K; len++){
			for(int i=1; i<=K-len; i++){
				int j = i + len;
				dp[i][j] = INF;
				
				for(int mid=i; mid<j; mid++){
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j] + sum[j] - sum[i-1]);
				}
			}
		}
		
		cout << dp[1][K] << '\n';
	}
	
	
	return 0;
}