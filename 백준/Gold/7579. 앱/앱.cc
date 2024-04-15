#include <iostream>

using namespace std;

int main(){
	int N, M;
	int total = 0;
	int app[102] = {0,};
	int mute[102] = {0,};
	int dp[100001] = {0,};
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		cin >> app[i];
	}

	for(int i=1; i<=N; i++){
		cin >> mute[i];
		total += mute[i];
	}
	
	for(int i=1; i<=N; i++){
		int W = mute[i];
		int V = app[i];
		
		for(int j=total; j>=W; j--){
			dp[j] = max(dp[j-W] + V, dp[j]);
		}
	}
	
	for(int i=0; i<=total; i++){
		if(dp[i] >= M){
			cout << i;
			break;
		}
	}
		
	return 0;	
}