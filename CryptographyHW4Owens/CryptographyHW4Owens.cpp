//Braden Owens
//Cryptography
#include<iostream>
#include<math.h>
#include <cstring>
using namespace std;
// we first create a prototype gcd function to check for coprime numbers
int greatestcommondiv(int, int);
int main() 
{
    cout << "Welcome to the RSA Encryption tool!" << endl;
    double check=0;
    double e = 7;
    // first we establish the values for p and q which were given to us
    double pvalue = 907;
    double qvalue = 773;
    cout << "P value= 907" << endl;
    cout << endl;
    cout << "Q value= 773" << endl;
    cout << endl;

    double pq = (pvalue * qvalue);
    double phi = (pvalue - 1) * (qvalue - 1);
    // we must check that e and phi(n) are coprime
    while (e < phi) {
        check = greatestcommondiv(e, phi);
        if (check == 1)
            break;
        else
            e++;
    }
  
    double d1 = 1 / e;
    double d = fmod(d1, phi);
    double msg = 97;
    //string message = "attackatdawn" << endl;
    //char msg2[100]='';
    //strcpy_s(msg2, sizeof(msg2),message);
    double cipher = pow(msg, e); 
    double message = pow(cipher, d);
    cipher = fmod(cipher, pq);
    message = fmod(msg, pq);
    cout << "Public Key= { " << e << ", "<< pq<<"}"<< endl;
    cout << "Private Key= { " << d << ", "<< pq<<"}"<< endl;
    cout << "The Original Message is: "<< msg<<" (which is ascii for a) "<<endl;
    cout << "The Encrypted message is: " << cipher<<endl;
    cout << "The Decrypted message is: " << message<<endl;
    cout << "I was not able to encrypt the entire plaintext attackatdawn, but i was able to encrypt a letter at a time, which means encrypting the whole string is possible " << endl;
    return 0;
}
int greatestcommondiv(int x, int y) {
    int temporary;
    while (1) {
        temporary = x % y;
        if (temporary == 0)
            return y;
        x = y;
        y = temporary;
    }
}


// Operating Systems Homework 1 
// Braden Owens
// January 17, 2023

#include <iostream>
#include <string>
#include <regex>
#include <vector>

//char** parseCommandLine(std::string aCommandLine)
{
    //char** ar = new char * [100]; //create a dynamically allocated array of characters
    //return ar;

}
int main()
{

}

