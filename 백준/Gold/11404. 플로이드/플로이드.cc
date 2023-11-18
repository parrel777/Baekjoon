#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999

using namespace std;

int N, M;
int ans[101][101]; // min way
vector<pair<int, int> > d[100001]; // bus

void dijkstra(int start){
	ans[start][start] = 0;
	
	// pq <cost, end>
	priority_queue<pair<int, int> > pq; // min cost array
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int end = pq.top().second;
		pq.pop();
		
		// if now way is more cost, pass it
		if(ans[start][end] < cost)
			continue;
			
		int s = d[end].size();
		
		for(int i=0; i<s; i++){
			int next = d[end][i].first;
			int ncost = d[end][i].second;
			
			if(ans[start][next] > cost + ncost){
				ans[start][next] = cost + ncost;
				pq.push({-ans[start][next], next});
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
		int a, b, c; // a=start, b=end, c=cost
		cin >> a >> b >> c;
		d[a].push_back({b, c});
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			ans[i][j] = INF;
		}
	}
	
	for(int i=1; i<=N; i++){
		dijkstra(i);
		for(int j=1; j<=N; j++){
			if(ans[i][j] != INF)
				cout << ans[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
