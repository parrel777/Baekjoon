#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string a, b;
int dp[41][41] = {0,};
int ans = 0;
vector<char> v; 

int main(){
	cin >> a >> b;
	
	int alen = a.length();
	int blen = b.length();
	
	int ma=0, mb=0;
	
	// find LCS length, target i ans j
	for(int i=1; i<=alen; i++){
		for(int j=1; j<=blen; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			
			if(ans < dp[i][j]){
				ans = dp[i][j];
				ma = i;
				mb = j;
			}
		}
	}
	
	int temp = ans;
	
	while(temp > 0){
		if(dp[ma][mb-1] == temp){
			mb -= 1;
			continue;
		}
		
		if(dp[ma-1][mb] == temp){
			ma -= 1;
			continue;
		}
		
		ma -= 1;
		mb -= 1;
		temp -= 1;
		v.push_back(a[ma]);
	}
	
	for(int i=v.size()-1; i>=0; i--){
		cout << v[i];
	}
	
	
	return 0;	
}