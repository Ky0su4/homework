#include <iostream>

int** snail(int n, int m) {
    int **array = new int *[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];

    }
    int counter = 0;

    int i = 0;
    int j = 0;
    int mx = n * m;
    for (int offset = 0; counter < mx; ++offset) {
        for (; i < m-offset-1; ++i)
            array[j][i] = ++counter;
        for (; j < n-offset-1; ++j)
            array[j][i] = ++counter;
        for (; i > offset; --i)
            array[j][i] = ++counter;
        for (; j > offset; --j)
            array[j][i] = ++counter;
        i = offset + 1;
        j = offset + 1;
    }

    return array;
}

void shiftArray(int A[], int n, int k){
    std::reverse(A, A+k);
    std::reverse(A+k, A+n);
    std::reverse(A, A+n);
}

int main() {
    int** array = snail(5,9);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    int A[] = {1,2,3,4,5,6,7,8,9};
    shiftArray(A,9,2);
    std::cout << std::endl;

    for (auto c:A) {
        std::cout << c << '\t';
    }


    return 0;
}
