#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll check(int i, int j, int n, int m, vector<string> v){
	ll sum = 0;
	
//	left
	if(j-3 >= 0 && 
	v[i][j] == 'X' && v[i][j-1] == 'M' && v[i][j-2] == 'A' && v[i][j-3] == 'S'){
		sum++;
	}
	
//	right
	if(j+3 < m && 
	v[i][j] == 'X' && v[i][j+1] == 'M' && v[i][j+2] == 'A' && v[i][j+3] == 'S'){
		sum++;
	}
	
//	up
	if(i+3 < n && 
	v[i][j] == 'X' && v[i+1][j] == 'M' && v[i+2][j] == 'A' && v[i+3][j] == 'S'){
		sum++;
	}

//	down
	if(i-3 >= 0 && 
	v[i][j] == 'X' && v[i-1][j] == 'M' && v[i-2][j] == 'A' && v[i-3][j] == 'S'){
		sum++;
	}

//	le-up
	if(j-3 >= 0 && i+3 < n && 
	v[i][j] == 'X' && v[i+1][j-1] == 'M' && v[i+2][j-2] == 'A' && v[i+3][j-3] == 'S'){
		sum++;
	}

//	le-do
	if(j-3 >= 0 < m && i-3 >= 0 && 
	v[i][j] == 'X' && v[i-1][j-1] == 'M' && v[i-2][j-2] == 'A' && v[i-3][j-3] == 'S'){
		sum++;
	}

//	ri-up
	if(j+3 < m && i+3 < n && 
	v[i][j] == 'X' && v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' && v[i+3][j+3] == 'S'){
		sum++;
	}

//	ri-do
	if(j+3 < m && i-3 >= 0 && 
	v[i][j] == 'X' && v[i-1][j+1] == 'M' && v[i-2][j+2] == 'A' && v[i-3][j+3] == 'S'){
		sum++;
	}

	return sum;
}

ll resolve(vector<string> &v){
	int n = v.size();
	int m = v[0].size();
	
	ll total = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
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
//2545
