#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int T, N, K, W;

int main(){
	cin >> T;
	
	while(T--){
		vector<int> graph[1001];
		int inDegree[1001] = {0,};
		int time[1001];
		int end_time[1001];
		
		queue<int> q;
		
		cin >> N >> K;
		
		for(int i=1; i<=N; i++){
			cin >> time[i];
		}
		
		for(int i=0; i<K; i++){
			int p, q;
			cin >> p >> q;
			graph[p].push_back(q);
			inDegree[q]++;
		}
		
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
		
		cin >> W;
		cout << end_time[W] << '\n';
	}
	
	
	return 0;
}