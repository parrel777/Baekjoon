#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];

int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	int w=1;
	
	for(int i=0; i<N; i++){
		if(arr[i] > w)
			break;
		
		w += arr[i];
	}
	
	cout << w;
	
	return 0;
}