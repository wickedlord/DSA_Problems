#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main () {
    //creation
    unordered_map<string,int> m;

    //insert1
    pair<string,int> pair1 = make_pair("my",3);
    m.insert(pair1);

    //insert2 
    pair<string,int> pair2("name",2);
    m.insert(pair2);

    pair<string,int> pair3 = make_pair("is",4);
    m.insert(pair3);

    //printing
    for (auto i:m) {
        cout << i.first << " " << i.second << endl;
    }

    //deletion
    m.erase("name");

    //printing another method
    unordered_map<string,int>::iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    //size finder
    cout << "Size of the map is " << m.size() << endl;

    //unordered map uses hashtable to store the elements and they are not in order
    //ordered map or only map uses BST to store data and those are printed in order
}