#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//global variables
vector<string> maze;
int n, m; // maze limit
int total = 0;
vector<pair<int,int>> points[256]; // (x,y) points for each node

bool isSafe(int x, int y){
	if(x >= n || y >= m || x < 0 || y < 0) return false;
	return true;
}

void resolve(){
	n = maze.size();
	m = maze[0].size();
	
	// map all the possible nodes
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(maze[i][j] == '.') continue;
			points[maze[i][j]].push_back({i, j});
		}
	}
	
	// calculate the anti-nodes
	for(int node = 0 ; node < 256 ; node++){
		if(points[node].size() < 2) continue;
		
		int vector_x, vector_y;
		for(int i = 0 ; i < points[node].size() ; i++){
			for(int j = i+1 ; j < points[node].size() ; j++){
				int jx = (points[node][j].first);
				int jy = (points[node][j].second);
				int ix = (points[node][i].first);
				int iy = (points[node][i].second);
				
				vector_x = jx - ix;
				vector_y = jy - iy;
				
				int tempx = ix - vector_x;
				int tempy = iy - vector_y;
				
				while(isSafe(tempx, tempy)){
					if(maze[tempx][tempy] != '#'){
						total++;
						maze[tempx][tempy] = '#';
					}
					tempx -= vector_x;
					tempy -= vector_y;
				}
				
				tempx = ix + 2*vector_x;
				tempy = iy + 2*vector_y;
				while(isSafe(tempx, tempy)){
					if(maze[tempx][tempy] != '#'){
						total++;
						maze[tempx][tempy] = '#';
					}
					tempx += vector_x;
					tempy += vector_y;
				}
			}
		}
		
		for(int i = 0 ; i < points[node].size() ; i++){
			if(maze[points[node][i].first][points[node][i].second] != '#'){
				total++;
				maze[points[node][i].first][points[node][i].second] = '#';
			}
		}
	}
}

void solve(){
	fstream my_file;
	my_file.open("day7.txt", ios::in);
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
	resolve();
	cout << total << "\n";
}

int main() {
	solve();
    return 0;
}
//1184
