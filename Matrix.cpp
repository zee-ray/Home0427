#include "Matrix.h"
using namespace std;
Matrix::Matrix(int rows, int cols){
    r = rows; c = cols;
    m = new int*[r];
    for(int i=0; i<r; i++){
        m[i] = new int[c]{0};
    }
}
Matrix::Matrix(const Matrix& otherM){
    r = otherM.getrows(); c = otherM.getcols();
    m = new int*[r];
    for(int i=0; i<r; i++){
        m[i] = new int[c];
        for(int j=0; j<c; j++){
            m[i][j] = otherM.m[i][j];
        }
    }
}
Matrix::~Matrix(){
    clear();
}
void Matrix::clear(){
    for(int i=0; i<r; i++){
        delete [] m[i];
        m[i] = nullptr;
    }
    delete [] m;
    m = nullptr;
    // cout<<"Matrix deleted !"<<endl;
}
istream& operator>>(istream& in, Matrix& rhs){
    // delete old one
    rhs.clear();
    // first enter num of row and col
    in>>rhs.r>>rhs.c;
    // then enter elements
    rhs.m = new int*[rhs.r];
    for(int i=0; i<rhs.r; i++){
        rhs.m[i] = new int[rhs.c];
        for(int j=0; j<rhs.c; j++){
            in>>rhs.m[i][j];
        }
    }
    return in;
}
ostream& operator<<(ostream& out, const Matrix& rhs){
    if(rhs.isEmpty())   cout<<"Empty Matrix\n";
    for(int i=0; i<rhs.r; i++){
        for(int j=0; j<rhs.c; j++){
            out<<setw(4)<<rhs.m[i][j];
        }
        out<<endl;
    }
    return out;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs){
    if(!lhs.sameSize(rhs)){
        cout<<"Error: this two matrix have diff size!"<<endl;
        return Matrix();
    }else{
        Matrix result(lhs.r, lhs.c);
        for(int i=0; i<lhs.r; i++){
            for(int j=0; j<lhs.c; j++){
                result.m[i][j] = lhs.m[i][j] + rhs.m[i][j];
            }
        }
        return result;
    }
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs){
    if(!lhs.sameSize(rhs)){
        cout<<"Error: this two matrix have diff size!"<<endl;
        return Matrix();
    }else{
        Matrix result(lhs.r, lhs.c);
        for(int i=0; i<lhs.r; i++){
            for(int j=0; j<lhs.c; j++){
                result.m[i][j] = lhs.m[i][j] - rhs.m[i][j];
            }
        }
        return result;
    }
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs){
    if(lhs.c != rhs.r){
        cout<<"Error: invalid multiplication!"<<endl;
        return Matrix();
    }else{
        Matrix result(lhs.r, rhs.c);
        for(int i=0; i<lhs.r; i++){
            for(int j=0; j<rhs.c; j++){
                for(int x=0; x<lhs.c; x++){
                    result.m[i][j] += lhs.m[i][x]*rhs.m[x][j];
                }
            }
        }
        return result;
    }
}
Matrix operator*(int scalar, const Matrix& rhs){
    Matrix result(rhs.r, rhs.c);
    for(int i=0; i<rhs.r; i++){
        for(int j=0; j<rhs.c; j++){
            result.m[i][j] = scalar*rhs.m[i][j];
        }
    }
    return result;
}
bool operator==(const Matrix& lhs, const Matrix& rhs){
    for(int i=0; i<lhs.r; i++){
        for(int j=0; j<lhs.c; j++){
            if(lhs.m[i][j] != rhs.m[i][j])  return false;
        }
    }
    return true;
}
void Matrix::operator=(const Matrix& rhs){
    this->clear();
    this->r = rhs.r;
    this->c = rhs.c;
    this->m = new int*[r];
    for(int i=0; i<this->r; i++){
        this->m[i] = new int[c];
        for(int j=0; j<this->c; j++){
            this->m[i][j] = rhs.m[i][j];
        }
    }
}
int Matrix::det()const{
    if(!isSpuare()){
        cout<<"Error: ("<<r<<","<<c<<") is not a square matrix!"<<endl;
        return 0;
    }
    if(r<=2){
        return(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
    }else{
        int ans = 0;
        for(int j=0; j<c; j++){
            if(j%2) ans -= m[0][j] * det_expa(j).det();
            else    ans += m[0][j] * det_expa(j).det();
        }
        return ans;
    }
}
Matrix Matrix::det_expa(int col)const{
    Matrix result(r-1, c-1);
    int found=0;
    for(int j=0; j<c; j++){
        if(j == col)    found=1;
        else{
            for(int i=1; i<r; i++){
                result.m[i-1][j-found] = m[i][j];
            }
        }
    }
    return result;
}
Matrix& Matrix::inverse(){

}