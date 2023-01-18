// Cryptography Assg 02
// Braden Owens
// 9/9/2022
// This program will act as the Vignere Cipher, and will encrypt and decrypt using the given plaintext and key


#include <iostream>
#include <string>
using namespace std;

class VignereCipher {
public:
    string key;
    VignereCipher(string key) {
        for (int count = 0; count < key.size(); count++) {
            if (key[count] >= 'A' && key[count] <= 'Z')
                this->key += key[count];
            else if (key[count] >= 'a' && key[count] <= 'z')
                this->key += key[count] + 'A' - 'a';
        }
    }
    string Vigneredecrypt(string text) {
        string result;
        for (int count = 0, count2 = 0; count < text.length(); count++) {
            char temp = text[count];
            if (temp >= 'a' && temp <= 'z')
                temp += 'A' - 'a';
            else if (temp < 'A' || temp > 'Z')
                continue;
            result += (temp - key[count2] + 26) % 26 + 'A';
            count2 = (count2 + 1) % key.length();
        }
        return result;
    }
    string Vignereencrypt(string text) {
        string result;
        for (int count = 0, count2 = 0; count < text.length(); count++) {
            char temp = text[count];
            if (temp >= 'a' && temp <= 'z')
                temp += 'A' - 'a';
            else if (temp < 'A' || temp > 'Z')
                continue;
            result += (temp + key[count2] - 2 * 'A') % 26 + 'A'; 
            count2 = (count2 + 1) % key.length();
        }
        return result;
    }
};
void openingdisplay()
{
    cout << "----------------------------------" << endl;
    cout << "Created By Braden Owens" << endl;
    cout << "Welcome to the Vignere Cipher Tool!" << endl;
    cout << "This program will take the the keyword and plaintext to accomplish a few tasks! " << endl;
    cout << "1. Encrypt the Plaintext with the key" << endl;
    cout << "2. Decrypt the Ciphertext with the key " << endl;
    cout << "3. Return the Ciphertext " << endl;
    cout << "----------------------------------" << endl;
    cout << "                                   " << endl;
    cout << "The given Plaintext: information warfare is any action to deny exploit ";
    cout << "corrupt or destroy the information of the enemy and its functions " << endl;
    cout << "                                   " << endl;
    cout << "The Key: wearethestudentsincsfoureightfour" << endl;

}

int main() {
    openingdisplay();
    VignereCipher key("wearethestudentsincsfoureightfour");
    string plaintext = "informationwarfareisanyactiontodenyexploitcorruptordestroytheinformationoftheenemyanditsfunctions";
    string encryptedplaintxt = key.Vignereencrypt(plaintext);
    string decryptedplaintxt= key.Vigneredecrypt(encryptedplaintxt);
    cout << "                                   " << endl;
    cout << "----------------------------------" << endl;
    cout << "The Plaintext before encryption: " << plaintext << endl;
    cout << "The Ciphertext: " << encryptedplaintxt << endl;
    cout << "The plaintext after decryption: " << decryptedplaintxt << endl;
    cout << "                                   " << endl;
    cout << "----------------------------------" << endl;
}