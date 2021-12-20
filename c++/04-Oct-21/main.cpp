#include <iostream>

int main(int argc, char *argv[]) {
    int a = argc;
    int m, n;
    do {
        if (a < 3) {
            std::cout << "Enter m (height)\t";
            std::cin >> m;
            std::cout << "\nEnter n (count)\t";
            std::cin >> n;
            std::cout << std::endl;
        } else {
            m = std::stoi(argv[1]);
            n = std::stoi(argv[2]);
        }
        m--;
        a = 0;
    } while ((m<0)||(n<0));


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m-i; ++k) std::cout.put(' ');
            for (int k = 0; k < i*2+1; ++k) std::cout.put('*');
            for (int k = 0; k < m-i; ++k) std::cout.put(' ');
        }
        std::cout << std::endl;
    }
    for (int i = m; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m-i; ++k) std::cout.put(' ');
            for (int k = 0; k < i*2+1; ++k) std::cout.put('*');
            for (int k = 0; k < m-i; ++k) std::cout.put(' ');
        }
        std::cout << std::endl;
    }
    return 0;
}
