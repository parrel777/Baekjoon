#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	long long total;
	int arr[100001];
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N, greater<int>());
	total = arr[0];
	
	for(int i=1; i<N; i++){
		long long temp = arr[i] * (i+1);
		if(total < temp){
			total = temp;
		}
	}
	
	cout << total;
	
	return 0;
}