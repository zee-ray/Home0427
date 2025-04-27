// Matrix.h
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix{
    private:
        int r; int c;
        int **m;
        bool isEmpty()const{return(r==0&&c==0);}
        bool isSpuare()const{return (r==c);}
        bool sameSize(const Matrix& otherM)const{return (r==otherM.r && c==otherM.c);}
        Matrix det_expa(int col)const;
    public:
        Matrix() : r(0), c(0), m(nullptr){}
        Matrix(int rows, int cols);
        Matrix(const Matrix& otherM);
        ~Matrix();
        void clear();
        
        friend istream& operator>>(istream& in, Matrix& rhs);
        friend ostream& operator<<(ostream& out, const Matrix& rhs);
        
        friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
        friend Matrix operator*(int scalar, const Matrix& rhs);
        friend bool operator==(const Matrix& lhs, const Matrix& rhs);
        void operator=(const Matrix& rhs);

        int getcols()const{return c;}
        int getrows()const{return r;}
        
        int det()const;
        Matrix& inverse();
};