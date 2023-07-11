#include <iostream>
#include <string>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isterminal;

        TrieNode (char ch) {
            data = ch;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isterminal = false;
        }
};

class Trie {
    public:
        TrieNode* root = NULL;

        //constructor
        Trie () {
            root = new TrieNode('\0');
        }

        void insertUtil (TrieNode* root, string word) {
            //base case, we have reached the end of word
            if (word.length() == 0) {
                root->isterminal = true;
            }

            //search for the word, assuming all lettesr are uppercased
            int index = word[0] - 'A';
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

        bool searchUtil (TrieNode* root, string word) {
            //base case
            if (word.length() == 0) {
                return root->isterminal;
            }

            //find element
            int index = word[0] - 'A';
            TrieNode* child;

            //if present
            if (root->children[index] != NULL) {
                child = root->children[index];
            }

            else return false;

            return searchUtil(child,word.substr(1));
        }

        bool searchWord (string word) {
            return searchUtil(root,word);
        }

        void deleteUtil (TrieNode* root, string word) {
            //base case, we have reached the end of word, so set isTerminal to
            //false, so word is never detected.
            if (word.length() == 0) {
                root->isterminal = false;

                //check if the last node has some other children
                //it could have it for other words
                bool hasChildren = false;
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        hasChildren = true;
                        break;
                    }
                }

                if (!hasChildren) {
                    delete root;
                }

                return;
            }

            //getting the word in the trie
            int index = word[0] - 'A';
            TrieNode* child = root->children[index];

            //recursive call, child is called and one letter of word is removed
            //also confirm the length of word is more than 1 for removing one char
            if (word.length() > 0) {
                deleteUtil(child,word.substr(1));
            }
        }

        void deleteWord (string word) {
            if (searchWord(word)) {
                deleteUtil(root, word);
                cout << "Word deleted successfully" << endl;
                return;
            }
            else {
                cout << "Word doesn't exist" << endl;
                return; 
            }
        }
};


int main () {
    Trie *t = new Trie();
    t->insertWord("TIME");
    // t->insertWord("ARM");
    // t->insertWord("CAT");

    cout << "TIME is present or not " << t->searchWord("TIME") << endl;
    cout << "Deleting word... " << endl;
    t->deleteWord("TIME");
    cout << "TIME is present or not " << t->searchWord("TIME");
}