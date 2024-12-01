#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    // change the input.txt file according to your case

	// Read the input from file
	fstream my_file;
	my_file.open("input.txt", ios::in);

    // if we can't read the file
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	ll x, y; // get the input
	vector<int> lists; // list to store our data
	ll ctr[100000] = {0}; // ctr[x]: we use this to count the frequency of number x
	while(!my_file.eof()) {
		my_file >> x >> y;
		lists.push_back(x); // put first number on the list
		ctr[y]++; // add the frequency count of the second number
	}
	
    // close the file
	my_file.close();
    
    // calculate the score
    ll score = 0;
    for(auto x: lists){
        score += x * ctr[x];
    }
    cout << score << "\n";
}

int main() {
	solve();
    return 0;
}
//18934359
