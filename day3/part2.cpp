#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool compareString(string s, int idx, string s2){
	int n = s.size();
	int n2 = s2.size();
	
//	compare it like this
//	superstringdo()xxd
//	           do()
	
	for(int i = idx, j = 0 ; i < n && i < idx+n2 ; i++, j++){
		if(s[i] != s2[j]) return false;
	}
	return true;
}

bool enabled = true; // global variable
ll resolve(string s){
	int n = s.size();
	ll sum = 0;
	for(int i = 0 ; i < n ; i++){
//		check if enabled
		if(compareString(s, i, "do()")){
//			cout << "trigger enable\n";
			enabled = true;
			i+=3;continue;
		}
		
//		check if disabled
		if(compareString(s, i, "don't()")){
//			cout << "trigger disable\n";
			enabled = false;
			i+=6;continue;
		}
		
//		check if it forms mul() perfectly
		if(i+0 >= n || s[i+0] != 'm') continue;
		if(i+1 >= n || s[i+1] != 'u') continue;
		if(i+2 >= n || s[i+2] != 'l') continue;
		if(i+3 >= n || s[i+3] != '(') continue;
		
		int j;
		int idx1 = i+4, idx2;
		ll num1 = 0, num2 = 0;
		for(j = i+4 ; j < n ; j++){
			if(s[j] < '0' || s[j] > '9') break;
			num1 *= 10;
			num1 += s[j] - '0';
		}
		
		if(s[j] != ',' || j == idx1) {
			i = j;continue;
		}
		
		j++;
		idx2 = j;
		for(; j < n ; j++){
			if(s[j] < '0' || s[j] > '9') break;
			num2 *= 10;
			num2 += s[j] - '0';
		}
		
		if(s[j] != ')' || j == idx2) {
			i = j;continue;
		}
		
		i = j;
		if(enabled) sum += num1 * num2;
//		if(enabled) cout << "got sum " << num1 << " * " << num2 << "\n";
	}
	return sum;
}

void solve(){
	fstream my_file;
	my_file.open("day3.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	ll total = 0;
	string input;
	while(getline(my_file, input)){
		// answer here
		total += resolve(input);
	}
	
	my_file.close();
    cout << total << "\n";
}

int main() {
	solve();
    return 0;
}
//100411201
