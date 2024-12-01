#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){	
    // change the input.txt file according to your case

	fstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	int n = 0;
	ll x, y;
	vector<int> a, b;
	while(!my_file.eof()) {
		my_file >> x >> y;
		a.push_back(x);
		b.push_back(y);
		n++;
	}
	
	my_file.close();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
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
