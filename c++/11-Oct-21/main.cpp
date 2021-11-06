#include <iostream>
#include <thread>

#define THREADS 8

int c = 0;
void check(int from, int to){
    for (int i = from; i < to; ++i) {
        for (int j = 0; j < 1000000; ++j) {
            if (i*i+j*j<1000000) c++;
            else break;
        }
    }
}

int main(){
    auto* array = new std::thread[THREADS];
    for (int i = 0; i < THREADS; ++i) {
        array[i] = std::thread(check, i*1000000/THREADS, (i+1)*1000000/THREADS);
    }

    for (int i = 0; i < THREADS; ++i) {
        array[i].join();
    }

    std::cout << c;
    return 0;
}
