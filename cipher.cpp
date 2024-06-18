#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


using namespace std;



string caesar_cipher(const string &text, const string &key, bool encrypt=true) {
    string result = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipher_alphabet = "";

    // Convert key to lowercase
    string lowercase_key = "";
    for ( char c : key)
        lowercase_key += tolower(c);

    cipher_alphabet = lowercase_key;
    // Add remaining letters to the cipher  alphabet
    for (char c : alphabet) {
        if (lowercase_key.find(tolower(c)) == string::npos) {
            cipher_alphabet += c;
        }
    }
    // Convert text to lowercase
    string lowercase_text = "";
    for ( char c : text)
        lowercase_text += tolower(c);

    // loops through each character in lowered text
    for (char c: lowercase_text) {

        // checks if character is alphabetical
        if (isalpha(c)) {

            // A nested loop through each character in alphabet
            for (size_t i = 0 ; i < alphabet.size(); i++) {

               // A flag to detects whether it's encryption or decryption
                if (encrypt) {
                    // When find a character of alphabet in text, add the corresponded letter of cipher alphabet to result
                    if (c == alphabet[i]) {
                    result += cipher_alphabet[i];
                    break;
                    }
                }
                else {
                    // The opposite when decrypting
                    if (c == cipher_alphabet[i]) {
                    result += alphabet[i];
                    break;
                    }
                }
            }
        }

        // Leave any non alphabetical character unchanged to result
        else
            result += c;


    }
    return result;
}

int main() {
    string key;
    string text;
    bool encrypt = true;

    cout << "Welcome to the Substitution cipher program!\n";
    cout << endl;

    // Allow user to input again until valid input
     while (true) {
        cout << "Enter the key (5 unique letters): " << endl;
        cin >> key;
        cout << endl;
        // Validate key length
        if (key.length() != 5) {
            cout << "Invalid input. The key must be exactly 5 characters long." << endl;
            continue; // Prompt user again
        }

        // Validate alphabetic characters and unique letters
        bool valid = true;
        for (char c : key) {
            if (!isalpha(c)) {
                cout << "Invalid input. The key must consist of alphabetic characters only." << endl;
                valid = false;
                break; // Exit the loop if invalid
            }
            if (count(key.begin(), key.end(), c) != 1) {
                cout << "Invalid input. The key must consist of unique letters only." << endl;
                valid = false;
                break; // The same here
            }
        }
        if (!valid) continue; // Prompt user again if invalid

        // If we reach this point, the key is valid
        break;
    }


    while (true) {
        cout << "Do you want to encrypt or decrypt? (e/d): ";
        char choice;
        cin >> choice;
        choice = tolower(choice); // Convert choice to lowercase

        if (choice == 'e') {
            break; // Encryption chosen, exit loop
        }
        else if (choice == 'd') {
            encrypt = false; // Decryption chosen, set encrypt flag to false
            break; // Exit loop
        }
        else {
            cout << "Invalid choice. Please enter 'e' for encryption or 'd' for decryption." << endl;
        }
    }


    cout << "Enter the text: ";
    cin.ignore();
    getline(cin, text);
    cout << endl;

    string result = caesar_cipher(text, key, encrypt);
    if (encrypt)
        cout << "The ciphered text is: " << result << endl;
    else
        cout << "The decrypted text is: " << result << endl;
    return 0;
}


