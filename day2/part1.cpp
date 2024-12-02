#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// convert to integer
int toInt(string& x){
	int res = 0;
	for(auto z: x){
		res *= 10;
		res += (z - '0');
	}
	return res;
}

// split the string into integers
vector<int> string_split(const string& str) {
	vector<int> result;
	istringstream iss(str);
	for (string s; iss >> s;){
		result.push_back(toInt(s));
	}
	return result;
}

// check if the list is valid or not
bool check(vector<int> &v, int ignore){
	bool increment = true; // increment or decrement

    // index to compare integers
    // important because we will ignore some index
	int idx1 = 0, idx2 = 1;
	int n = v.size();
	
	if(ignore == 0){
		idx1++;idx2++;
	}else if(ignore == 1){
		idx2++;
	}
	
	if(v[idx1] == v[idx2]) return false;
	if(v[idx1] > v[idx2]) increment = false;
	
	
	while(idx2 < n){
		if(increment){
			if(v[idx2] - v[idx1] < 1 || v[idx2] - v[idx1] > 3) return false;
		}else{
			if(v[idx1] - v[idx2] < 1 || v[idx1] - v[idx2] > 3) return false;
		}
		idx2++;
		idx1++;
		if(idx2 == ignore) idx2++; // pass the ignored index
		if(idx1 == ignore) idx1++; // pass the ignored index
	}
	return true;
}

void solve(){
	fstream my_file;
	my_file.open("day2.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	int safe = 0;
	string input;
	
	while(getline(my_file, input)){
		vector<int> arr = string_split(input);
		int n = arr.size();
		int ctr = 0;
		
		if(check(arr, -1)) safe++;
	}
	
	my_file.close();
    cout << safe << "\n";
}

int main() {
	solve();
    return 0;
}
//306
