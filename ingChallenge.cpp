/****************************************************************************************
Write a function that takes a string as an argument and returns a
list of all the words inflected by "-ing". Your function should also
exclude all the mono-syllabic words ending in "-ing" (e.g. bing, sing, sling, ...).
Although these words end in "-ing", the "-ing" is not an inflection affix.

Examples
    ingExtractor("coming bringing Letting sing") ➞ ["coming", "bringing", "Letting"]
    ingExtractor("going Ping, king sHrink dOing") ➞ ["going", "dOing"]
    ingExtractor("zing went ring, ding wing SINk") ➞ []

Notes
    Mono-syllabic means a word containing just one syllable.
    It's probably best to use RegEx for this challenge.
*****************************************************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <cstring>
using namespace std;

bool isVowel(char c)
{
    // Convert character to lowercase to handle both cases
    c = tolower(c);

    // Check if it's one of the vowels
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

list<string> ingExtractor(string words)
{
    vector<string> allWords;
    vector<int> wordLengths;
    list<string> results;
    string currentWord = "";
    bool endWithIng;
    bool syllabul;

    char *wordsC = new char[words.length() + 1];
    strcpy(wordsC, words.c_str());

    // Split words into vector
    char *ptr = strtok(wordsC, " ");
    while (ptr != nullptr)
    {
        allWords.push_back(ptr);
        wordLengths.push_back(strlen(ptr));
        ptr = strtok(NULL, " ");
    }

    // Go through each word and check ends in ing and is < 1 syllabul (can't spell that!)
    for (int i = 0; i < size(allWords); i++)
    {
        string word = allWords.at(i);
        int index = wordLengths.at(i) - 3;
        string slice = word.substr(index);
        for (auto &&letter : slice) // Convert all letters in slice to lowercase
            letter = tolower(letter);
        endWithIng = slice == "ing" ? true : false;
        if (endWithIng) // Check syllabuls - general rule if > 5 letters fine, if == 5 letters second letter must be a vowel, if < 5 no
        {
            if (size(word) > 5)
            {
                syllabul = true;
            }
            else if (size(word) == 5)
            {
                char second = word.at(1);
                syllabul = isVowel(second) ? true : false;
            }
            else
                syllabul = false;
        }

        if (endWithIng && syllabul)
            results.push_back(word);
    }

    return results;
}

int main()
{
    list<string> test = ingExtractor("zing went ring, ding wing SINk");
    for (string word : test) 
    {
        cout << word << endl;
    }
    return 0;
}