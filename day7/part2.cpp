#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//global variables
vector<ll> numList;
vector<int> operators;
ll target = 0;
ll total = 0;
bool flag;

void getValue(string input){
	numList.clear();
	
	ll num = 0;
	int idx;
	for(idx = 0; idx < input.size() ; idx++){
		if(input[idx] == ':') break;
		num *= 10;
		num += input[idx] - '0';
	}
	
	target = num;
	idx+=2;
	num = 0;
	
	for(; idx < input.size() ; idx++){
		if(input[idx] == ' '){
			numList.push_back(num);
			num = 0;
			continue;
		}
		num *= 10;
		num += input[idx] - '0';
	}
	numList.push_back(num);
}

ll concat(ll a, ll b){
	ll x = b;
	ll multiplier = 1;
	
	while(x){
		multiplier *= 10;
		x /= 10;
	}
	
	ll result = a * multiplier + b;
	return result;
}

void calculate(int idx){
	if(idx == numList.size()-1){
		ll sum = numList[0];
		for(int i = 0 ; i < operators.size() ; i++){
			if(operators[i] == 1){
				// multiplication
				sum *= numList[i+1];
			}else if(operators[i] == 0){
				// addition
				sum += numList[i+1];
			}else{
				sum = concat(sum, numList[i+1]);
			}
		}

		if(sum == target){
			flag = true;
			total += target;
		}
		return;
	}
	
	operators.push_back(0); // +
	calculate(idx+1);
	if(flag){
		operators.pop_back();
		return;
	}
	
	operators[idx] = 1; // *
	calculate(idx+1);
	if(flag){
		operators.pop_back();
		return;
	}
	
	operators[idx] = 2; // concat
	calculate(idx+1);
	operators.pop_back();
	return;
}

void solve(){
	fstream my_file;
	my_file.open("day6.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
		return;
	}
	
	string input;
	while(getline(my_file, input)){
		// answer here
		getValue(input);
		flag = false;
		calculate(0);
	}

	my_file.close();
	cout << total << "\n";
}

int main() {
	solve();
    return 0;
}
//328790210468594
