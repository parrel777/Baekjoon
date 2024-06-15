#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long T, K;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while(T--){
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		long long total = 0;
		cin >> K;
		
		for(int i=0; i<K; i++){
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		
		while(pq.size() > 1){
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			long long c = a + b;
			pq.push(c);
			total += c;
		}
		
		
		cout << total << '\n';
	}
	
	return 0;
}