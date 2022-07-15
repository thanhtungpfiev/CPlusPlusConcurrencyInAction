/*
 * File: listing2.2.cpp
 * Project: CPlusPlusConcurrencyInAction
 * File Created: Wednesday, 13th July 2022 5:31:14 pm
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

void do_something_in_current_thread()
{
}

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        t.join();
        throw;
    }
    t.join();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    f();
    return 0;
}