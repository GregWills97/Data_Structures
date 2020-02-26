#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);



vector<vector<string>> findAnagrams(const vector<string>& dict)
{
    unordered_map<string, vector<string>> mymap;
    vector<vector<string>> result;
    for(int i = 0; i < dict.size(); i++){           
        string key_str = dict[i];               //sort string in alphabetical order to use as a key
        sort(key_str.begin(), key_str.end());
        mymap[key_str].push_back(dict[i]);      //insert the word into the vector at that key
    }
    for(auto x : mymap){
        if(x.second.size() > 1){
            result.push_back(x.second);         //if the size of the vector is greater than one(meaning there are anagrams)
        }                                       //put into result vector
    }
   return result;
}
