#include <iostream>

using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001] = {0,};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	// len = 1, self
	for(int i=0; i<N; i++){
		dp[i][i] = 1;
	}
	
	// len = 2, my next
	for(int i=0; i<N-1; i++){
		if(arr[i] == arr[i+1])
			dp[i][i+1] = 1;
	}
	
	// len >= 3
	for(int len=2; len<N; len++){ // palindrom check length
		for(int i=0; i<N-len; i++){ // i = start idx
			int j = i + len;
			
			if(arr[i] == arr[j])
				dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = 0;
		}
	}
	
	cin >> M;
	
	for(int i=0; i<M; i++){
		int s, e;
		cin >> s >> e;
		cout << dp[s-1][e-1] << '\n';
	}
	
	
	return 0;
}