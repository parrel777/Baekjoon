#include <iostream>

using namespace std;

void plug(int arr[], size_t) {
	
}

int main() {
	int N, K, cnt=0;
	int arr[102];
	int plug[102] = {0,};
	
	cin >> N >> K;
	
	for(int i=0; i<K; i++){
		cin >> arr[i];
	}
	
	for(int i=0; i<K; i++){
		bool skip = false;
		// already pluged
		for (int j=0; j<N; j++){
			if(arr[i] == plug[j]){
				skip = true;
				break;
			}
		}
		if(skip) continue;
		
		// plug empty
		for (int j=0; j<N; j++){
			if(plug[j] == 0){
				plug[j] = arr[i];
				skip = true;
				break;
			}
		}
		if(skip) continue;
		
		// unplug the last plug use
		int pos = -1;
		int last = -1;
		
		for(int j=0; j<N; j++){
			int far = 0;
			
			for(int k=i+1; k<K; k++){
				if(plug[j] == arr[k]) break;
				far++;
			}
			
			if(far > last) {
				pos = j;
				last = far;
			}
		}
		
		plug[pos] = arr[i];
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}