#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[32001];
int inDegree[32001];
priority_queue<int, vector<int>, greater<int> > pq;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 0){
			pq.push(i);
		}
	}
	
	while(!pq.empty()){
		int a = pq.top();
		pq.pop();
		cout << a << ' ';
		
		for(int i=0; i<graph[a].size(); i++){
			int temp = graph[a][i];
			
			inDegree[temp]--;
			if(inDegree[temp] == 0){
				pq.push(temp);
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
