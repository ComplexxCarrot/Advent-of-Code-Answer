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
	
	int n = 0; // number of data
	ll x, y; // get the input
	vector<int> a, b; // store our data into 2 lists
	while(!my_file.eof()) {
		my_file >> x >> y;
		a.push_back(x); // push the first number to a
		b.push_back(y); // push the second number to b
		n++; // increase total number of data we have
	}
	
	// close the file
	my_file.close();

	// sort our lists
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
	// calculate the difference
    ll diff = 0;
    for(int i = 0 ; i < n ; i++){
        diff += abs(a[i] - b[i]);
    }
    cout << diff << "\n";
}

int main() {
	solve();
    return 0;
}
//2378066
