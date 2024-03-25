#include <iostream>
#include <cmath>

using namespace std;

int N, S, p, q;
int sum, len = 987654321;
int arr[100001];

int main(){
	cin >> N >> S;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	p = 0;
	q = 0;
	sum = arr[0];
	
	while(p <= q && q < N){
		if(sum >= S) 
			len = min(len, q - p + 1);
		
		if(sum < S){
			q++;
			sum += arr[q];
		}
		else{
			sum -= arr[p];
			p++;
		}
	}
	
	if(len == 987654321) cout << 0;
	else cout << len;
	
	return 0;
}