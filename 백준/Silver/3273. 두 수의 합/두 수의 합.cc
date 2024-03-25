#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
int p, q, cnt=0;
int arr[1000001];

int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	cin >> X;
	
	sort(arr, arr+N);
	
	p = 0;
	q = N-1;
	
	while(p < q){
		if(arr[p] + arr[q] == X){
			cnt++;
			p++;
			q--;
		}
		else if(arr[p] + arr[q] < X){
			p++;
		}
		else if(arr[p] + arr[q] > X){
			q--;
		}
	}
	
	cout << cnt;
	
	return 0;
}