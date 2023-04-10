
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

struct redirInputTypes{
    enum rITypes {redirInputNone,
        redirInputCreate,
        redirInputAppend};
};
struct redirOutputTypes {
    enum rOTypes {
        redirOutputNone,
        redirOutputCreate,
        redirOutputAppend
    };
};
typedef struct {
    size_t argc;
    char** argv;
    redirInputTypes::rITypes redirInput;
    redirOutputTypes::rOTypes redirOutput;
}ArguementStruct;

struct split {
    enum empties_t{empties_ok, no_empties};
};
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
