#include <iostream>
#include <thread>
#include <mutex>


int myAmount = 0;
std::mutex m;

void addMoney() {
    m.lock();
    ++myAmount;
    m.unlock();
}

void function1() {
  

    for (int i = 0; i < 200; ++i) {
        {
            std::cout << "+";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    
}

void function2() {
     
     for (int j = 0; j < 200; ++j) {
         std::cout << "-";

         std::this_thread::sleep_for(std::chrono::milliseconds(10));
     }
}

int main() {

    std::cout<<"Amount: "<<myAmount;
    
    const int NUM_THREADS = 30000;

    std::thread threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = std::thread(addMoney);
    }

    for(int i = 0; i < NUM_THREADS; ++i) {
        if(threads[i].joinable()) {
            threads[i].detach();
        }
    }

    std::cout<<"Amount is now: "<<myAmount;

    return 1;
}