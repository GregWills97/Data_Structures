// Find the number of connected components of an undirected graph
// Your algorithm should be of O(n) where n is the number of vertices in the graph

 
#include <iostream>
#include <vector>

using namespace std;

const int N = 6;
int A[N][N] = { {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0} };
int numConnectedComponents(int A[N][N]);
void DFSHelper(int A[N][N], int n, vector<bool>& v);


int main() {
    cout << numConnectedComponents(A) << endl; // Should output 3
}


int numConnectedComponents(int A[N][N]) {  
    vector<bool> v;
    int count = 0;
    for(int i = 0; i < N; i++){
		v.push_back(false);
	}
	for(int i = 0; i < N; i++){
		if(v[i] == false){
			DFSHelper(A, i , v);
			count += 1;
		}
	}
	return count;
}

void DFSHelper(int A[N][N], int n, vector<bool>& v){
	v[n] = true;
	for(int i = 0; i < N; i++){
		if((!v[i]) && (A[n][i] == 1)){
			DFSHelper(A, i, v);
		}
	}
}
