#include <iostream>

using namespace std;

int arr[301];
int dp[301];

int main(){
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3]; 
	
	for(int i=4; i<=N; i++){
		dp[i] = max(dp[i-3] + arr[i-1], dp[i-2]) + arr[i];
	}
	
	cout << dp[N];
	return 0;
}