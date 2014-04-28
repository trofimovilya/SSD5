/**
 * \file    main.cpp
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-04-22 10:02:50
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-04-28 22:18:05
 */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string strip_punct(const string& s);
void check_spelling(ifstream& in, Dictionary& dict);
void fix(const string& word, Dictionary& dict);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
        return EXIT_FAILURE;
    }

    ifstream inf(argv[2]);

    if (! inf) {
        cerr << "Could not open " << argv[2] << "\n";
        return EXIT_FAILURE;
    }

    // Read dictionary, but let user know what we are working on.
    cout << "Loading dictionary, this may take awhile...\n";

    Dictionary d(argv[1]);

    check_spelling(inf, d);

    inf.close();
    system("pause");
    return EXIT_SUCCESS;
}

void check_spelling(ifstream& in, Dictionary& dict) {

    int line_number = 0;

    while (in) {

        line_number++;

        string line;
        getline(in, line);

        stringstream ss(stringstream::in | stringstream::out);
        ss << line;

        string word;

        while (ss >> word) {

            // TODO: Complete the spell check of each word
            word = strip_punct(word);
            lower(word);

            if (dict.search(word)) {
                continue;
            }

            cout << "line " << line_number << ": '" << word << "' " << endl;
            cout << "\t" << "suggestions: " << endl;
            fix(word, dict);
        }

    }

}

void fix(const string& word, Dictionary& dict) {
    string expected;
    string wordPart;
    char temporaryChar;

    // insert
    for (int j = 'a'; j <= 'z'; j++) {

        expected = word;
        expected += (char)j;

        if (dict.search(expected)) {
            cout << "\t\t" << expected << endl;
        }
    }

    for (int i = 0; i < word.size(); i++) {
        // Swap
        if (i < word.size() - 1) {
            expected = word;
            temporaryChar = word[i];
            expected[i] = expected[i + 1];
            expected[i + 1] = temporaryChar;

            if (dict.search(expected)) {
                cout << "\t\t" << expected << endl;
            }
        }

        // Remove
        expected = word;

        if (word[i] != word[i + 1]) {
            expected.erase(i, 1);
        }

        if (dict.search(expected)) {
            cout << "\t\t" << expected << endl;
        }

        for (int j = 'a'; j <= 'z'; j++) {
            // Replace
            expected = word;
            expected[i] = (char)j;

            if (dict.search(expected)) {
                cout << "\t\t" << expected << endl;
            }

            if (word[i] == (char)j) {
                continue;
            }

            wordPart = word.substr(i, word.length() - i);
            expected = word.substr(0, i) + (char)j + wordPart;

            if (dict.search(expected)) {
                cout << "\t\t" << expected << endl;
            }

        }
    }
}

void lower(string& s) {

    // Ensures that a word is lowercase
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

string strip_punct(const string& s) {

    // Remove any single trailing
    // punctuation character from a word.
    if (ispunct(s[s.length() - 1])) {
        return s.substr(0, s.length() - 1);
    } else {
        return s;
    }
}
