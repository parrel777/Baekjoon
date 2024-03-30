#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int N, T, M=0;
int inDegree[501] = {0,};
int time[501];
int end_time[501];
vector<int> graph[501];
queue<int> q;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
		end_time[i] = time[i];
	}
	
	while(!q.empty()){
		int a = q.front();
		q.pop();
		
		for(int i=0; i<graph[a].size(); i++){
			int temp = graph[a][i];
			inDegree[temp]--;
			end_time[temp] = max(end_time[temp], end_time[a] + time[temp]);
			
			if(inDegree[temp] == 0){
				q.push(temp);
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		cout << end_time[i] << '\n';
	}
	
}

int main(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		cin >> T;
		time[i] = T;
		while(true){
			cin >> M;
			if(M == -1) break;
			
			graph[M].push_back(i);
			inDegree[i]++;
		}
	}
	
	TopologySort();
	
	return 0;
}
