#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <vector>



using namespace std;

bool vectorSort(const pair<string, int> &a, const pair<string, int> &b){
    return(a.second > b.second);
}


int main() {
    static const char* fileName = "programwordfile.txt";

    vector<pair<string, int>> v;
    map<string, unsigned int> wordCount;

    ifstream fileStream(fileName);

    if(fileStream.is_open()){
        while(fileStream.good()){
            string word;
            fileStream >> word;
            if(wordCount.find(word) == wordCount.end()){
                wordCount[word] = 1;
            } else {
                wordCount[word]++;
            }
        }
    } else {
        cout << "Couldn't open file" << endl;
    }



    for(auto it = wordCount.begin(); it!=wordCount.end(); ++it){

        v.push_back(make_pair(it->first, it->second));

    }

    sort(v.begin(), v.end(), vectorSort);

    cout << "Top 5 Word Occurences: " << endl;

    for(int i = 0; i < 5; i++){

        cout << v[i].first << ": " << v[i].second << endl;

    }



}
