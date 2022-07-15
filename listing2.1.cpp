/*
 * File: listing2.1.cpp
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Tuesday, 12th July 2022 5:54:45 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <thread>

using namespace std;

void do_something(int &i)
{
    ++i;
}

struct func
{
    int &i;
    func(int &i_) : i(i_) {}
    void operator()()
    {
        for (unsigned int j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}

int main(int argc, char **argv)
{
    oops();
    return 0;
}