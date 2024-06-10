#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string a, b;
int dp[1001][1001];
int ans = 0;

int main(){
	cin >> a;
	cin >> b;
	
	int alen = a.length();
	int blen = b.length();
	
	for(int i=1; i<=alen; i++){
		for(int j=1; j<=blen; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
			}
			
			ans = max(ans, dp[i][j]);
		}
	}
	
	
	cout << ans;
	
	return 0;
}