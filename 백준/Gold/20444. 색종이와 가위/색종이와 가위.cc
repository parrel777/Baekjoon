#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long double N, K;
	cin >> N >> K;
	long double sq = sqrt(N*N + 4*(N-K+1));
	
	//not integ
	if(sq != (long long)sq){
		cout << "NO";
		return 0;
	}
	
	long double x = (N + sq) / 2.0;
	
	if(x = (long long)x && x>0)
		cout << "YES";
	else if(true){
		x = (N - sq) / 2.0;
		if(x==(long long)x && x>0)
			cout << "YES";
		
	}
	else
		cout << "NO";
	
	
	
	return 0;
}