#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//global variables
vector<string> maze;
bool vis[200][200] = {0};
// up, right, down, left
int x_dir[4] = {-1, 0, 1, 0};
int y_dir[4] = {0, 1, 0, -1};
int idx_dir = -1;
int x, y;
int total = 0;

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
	
	while(true){
		// current state
		if(!vis[x][y]){
			total++;
			vis[x][y] = true;
//			maze[x][y] = 'X';
//			cout << "record (" << x << ", " << y << ")\n";
		}
		
		// out of bound next move
		if(x + x_dir[idx_dir] < 0 || x + x_dir[idx_dir] >= n || y + y_dir[idx_dir] < 0 || y + y_dir[idx_dir] >= m){
			break;
		}
		
		// in front of wall
		if(maze[x + x_dir[idx_dir]][y + y_dir[idx_dir]] == '#'){
			idx_dir++;
			idx_dir %= 4;
			continue;
		}
		
		// move
		x += x_dir[idx_dir];
		y += y_dir[idx_dir];
	}
	cout << total << "\n";
//	for(int i = 0 ; i < n ; i++){
//		cout << maze[i] << "\n";
//	}cout << "\n";
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
//4433
