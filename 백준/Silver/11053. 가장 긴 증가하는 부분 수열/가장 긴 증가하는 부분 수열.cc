#include <iostream>

using namespace std;

int max(int a, int b){
	return (a > b)? a : b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int arr[1001];
	int dp[1001];
	int ans = 0;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int k=0; k<N; k++){
		dp[k] = 1;
		for(int i=0; i<k; i++){
			if(arr[i] < arr[k]){
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
		if(ans < dp[k]) ans = dp[k];
	}
	
	cout << ans;
	
	return 0;
}