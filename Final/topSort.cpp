// Topologically sort a directed graph. Assume graph is strongly connected.
// Your algorithm should be O(n) where n is the number of vertices in the graph

#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
vector<int> topSort(int A[N][N], int start);
void topHelper(int A[N][N], vector<int>& top_list, vector<bool>& v, int start);



int main() {
    int A[N][N] = { {0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0} };
 
    vector<int> res = topSort(A, 0);
    for (auto v : res) {
        cout << v << " "; // One possibility - 0 3 7 2 5 4 1 6 
    }
    cout << endl;
    return 0;
}

// Returns vertices in topologically sorted order.
// For example, if the vertices represent task dependencies, the topologically sorted order
// indicates the order in which the tasks should be performed

vector<int> topSort(int A[N][N], int start) {
	vector<bool> v;
	vector<int> top_list;
	for(int i = 0; i < N; i++){
		v.push_back(false);
	}
	topHelper(A, top_list, v, start);
	return top_list;
}

void topHelper(int A[N][N], vector<int>& top_list, vector<bool>& v, int source){
	v[source] = true;
	top_list.push_back(source);
	for(int i = 0; i < N; i++){
		if((A[source][i] == 1) && (!v[i])){
			topHelper(A, top_list, v, i);
		}
	}
}

