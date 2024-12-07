#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// TODO: find faster solution
// current solution: brute force placing one wall in every possible place

//global variables
vector<string> maze;

// up, right, down, left
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
int idx_dir = -1;
int x, y;
int total = 0;

void bruteForce(){
	// will be very slow
	int n = maze.size(); // x size
	int m = maze[0].size(); // y size
	
	int idx_dir_temp = idx_dir;
	int x_temp = x;
	int y_temp = y;
	
	bool vis[4][200][200] = {0};
	while(true){
		if(vis[idx_dir_temp][x_temp][y_temp]){
			total++;return;
		}
		vis[idx_dir_temp][x_temp][y_temp] = true;
		
		// out of bound next move
		if(x_temp + x_dir[idx_dir_temp] < 0 || x_temp + x_dir[idx_dir_temp] >= n || 
		y_temp + y_dir[idx_dir_temp] < 0 || y_temp + y_dir[idx_dir_temp] >= m){
			return;
		}
		
		// in front of wall
		if(maze[x_temp + x_dir[idx_dir_temp]][y_temp + y_dir[idx_dir_temp]] == '#'){
			idx_dir_temp++;
			idx_dir_temp %= 4;
			continue;
		}
		
		// move
		x_temp += x_dir[idx_dir_temp];
		y_temp += y_dir[idx_dir_temp];
	}
}

void calculate(){
	// find position and direction
	int n = maze.size(); // x size
	int m = maze[0].size(); // y size
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(maze[i][j] == '^') idx_dir = 0;
			if(maze[i][j] == '>') idx_dir = 1;
			if(maze[i][j] == 'v') idx_dir = 2;
			if(maze[i][j] == '<') idx_dir = 3;
			
			if(idx_dir != -1){
				x = i;y = j;
				break;
			}
		}
		if(idx_dir != -1) break;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(maze[i][j] == '.'){
				maze[i][j] = '#';
				bruteForce();
				maze[i][j] = '.';
			}
		}
	}
	cout << total << "\n";
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
		maze.push_back(input);
	}

	my_file.close();
	calculate();
}

int main() {
	solve();
    return 0;
}
//1516
