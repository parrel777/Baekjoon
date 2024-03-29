#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector<int> graph[10001];
int time[10001];
int end_time[10001];
int inDegree[10001] = {0,};
queue<int> q;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
		end_time[i] = time[i];
	}
	
	while(!q.empty()){
		int s = q.front();
		q.pop();
		
		for(int i=0; i<graph[s].size(); i++){
			int temp = graph[s][i];
			inDegree[temp]--;
			end_time[temp] = max(end_time[temp], end_time[s] + time[temp]);
			
			if(inDegree[temp] == 0){
				q.push(temp);
			}
		}
	}
}


int main(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int t, k, m;
		cin >> time[i];
		cin >> k;
		inDegree[i] += k;
		for(int j=0; j<k; j++){
			cin >> m;
			graph[m].push_back(i);
		}
	}
	
	TopologySort();
	
	int ans = 0;
	for(int i=1; i<=N; i++){
			ans = max(ans, end_time[i]);
	}
	cout << ans;
	
	return 0;
}