#include <iostream>
#include <string>
#define Mod 1000000
using namespace std;

string pwd;
int len;
int dp[5001]={0,};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> pwd;
	
	len = pwd.length();
	dp[0] = dp[1] = 1;
	
	if(pwd[0]=='0'){
		cout << 0;
		return 0;
	} 
	
	for(int i=2; i<=len; i++){
		if(pwd[i-1]!='0') dp[i] = dp[i-1] % Mod;
		
		int temp = (pwd[i-2]-'0') * 10 + (pwd[i-1]-'0');
		if(temp>=10 && temp <=26)
			dp[i] = (dp[i]+dp[i-2]) % Mod;
	}
	
	cout << dp[len];
	
	return 0;
}