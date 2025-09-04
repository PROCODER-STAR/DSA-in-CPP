#include <iostream>
#include <cstring> 

using namespace std;

int main() {
    char temp1[100], temp2[100];

    cout << "Enter first word: ";
    cin >> temp1;
    cout << "Enter second word: ";
    cin >> temp2;

    char* word1 = new char[strlen(temp1) + 1];
    char* word2 = new char[strlen(temp2) + 1];

    strcpy(word1, temp1);
    strcpy(word2, temp2);

    int totalLength = strlen(word1) + strlen(word2) + 2;
    char* concatenated = new char[totalLength];

    strcpy(concatenated, word1);
    strcat(concatenated, " ");
    strcat(concatenated, word2);

    cout << "Concatenated String: " << concatenated << endl;

    delete[] word1;
    delete[] word2;
    delete[] concatenated;

    return 0;
}
