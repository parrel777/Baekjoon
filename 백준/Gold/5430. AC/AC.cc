#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		string p; //function
		int n; //size of arr
		string input; //arr
		deque<int> dq; //arr to deque
		bool rev = false; //is reverse
		int D=0;
		string temp;
		
		cin >> p >> n >> input;
		
		//arr -> deque
		for(int i=0; i<input.length(); i++){
			if(isdigit(input[i]))
				temp += input[i];
			
			else{
				if(!temp.empty()){
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		
		for(int i=0; i<p.length(); i++){
			if(p[i]=='D') D++;
		}
		 
		//error
		if(D > dq.size()){
			cout << "error" << '\n';
			continue;
		}
		
		//R and D
		for(int i=0; i<p.length(); i++){
			if(p[i]=='R')
				rev = !rev;
			
			if(p[i]=='D' && rev==false)
				dq.pop_front();
			else if(p[i]=='D' && rev==true)
				dq.pop_back();
		}
			
		//cout answer
		if(rev){
			cout << '[';
			for(int i=dq.size()-1; i>=0; i--){
				if(i != dq.size()-1) cout << ',';
				cout << dq[i];
			}
			cout << ']' << '\n';
		}
		else{
			cout << '[';
			for(int i=0; i<dq.size(); i++){
				if(i != 0) cout << ',';
				cout << dq[i];
			}
			cout << ']' << '\n';
		}
	}
	
	return 0;
}