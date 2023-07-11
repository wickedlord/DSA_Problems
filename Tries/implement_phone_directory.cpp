#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data) {
            this->data = data;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root = NULL;
        
        Trie () {
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


        void printSuggestions(TrieNode* &curr, vector<string> &temp, string prefix) {
            //base case if we are standing on the last character
            if (curr->isTerminal) {
                temp.push_back(prefix);
            }

            for (char ch='a'; ch<='z'; ch++) {
                //checking all the children it has
                TrieNode* next = curr->children[ch-'a'];

                //means there is a child here
                if (next != NULL) {
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    //came back after backtracking, dry run to check
                    //going back to common node which supposedly has many children
                    prefix.pop_back();
                }
            }
        }


        vector<vector<string>> getSuggestions(string queryStr) {
            TrieNode* prev = root;
            vector<vector<string>> output;
            //prefix will store the chars'
            string prefix = "";

            for (int i=0; i<queryStr.length(); i++) {
                char lastChar = queryStr[i];
                prefix.push_back(lastChar);
                TrieNode* curr = prev->children[lastChar-'a'];

                if (curr == NULL) {
                    break;
                }

                //char is found
                vector<string> temp;
                // string currChar = "";
                // currChar.push_back(prefix);
                printSuggestions(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }

            return output;
        }
};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();
    //insert all the words in a trie
    for (int i=0; i<contactList.size(); i++) {
        t->insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr); 
}