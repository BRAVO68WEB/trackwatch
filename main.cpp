#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    while (true)
    {
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\r" << fixed << setprecision(2) << elapsed_seconds.count() << " seconds" << flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}