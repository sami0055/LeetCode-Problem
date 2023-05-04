#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    getline(cin, str); 
   
    stringstream ss(str);

    string word;
    vector<string> words; 

  
    while (ss >> word) {
        words.push_back(word);
        cout<<word<<endl;
    }

  
    reverse(words.begin(), words.end());

    // Create a new string with the reversed order of the words
    string reversed_str;
    for (auto& w : words) {
        reversed_str += w + " ";
    }

    // Output the reversed string
    cout << reversed_str << endl;

    return 0;
}
