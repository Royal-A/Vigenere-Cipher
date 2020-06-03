#include <iostream>
#include <iomanip>
#include <string>                                                                    //getline()
#include <algorithm>                                                                 //transform()

using namespace std;

string encode(string message, string key) {                                         //function to encrypt message
    string output= "";
    int j = 0;
    for (int i = 0; i < message.length(); i++) {
        if ((message[i] >= 97 && message[i] <= 122)) {                              //checks if the current char is a lowercase letter.
            output += char((int(message[i] - 97) + int(key[j] - 97)) % 26 + 97);    //appends encrypted letter to string "output"
            j = (j + 1) % key.length();                                             //iterator for "key" string. Will loop back to first letter via Modulo
        }
        else if ((message[i] >= 65 && message[i] <= 90)) {                          //checks if the current char is an uppercase letter.
            output += char((int(message[i] - 65) + int(key[j] - 97)) % 26 + 65);    //appends encrypted letter to string "output"
            j = (j + 1) % key.length();                                             //iterator for "key" string. Will loop back to first letter via Modulo
        }
        else
            output += message[i];                                                   //appends characters that doesn't meet criteria for encryption
    }
    return output;                                                                  //returns encrypted message
}

string decode(string message, string key) {                                         //function to decrypt message
   string output = "";
   int j = 0;
   for (int i = 0; i < message.length(); i++) {
        if ((message[i] >= 97 && message[i] <= 122)) {                              //checks if the current char is a lowercase letter. Anything else will be ignored
            output += char((int(message[i])-int(key[j])+26)% 26 + 97);              //appends decrypted letter to string "output"
            j = (j + 1) % key.length();                                             //iterator for "key" string. Will loop back to first letter via Modulo
        }
        else if ((message[i] >= 65 && message[i] <= 90)) {                          //checks if the current char is a lowercase letter. Anything else will be ignored
            output += char((int(message[i]) - int(key[j]) + 26) % 26 + 65);         //appends decrypted letter to string "output"
            j = (j + 1) % key.length();                                             //iterator for "key" string. Will loop back to first letter via Modulo
        }
        else
            output += message[i];                                                   //appends characters that doesn't meet criteria for encryption
    }
    return output;
}


int main(){
    string message;                                                                 //holds the message that will be encrypted/decrypted
    string key;                                                                     //holds key that will be used to encrypt or decrypt message
    bool validselection=false;                                                      //used to select if the message will be encoded or decoded. 1 is for encoding, 2 for decoding.
    cout << "--Vigenere Cipher Encrypting/Decryption--\n\n";

    cout << "Please enter your message: \n";
    getline(cin, message);                                                          ////user input for string "message". using getline because cin ignores whitespaces for some reason.
    cout << "Please enter your key: \n";
    getline(cin, key);                                                              //user input for string "key"
    transform(key.begin(), key.end(), key.begin(), ::tolower);                      //converts string "key" to all lowercase. It shouldn't matter what case the key comes in so I might as well make it consistant
    cout<<"Message: "<<encode(message, key);                                 
}
