#include <iostream>
#include <string>

using namespace std;

string s;

bool xwin(){
	// row
	for(int i=0; i<=6; i+=3){
		if(s[i] == 'X' && s[i] == s[i+1] && s[i] == s[i+2]) return true;
	}
	// column
	for(int i=0; i<=2; i++){
		if(s[i] == 'X' && s[i] == s[i+3] && s[i] == s[i+6]) return true;
	}
	// right up
	if(s[0] == 'X' && s[0] == s[4] && s[0] == s[8]) return true;
	// righ down 
	if(s[2] == 'X' && s[2] == s[4] && s[2] == s[6]) return true;
	
	return false;
}

bool owin(){
	// row
	for(int i=0; i<=6; i+=3){
		if(s[i] == 'O' && s[i] == s[i+1] && s[i] == s[i+2]) return true;
	}
	// column
	for(int i=0; i<=2; i++){
		if(s[i] == 'O' && s[i] == s[i+3] && s[i] == s[i+6]) return true;
	}
	// right up
	if(s[0] == 'O' && s[0] == s[4] && s[0] == s[8]) return true;
	// righ down 
	if(s[2] == 'O' && s[2] == s[4] && s[2] == s[6]) return true;
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while(1){
		int x=0, o=0;
		cin >> s;
		if(s.compare("end") == 0) break;
		
		for(int i=0; i<9; i++){
			if(s[i] == 'X') x++;
			else if(s[i] == 'O') o++;
		}
		
		if(o > x || x - o >= 2){
			cout << "invalid" << '\n';
			continue;
		}
		
		if(xwin() && !owin() && x == o+1) cout << "valid\n"; 
        else if(!xwin() && owin() && x == o) cout << "valid\n"; 
        else if(!xwin() && !owin() && x == 5 && o == 4) cout << "valid\n"; 
        else cout << "invalid\n"; 
	}
	
	
	return 0;
}