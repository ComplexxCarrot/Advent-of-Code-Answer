#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll check(int i, int j, int n, int m, vector<string> v){
	ll sum = 0;
//	M.M
//	.A.
//	S.S
	if(v[i][j] == 'M' && v[i][j+2] == 'M' && v[i+1][j+1] == 'A' &&
	v[i+2][j] == 'S' && v[i+2][j+2] == 'S'){
		sum++;
	}
	
//	M.S
//	.A.
//	M.S
	if(v[i][j] == 'M' && v[i+2][j] == 'M' && v[i+1][j+1] == 'A' &&
	v[i][j+2] == 'S' && v[i+2][j+2] == 'S'){
		sum++;
	}
	
//	S.S
//	.A.
//	M.M
	if(v[i+2][j] == 'M' && v[i+2][j+2] == 'M' && v[i+1][j+1] == 'A' &&
	v[i][j] == 'S' && v[i][j+2] == 'S'){
		sum++;
	}
	
//	S.M
//	.A.
//	S.M
	if(v[i][j+2] == 'M' && v[i+2][j+2] == 'M' && v[i+1][j+1] == 'A' &&
	v[i][j] == 'S' && v[i+2][j] == 'S'){
		sum++;
	}
	
	return sum;
}

ll resolve(vector<string> &v){
	int n = v.size();
	int m = v[0].size();
	
	ll total = 0;
	for(int i = 0 ; i < n-2 ; i++){
		for(int j = 0 ; j < m-2 ; j++){
			total += check(i, j, n, m, v);
		}
	}
	return total;
}

void solve(){
	fstream my_file;
	my_file.open("day4.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	ll total = 0;
	string input;
	vector<string> v;
	while(getline(my_file, input)){
		// answer here
		v.push_back(input);
	}
	
	my_file.close();
	cout << "answer: " << resolve(v) << "\n";
}

int main() {
	solve();
    return 0;
}
//1886
