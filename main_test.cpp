#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

void trackTime(chrono::milliseconds interval, ostream& out)
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    for (int i = 0; i < 5; ++i) // Run for a few iterations for testing
    {
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        out << "\r" << fixed << setprecision(2) << elapsed_seconds.count() << " seconds" << flush;
        this_thread::sleep_for(interval);
    }
}

TEST_CASE("TrackTime Output Format")
{
    stringstream ss;
    trackTime(chrono::milliseconds(100), ss);
    string output = ss.str();
    // Check if the output contains " seconds"
    CHECK(output.find(" seconds") != string::npos);
    // Check if the output has a floating point number with 2 decimal places
    CHECK(output.find('.') != string::npos);
    size_t dot_pos = output.find('.');
    CHECK(isdigit(output[dot_pos + 1]));
    CHECK(isdigit(output[dot_pos + 2]));
}