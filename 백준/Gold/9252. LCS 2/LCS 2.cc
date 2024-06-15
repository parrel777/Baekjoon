#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int dp[1002][1002] = {0,};
string a, b;
vector<char> v;
int la, lb;
int x, y, cnt=0;

int main(){
	cin >> a >> b;
	
	la = a.length();
	lb = b.length();
	
	for(int i=1; i<=la; i++){
		for(int j=1; j<=lb; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			
			cnt = max(cnt, dp[i][j]);
		}
	}
	
	x = la;
	y = lb;
	
	while(cnt > 0){
		if(dp[x][y] == dp[x-1][y]){
			x--;
			continue;
		}
		
		if(dp[x][y] == dp[x][y-1]){
			y--;
			continue;
		}
		
		x--;
		y--;
		v.push_back(a[x]);
		cnt--;
	}
	
	int len = v.size();
	cout << len << '\n';
	
	for(int i=len; i>0; i--){
		cout << v[i-1];
	}
	
	return 0;
} 