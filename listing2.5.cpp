/*
 * File: listing2.5.cpp
 * Project: ccia_code_samples-master
 * File Created: Tuesday, 19th July 2022 5:41:13 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <thread>

using namespace std;

void some_function()
{
}

void some_other_function(int)
{
}

std::thread f()
{
    void some_function();
    return std::thread(some_function);
}

std::thread g()
{
    void some_other_function(int);
    std::thread t(some_other_function, 42);
    return t;
}

int main(int argc, char **argv)
{
    std::thread t1 = f();
    t1.join();
    std::thread t2 = g();
    t2.join();
    return 0;
}