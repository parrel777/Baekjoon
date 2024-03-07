#include <iostream>
#define Mod 1000000000
typedef long long ll;
using namespace std;

int N;
ll total = 0;
ll dp[101][10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i=1; i<=9; i++){
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	
	for(int i=2; i<=N; i++){
		for(int j=0; j<=9; j++){
			if(j==0) dp[i][j] = dp[i-1][j+1] % Mod;
			else if(j==9) dp[i][j] = dp[i-1][j-1] % Mod;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % Mod;
		}
	}
	
	for(int i=0; i<=9; i++){
		total = (total + dp[N][i]) % Mod;
	}
	
	cout << total;
	
	return 0;
}