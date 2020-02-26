// Heapsort implementation with STL
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> heapSort(const vector<int>& nums);

// Do not change main()
int main() {
    vector<int> nums = {5, 3, 9, 1, 7, 2, 6, 4};
    vector<int> sortedNums = heapSort(nums);
    for (auto n : sortedNums) {
        cout << n << " ";
    }
    cout << endl;
}

vector<int> heapSort(const vector<int>& nums) {
   priority_queue<int, vector<int>, greater<int>> min_heap; 
   vector<int> result;
   for(auto x : nums){
       min_heap.push(x);
   }
   
   while(!min_heap.empty()){
       result.push_back(min_heap.top());
       min_heap.pop();
   }
   return result;
}
