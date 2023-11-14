#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, A, B;
int ans[1001]; // min way
vector<pair<int, int> > d[100001]; // all way

void dijkstra(int start){
	ans[start] = 0;
	
	// pq <cost, end>
	priority_queue<pair<int, int> > pq; // min cost array 
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int end = pq.top().second;
		pq.pop();
		
		// if now way is more cost, pass it
		if(ans[end] < cost)
			continue;
			
		int s = d[end].size();
		
		for(int i=0; i<s; i++){
			int next = d[end][i].first;
			int ncost = d[end][i].second;
			
			if(ans[next] > cost + ncost){
				ans[next] = cost + ncost;
				pq.push({-ans[next], next});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int u, v, w;
		// start, end, cost
		cin >> u >> v >> w;
		
		// v <end, cost>
		d[u].push_back({v, w});
	}
	
	for(int i=1; i<=N; i++){
		ans[i] = INF;
	}
	
	cin >> A >> B;
	
	dijkstra(A);
	
	cout << ans[B];
	
	return 0;
}