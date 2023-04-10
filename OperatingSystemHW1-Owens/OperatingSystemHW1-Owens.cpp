//Operating Systems
//Braden Owens
//1/18/2023
#include <string>
#include <iostream>
#include <vector>
std::string const d{ "<,>,<<,>>,|" }; //maintain a constant list of delimiters
char** parseCommandLine(std::string aCommandLine) 
{ //function that will return double pointer to c array of strings
    int tokencount=0; //keep a count of tokens for creation of carray
    std::vector<std::string> v;
    std::cout << "Input a command line you wish to be parsed";
    std::cin >> aCommandLine; //input of string
    auto position = aCommandLine.find_first_of(d); //search string for delimeters
    while (position != std::string::npos) {
        aCommandLine[position] = '\n'; //create new line
        tokencount++; //token count
        position = aCommandLine.find_first_of(d);
        v.insert(v.end(),aCommandLine);
    }
    std::cout << aCommandLine;
    char** pointerarray = new char* [tokencount++];

    return pointerarray;
}

int main()
{
    std::string aCommandLine;
    std::cout << "Input a command line to be parsed  ";
    std::cin >> aCommandLine;// take in a command line arg
    parseCommandLine(aCommandLine);
}
//works used for reference
//https://www.reddit.com/r/cpp_questions/comments/wztagx/how_to_split_a_string_with_multiple_delimiters_in/
//https://stackoverflow.com/questions/37957080/can-i-use-2-or-more-delimiters-in-c-function-getline
//https://www.techiedelight.com/split-string-cpp-using-delimiter/
//https://cplusplus.com/reference/string/string/find_first_of/