#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2000000000

using namespace std;

int N, p, q;
int result, A, B;
int arr[100001];

int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	p = 0;
	q = N-1;
	result = INF;
	
	while(p < q){
		int temp = arr[p] + arr[q];
		
		if(result > abs(temp)){
			result = abs(temp);
			A = arr[p];
			B = arr[q];
			
			if(result == 0) break;
		}
		
		if(temp < 0) p++;
		else q--;
	}
	
	cout << A << ' ' << B;
	
	return 0;
}