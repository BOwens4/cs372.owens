//Braden Owens
//2/28/2023
//The Barbershop of Evil
//CS415- Operating Systems

#include <thread>
#include <mutex>
#include <iostream>
#include <random>
#include <condition_variable>
#include <chrono>
#include <thread>
using namespace std;


mutex BarberReady; //mutex 1: for whether the barber is ready or not
mutex waitChairsCanBeAccessed; //mutex 2: that protects the number of available waiting seats
condition_variable readyCustomers;
int readyc = 0;//condition variable that tracks number of customers in waiting room
int availseats = 0; //global counter for number of seats available
int amtcustomersleft = 0; //tracker for the number of customers that leave the shop
int haircutsgiven = 0; //tracker for the number of customers who received a haircut
bool complete = false;


void Barber()
{
    while (true)
    {
        unique_lock<mutex> barber_lock(BarberReady); // get the mutex for the barber ready
        unique_lock<mutex> chair_lock(waitChairsCanBeAccessed); //get the mutex for the chairs ready
        readyCustomers.wait(barber_lock,  [&]() { return readyc > 0 || complete; });//See if customer has arrived(readyCustomers unlocked& > 0)
        //Awake - acqure the customer chair mutex
        availseats++; //increment number of available seats
        barber_lock.unlock(); //unlocks the barber ready mutex
        chair_lock.unlock(); //unlocks the waiting chairs mutex
        cout << "The barber is now cutting hair" << endl;
        this_thread::sleep_for(chrono::seconds(rand()));//Cut hair for a random amount of time
        cout << "The barber is finished cutting hair" << endl;
        haircutsgiven++;
        barber_lock.lock();
        chair_lock.lock();

    }

}
void Customer()
{
    while (true)
    {
        unique_lock<mutex> chair2_lock(waitChairsCanBeAccessed);
        chair2_lock.lock(); //get the mutex for the chairs ready
        if (availseats > 0) //if there are seats available
        {
            availseats--;
            readyCustomers.notify_one();//Signal the readyCustomers condition variable
            chair2_lock.unlock();
            this_thread::sleep_for(chrono::seconds(rand()));//Wait until the barber is ready
            cout << "The barber is ready to give a haircut!" << endl;
            this_thread::sleep_for(chrono::seconds(rand()));//get a haircut for variable time
            cout << "The customer got a haircut, they are satisfied!" << endl;
            haircutsgiven++;
        }
        else // if there are no seats available
        {
            chair2_lock.unlock();
            amtcustomersleft++;
            cout << "The customer left the barbershop disappointed!" << endl;

        }

    }
}
int main()
{
    cout << "Welcome to the Barbershop"<<endl;
    for (int count = 0; count < 250; count++)
    {
        thread customer1(Customer); //2 threads representing the customers
        thread customer2(Customer); // 2 threads representing the customers
        customer1.join();
        customer2.join();
    }
    cout << "In total, " << amtcustomersleft << " customers left the shop without a haircut" << endl; //Display
    cout << "In total, " << haircutsgiven << " customers got a haircut at the barbershop" << endl; //Display
    return 0;
}
//https://cplusplus.com/reference/mutex/mutex/
//https://en.cppreference.com/w/cpp/thread/condition_variable
//https://www.softwaretestinghelp.com/cpp-sleep/
