#include <iostream>
#include <cmath>

using namespace std;

int N;
int maxdp[2][3];
int mindp[2][3];
int k=0;

int big(int x, int y, int z){
	return max(max(x, y), z);
}

int small(int x, int y, int z){
	return min(min(x, y), z);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		maxdp[k][0] = a + max(maxdp[1-k][0], maxdp[1-k][1]);
		maxdp[k][1] = b + big(maxdp[1-k][0], maxdp[1-k][1], maxdp[1-k][2]);
		maxdp[k][2] = c + max(maxdp[1-k][2], maxdp[1-k][1]);
		
		mindp[k][0] = a + min(mindp[1-k][0], mindp[1-k][1]);
		mindp[k][1] = b + small(mindp[1-k][0], mindp[1-k][1], mindp[1-k][2]);
		mindp[k][2] = c + min(mindp[1-k][2], mindp[1-k][1]);
		
		k = 1 - k;
	}
	
	cout << big(maxdp[1-k][0], maxdp[1-k][1], maxdp[1-k][2]) << ' ';
	cout << small(mindp[1-k][0], mindp[1-k][1], mindp[1-k][2]);
	
	return 0;
}