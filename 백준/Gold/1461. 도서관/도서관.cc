#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int arr[51];
int total = 0;
int neg = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
		if(arr[i] < 0) neg++;
	}
	
	sort(arr, arr+N);
	
	// negative position
	for(int i=0; i<neg; i+=M)
		total += abs(arr[i] * 2);
	
	// positive position
	for(int i=N-1; i>=neg; i-=M)
		total += (arr[i] * 2);
		
	// max position 1 direction
	total -= max(abs(arr[0]), abs(arr[N-1]));
	
	cout << total;
	
	return 0;
}