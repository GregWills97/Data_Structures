#include <iostream>
#include <vector>

using namespace std;

int numinv;

void mergeSort(vector<int>& numvec, vector<int>& temp, int left, int right);
int merge(vector<int>& numvec, vector<int>& temp, int left, int mid, int right);

int countInv(vector<int>& numvec) {
    numinv = 0;
    vector<int> temp(numvec);
    mergeSort(numvec, temp, 0, numvec.size() - 1);
    cout << "Sorted output: ";
    for (auto ele : numvec)
	    cout << ele << " ";
	cout << endl;
    return numinv;
    
}

//Sorts the input vector and returns the number of inversions in that vector
void mergeSort(vector<int>& numvec, vector<int>& temp, int left, int right){
    if(left >= right){
        return;
    }
    else{
    int middle = ((left + right) / 2); 
    mergeSort(numvec, temp, left, middle);
    mergeSort(numvec, temp, middle + 1, right);
    merge(numvec, temp, left, middle, right);
    }
}

int merge(vector<int>& numvec, vector<int>& temp, int left, int mid, int right){
    int l = left;
    int r = mid + 1;
    int i = l;

    while((l <= mid) && (r <= right)){
        if(numvec[l] <= numvec[r]){
            temp[i] = numvec[l];
            l++;
        } 
        else{
            temp[i] = numvec[r];
            r++;
            numinv += mid + 1 - l;
        }
        i++;
    }
    while(l <= mid){
       temp[i] = numvec[l];
       l++;
       i++;
    }
    while(r <= right){
       temp[i] = numvec[r];
       r++;
       i++;
    }
    for(int i = 0; i < temp.size(); i++){
        numvec[i] = temp[i];
    }  
}













