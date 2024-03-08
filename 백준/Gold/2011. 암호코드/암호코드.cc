#include <iostream>
#include <string>
#define Mod 1000000
typedef long long ll;
using namespace std;

string N;
int len;
bool last_zero = false;
ll dp[5001];
ll total = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	len = N.length();
	dp[0] = 1;
	
	if(N[len-1]== '0'){
		dp[1] = 0;
		last_zero = true;
	}
	else{
		dp[1] = 1;
	}
	
	for(int i=2; i<=len; i++){
		int a = N[len-i+1] - '0';
		int b = N[len-i] - '0';
		
		if(N[len-i] != '0'){
			int temp = b * 10 + a;
			if(temp < 27){
				dp[i] = (dp[i-1] + dp[i-2]) % Mod;
			}
			else{
				if(last_zero){
					cout << 0;
					return 0;
				}
				dp[i] = dp[i-1];
			}
			last_zero = false;
		}
		else{
			if(last_zero){
				cout << 0;
				return 0;
			}
			else{
				last_zero = true;
			}
		}
	}
	
	cout << dp[len];
	
	return 0;
}