#include <iostream>
#include <chrono>
#include <unistd.h>

using namespace std;

// C++ program to find the execution time of code
int main()
{
    int64_t prevTime;
    auto start = chrono::steady_clock::now();
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
     std::cout << now << std::endl;
    //sleep in seconds
    sleep(3);
    if(prevTime!=now){
    int64_t diff = now - prevTime;
    prevTime = now;
    std::cout << diff << std::endl;
    }
    //sleep in micro seconds
    usleep(100000);

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    cout << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;

    cout << "Elapsed time in milliseconds : "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    cout << "Elapsed time in seconds : "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";

    return 0;
}
