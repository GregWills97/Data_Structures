#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Helper function to print queue for debugging 

template<typename T> void printQueue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        cout << q_copy.top() << " ";
        q_copy.pop();
    }
    cout << endl;
}
 

vector<int> findMedian(vector<int>& data) {
    priority_queue<int> max_heap; // STL Max-heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // STL Min-heap
    
    vector<int> res;
    int temp;
    
    // Your code here 
    // Please comment out any debugging print outs

    for(int i = 0; i < data.size(); i++){
        if(i == 0){
            min_heap.push(data[0]);
        }
        else if(i == 1){
            if(min_heap.top() < data[1]){ 
                min_heap.pop();
                min_heap.push(data[1]);
                max_heap.push(data[0]);
            }
        }
        else{
            if(data[i] > min_heap.top()){
                if(min_heap.size() > max_heap.size()){
                    temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                }
                min_heap.push(data[i]);
            }
            else{
                if(max_heap.size() > min_heap.size()){
                    temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                }
                max_heap.push(data[i]);
            }
        }

        if(i % 2 == 0){
            if(min_heap.size() > max_heap.size()){
                res.push_back(min_heap.top());
            }
            else{
                res.push_back(max_heap.top());
            }
        }
        else{
            res.push_back((max_heap.top() + min_heap.top()) / 2);
        }
    }
    return res;
}



