#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[32001];
int inDegree[32001] = {0, };
queue<int> q;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int s = q.front();
		q.pop();
		cout << s << ' ';
		
		for(int i=0; i<graph[s].size(); i++){
			inDegree[graph[s][i]]--;
			
			if(inDegree[graph[s][i]] == 0){
				q.push(graph[s][i]);
			}
		}
	}
	
}


int main(){
	
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
		inDegree[q]++;
	}
	
	TopologySort();
	
	return 0;
}