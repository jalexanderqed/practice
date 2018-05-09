#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;

void foo() 
{
  mtx.lock();
  cout << "foo 1" << endl;
  mtx.unlock();
}

void bar(int x)
{
  mtx.lock();
  cout << "foo 2" << endl;
  mtx.unlock();
}

int main() 
{
  thread first (foo);
  thread second (bar,0);

  mtx.lock();
  cout << "main, foo and bar now execute concurrently..." << endl;
  mtx.unlock();

  first.join();
  second.join();

  cout << "foo and bar completed." << endl;

  return 0;
}
