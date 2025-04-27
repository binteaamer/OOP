#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream create_file("data.txt");
    if (create_file.is_open())
    {
        create_file << "AI is the future.\nAI will transform the world.\nEmbrace AI now." << endl;
        create_file.close();
    }
    else
    {
        cout << "Cannot create a file." << endl;
        return 1;
    }

    string searchWord, replacementWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    cout << "Enter a word to replace the searched word: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length())
    {
        cout << "Replacement word must be equal or smaller in length than the search word." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Cannot open the file!" << endl;
        return 1;
    }

    char ch;
    string word;
    streampos pos;

    while (true)
    {
        pos = file.tellg();
        word = "";

        for (int i = 0; i < searchWord.length(); i++)
        {
            file.get(ch);
            if (file.eof())
                break;
            word += ch;
        }

        if (file.eof())
            break;

        if (word == searchWord)
        {
            file.seekp(pos);
            file << replacementWord;

            for (size_t i = replacementWord.length(); i < searchWord.length(); i++)
            {
                file.put(' ');
            }

            file.seekg(pos + (streamoff)searchWord.length());
        }
        else
        {
            file.seekg(pos + (streamoff)1);
        }
    }

    file.close();

    ifstream read("data.txt");
    if (read.is_open())
    {
        cout << "\nUpdated File Content:" << endl;
        string line;
        while (getline(read, line))
        {
            cout << line << endl;
        }
        read.close();
    }
    else
    {
        cout << "Cannot open the file!" << endl;
        return 1;
    }

    return 0;
}
