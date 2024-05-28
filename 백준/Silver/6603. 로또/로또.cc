#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int arr[14]= {0,};
bool visit[14] = {0,};
vector<int> v;

void bt(int cnt, int before){
	if(cnt == 6){
		for(int i=0; i<6; i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i=0; i<N; i++){
		if(!visit[i] && arr[i] > before){
			v.push_back(arr[i]);
			visit[i] = 1;
			bt(cnt+1, arr[i]);
			visit[i] = 0;
			v.pop_back();
		}
	}
}

int main(){
	
	while(1){
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		
		cin >> N;
		
		if(N == 0) break;
		
		for(int i=0; i<N; i++){
			cin >> arr[i];
		}
		
		bt(0, 0);
		cout << '\n';
	}
	
	
	
	return 0;
}