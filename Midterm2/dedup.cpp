// Deduplication with hash tables
#include <iostream>
#include <unordered_map>


using namespace std;

string dedup(const string line);

int main() {
    string line("the first second was alright but the second second was tough ");
    string dedupLine = dedup(line);
    cout << dedupLine << endl; // No repeatd words, ok if different order
}

string dedup(const string line) {
    unordered_map<string, string> mymap;
    string word = "";
    string return_str;
    for(auto x : line){
        if(x == ' '){
            mymap[word] = word;
            word = "";
        }
        else{
            word = word + x;
        }
    }

    for(auto y : mymap){
        return_str = return_str + " " + y.first;
    }
    return return_str;
}
