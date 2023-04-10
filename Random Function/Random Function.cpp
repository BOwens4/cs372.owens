// This will create a random function we can use later
//Braden Owens
//2/6/2023
#include <iostream>
#include <random>
using namespace std;
int RANDOM(int a, int b)
{
    default_random_engine generate;
    uniform_int_distribution<int> distribute(a, b);
    int randomnum = distribute(generate);
    return randomnum;
}
int main()
{
    int a=0;
    int b=0;
    cout << "Please input the first number, a:" << endl;
    cin >> a;
    cout << "Please input the second number, b:" << endl;
    cin >> b;
    int result = 0;
    result=RANDOM(a, b);
    cout <<"Your random number is: "<< result << endl;
}

//works cited
//https://cplusplus.com/reference/random/
