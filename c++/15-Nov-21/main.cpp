#include <iostream>

#include <iostream>

template <typename T>
class Matrix{
private:

public:
    T** container;
    int rows;
    int cols;

    Matrix(int rows, int cols){
        this->rows = rows;
        this->cols = cols;
        container = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            container[i] = new T[cols];
        }
    }

    Matrix(Matrix<T>* matrix, int a, int b) {
        this->rows = matrix->rows-1;
        this->cols = matrix->cols-1;

        container = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            container[i] = new T[cols];
        }

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) container[i][j] = matrix->container[i][j];
            for (int j = b+1; j < cols+1; ++j) container[i][j-1] = matrix->container[i][j];
        }
        for (int i = a+1; i < rows+1; ++i) {
            for (int j = 0; j < b; ++j) container[i-1][j] = matrix->container[i][j];
            for (int j = b+1; j < cols+1; ++j) container[i-1][j-1] = matrix->container[i][j];
        }
    }

    ~Matrix(){
        for (int i = 0; i < rows; ++i) {
            delete[] container[i];
        }
        delete[] container;
    }

    void print(const char pre[] = ""){
        std::cout << pre;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << container[i][j] << '\t';
            }
            std::cout << std::endl;
        }
    }

    T det(){
        if (rows!=cols) throw "Unable to calculate determinant";

        T** tcontainer = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            tcontainer[i] = new T[rows];
            for (int j = 0; j < rows; ++j) {
                tcontainer[i][j] = container[i][j];
            }
        }

        T tmp;
        for (int i = 0; i < rows-1; ++i) {
            for (int j = i+1; j < rows; ++j) {
                tmp = tcontainer[j][i] / tcontainer[i][j];
                for (int k = i; k < rows; ++k) {
                    tcontainer[j][k] -= tcontainer[i][k]*tmp;
                }
            }
        }

        double det = 1;
        for (int i = 0; i < rows; ++i) {
            det = det * tcontainer[i][i];
        }


        for (int i = 0; i < rows; ++i) {
            delete[] tcontainer[i];
        }
        delete[] tcontainer;

        return det;

    }

    void inv(){
        T det = this->det();
        if (det == 0) throw "Determinant = 0";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                Matrix<T> A(this, i, j);
                container[i][j] = A.det()/det;
                if ((i+j)%2) container[i][j] = container[i][j] * (-1);
                container[i][j] = container[i][j] == 0 ? 0 : container[i][j];
            }
        }
    }
};


int main() {
    srandom(time(0));
    int n = 3;
    Matrix<double> A(n,n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A.container[i][j] = random() % 25 + 1;
        }
    }
    A.print("A= \n");
    std::cout << A.det() << "\n";
    A.inv();
    A.print();

}

template <typename T>
T** matrixminor(T** M, int n, int a, int b)
{
    T** A = creatematrix<T>(n - 1, n - 1);
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            A[i][j] = M[i][j];
        }
        for (int j = b + 1; j < n; ++j)
        {
            A[i][j - 1] = M[i][j];
        }
    }
    for (int i = a + 1; i < n; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            A[i - 1][j] = M[i][j];
        }
        for (int j = b + 1; j < n; ++j)
        {
            A[i - 1][j - 1] = M[i][j];
        }
    }
    return A;
}