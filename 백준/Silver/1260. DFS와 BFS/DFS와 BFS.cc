#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int arr[1001][1001];
bool visit[1001];
queue<int> q;

void reset(){
	for(int i=1; i<=N; i++){
		visit[i] = 0;
	}
}

void DFS(int v){
	visit[v] = true;
	cout << v << ' ';
	
	for(int i=1; i<=N; i++){
		if(arr[v][i] == 1 && visit[i] == false)
			DFS(i);
	}
}

void BFS(int v){
	q.push(v);
	visit[v] = true;
	cout << v << ' ';
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		for(int i=1; i<=N; i++){
			if(arr[v][i] == 1 && visit[i] == false){
				q.push(i);
				visit[i] = true;
				cout << i << ' ';
			}
		}
	}
}

int main(){
	cin >> N >> M >> V;
	
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	reset();
	DFS(V);
	
	cout <<'\n';
	
	reset();
	BFS(V);
	
	return 0;
	
}