#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data) {
            this->data = data;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root = NULL;
        
        Trie (char ch) {
            root = new TrieNode('\0');
        }

        void insertUtil (TrieNode* root, string word) {
            //base case, we have reached the end of word
            if (word.length() == 0) {
                root->isTerminal = true;
            }

            //search for the word, assuming all lettesr are uppercased
            int index = word[0] - 'a';
            TrieNode* child;

            //if its present
            if (root->children[index] != NULL) {
                child = root->children[index];
            }

            //absent
            else {
                root->childCount++;
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursive call, child is called and one letter of word is removed
            //also confirm the length of word is more than 1 for removing one char
            if (word.length() > 0) {
                insertUtil(child,word.substr(1));
            }    
        }

        void insertWord (string word) {
            insertUtil(root, word);
        }

        void lca(string first, string &ans) {
            for (int i=0; i<first.length(); i++) {
                char ch = first[i];

                if (root->childCount == 1) {
                    ans.push_back(ch);

                    //move ahead
                    int index = ch - 'a';
                    root = root->children[index];
                }

                else break;

                if (root -> isTerminal) {
                    break;
                }
            }
        }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    //inserting all strings in the trie
    for (int i=0; i<n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lca(first, ans);
    return ans;
}


int main () {
    vector<string> str;
    str.push_back("code");
    str.push_back("coding");
    str.push_back("coder");

    cout << longestCommonPrefix(str,str.size());
}