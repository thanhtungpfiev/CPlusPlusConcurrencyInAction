/*
 * File: listing2.7.cpp
 * Project: ccia_code_samples-master
 * File Created: Tuesday, 19th July 2022 5:54:08 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void do_work(unsigned int id)
{
}

void f()
{
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(do_work, i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main(int argc, char **argv)
{
    f();
    return 0;
}