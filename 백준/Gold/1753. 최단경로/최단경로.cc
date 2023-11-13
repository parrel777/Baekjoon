#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000

using namespace std;

int V, E, K;
int ans[20001];
vector<pair<int, int> > d[300001];

void dijkstra(int start){
	ans[start] = 0;
	
	// pq <cost, end>
	priority_queue<pair<int, int> > pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int end = pq.top().second;
		pq.pop();
		
		for(int i=0; i<d[end].size(); i++){
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
	
	cin >> V >> E >> K;
	
	for(int i=0; i<E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		
		// v <end, cost>
		d[u].push_back({v, w});
	}
	
	for(int i=1; i<=V; i++){
		ans[i] = INF; // w cant over 10
	}
	
	dijkstra(K);
	
	for(int i=1; i<=V; i++){
		if(ans[i] == INF)
			cout << "INF";
		else
			cout << ans[i];
			
		cout << '\n';
	}
	
	return 0;
}