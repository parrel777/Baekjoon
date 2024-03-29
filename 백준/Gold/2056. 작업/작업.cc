#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector<int> graph[10001];
vector<int> done[10001];
int time[10001];
int end_time[10001];
int inDegree[10001] = {0,};
queue<int> q;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 0){
			q.push(i);
			end_time[i] = time[i];
		}
	}
	
	while(!q.empty()){
		int s = q.front();
		q.pop();
		
		for(int i=0; i<graph[s].size(); i++){
			int temp = graph[s][i];
			
			done[temp].push_back(end_time[s]);
			inDegree[temp]--;
			
			if(inDegree[temp] == 0){
				q.push(temp);
				
				int max_time = 0;
				for(int j=0; j<done[temp].size(); j++){
					if(max_time < done[temp][j])
						max_time = done[temp][j];
				}
				end_time[temp] = max_time + time[temp];
			}
		}
	}
}


int main(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int t, k, m;
		cin >> t;
		time[i] = t;
		
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
		if(ans < end_time[i])
			ans = end_time[i];
	}
	cout << ans;
	
	return 0;
}