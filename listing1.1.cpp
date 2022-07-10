/*
 * File: listing1.1.cpp
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Sunday, 10th July 2022 2:39:23 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << "Hello Concurrent World" << endl;
}

int main(int argc, char **argv)
{
    thread t(hello);
    t.join();
    cout << "Hello World" << endl;
    return 0;
}