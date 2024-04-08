#include <iostream>
#include <cmath>

using namespace std;

int N, K, ans = 0;
int dp[100001] ={0,};

int main(){
	cin >> N >> K;
	
	while(N--){
		int W, V;
		cin >> W >> V;
		for(int i=K; i>=W; i--){
			dp[i] = max(dp[i-W] + V, dp[i]);
		}
	}
	
	for(int i=0; i<=K; i++){
		ans = ans < dp[i] ? dp[i] : ans;
	}
	
	cout << ans;
	
	return 0;
}