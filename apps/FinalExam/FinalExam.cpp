// Final Exam P1
// Braden Owens
// 7/25/2022
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// create the stack to push the characters to and from
class Stack
{
public:
    char* arr;
    int top;
    unsigned cap;
};


Stack* create(unsigned cap)
{
    Stack* stack = new Stack();
    stack->cap = cap;
    stack->top = -1;
    stack->arr = new char[(stack->cap * sizeof(char))];
    return stack;
}


int empty(Stack* stack)
{
    return stack->top == -1;
}
int full(Stack*stack)
{
    return stack->top == stack->cap - 1;
}
char pop(Stack* stack)
{
    if (empty(stack))
        return -1;
    return stack->arr[stack->top--];
}

void push(Stack* stack, char item)
{
    if (full(stack))
        return;
    stack->arr[++stack->top] = item;
}

void reverse(char str[])
{
    int length = strlen(str);
    Stack* stack = create(length);
    for (int count = 0; count < length; count++)
        push(stack, str[count]);
    for (int count = 0; count < length; count++)
        str[count] = pop(stack);
}

int main()
{
    ifstream infile;
    infile.open("start.txt");
    string str;
    while (infile.is_open())
    {
        cin >> str;
    }
    cout << "The Reversed string: " << str << " was written to the text file labeled rev!" << endl;
    // i cannot figure out while my infile is not reading nor how to get it converted from string to character array. however my program works for normal char arrays.
    char str1[] = "Test";
    reverse(str1);
    cout << "This shows it works " << str1 << endl;
    infile.close();
    return 0;
}


