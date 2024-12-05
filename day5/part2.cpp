#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//global variables
set<ll> backList[100]; // backList[x] numbers that need to be after x
vector<vector<ll> > queries; // queries of each line
ll total = 0; // total sum

void addDictionary(string s){
	ll x = (s[0] - '0')*10 + (s[1] - '0');
	ll y = (s[3] - '0')*10 + (s[4] - '0');
	backList[x].insert(y);
}

void addQuery(string s){
	ll num = 0;
	vector<ll> query;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == ','){
			query.push_back(num);
			num = 0;
		}else{
			num *= 10;
			num += s[i] - '0';
		}
	}
	query.push_back(num);
	queries.push_back(query);
}

void resolve(){
	int n;
	bool safe;
	for(auto query: queries){
		n = query.size();
		safe = true;
		for(int i = 0 ; i < query.size() ; i++){
//			check if there's a rule that the current order is breaking...
			for(int j = 0 ; j < i ; j++){
				auto setItr = backList[query[i]].lower_bound(query[j]);
				if(setItr != backList[query[i]].end() && (*setItr) == query[j]){			
					ll temp = query[i];
					query[i] = query[j];
					query[j] = temp;
					safe = false;//break;
				}
			}
		}
	
		if(!safe){
			total += query[n/2];
		}
	}
}

void solve(){
	fstream my_file;
	my_file.open("day5.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	string input;
	while(getline(my_file, input)){
		// answer here
		if(input == "") break;
		addDictionary(input);
	}
	cout << "dictionary done!\n";
	while(getline(my_file, input)){
		addQuery(input);
	}
	cout << "query done!\n";
	my_file.close();

	resolve();
	cout << "answer: " << total << "\n";
}

int main() {
	solve();
    return 0;
}
//5017
