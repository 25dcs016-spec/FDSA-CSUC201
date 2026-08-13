#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int max = 0;
    int count = 0;

    string a = "";
    string longest = "";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
        {
            if (count > max)
            {
                max = count;
                longest = a;
            }
            count = 0;
            a = "";
        }
        else
        {
            count++;
            a += sentence[i];
        }
    }

    // Check the last word
    if (count > max)
    {
        max = count;
        longest = a;
    }

    cout << "Length of longest word = " << max << endl;
    cout << "Longest word = " << longest << endl;

    return 0;
}