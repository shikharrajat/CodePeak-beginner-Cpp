//Author : Anmol Abhay Jain
//Date : 29/01/2021
//coding club cpp git task->

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Matrix {
    private:
    vector<vector<T>> mat;           // Our matrix as vector of vector
    int rowSize = -1, colSize = -1;  // No. of rows and columns respectively

    public:
    //constructor
    Matrix(int N, int M, T defaultValue);  // initialises a MxN matrix with defaultValue
    Matrix(Matrix& temp);  // Must create a deep copy of the temp matrix

    //Logging Functions
    void printMatrix();

    //Constructor Overloading
    //matrix Operation
    Matrix<T> operator*(Matrix &);
    Matrix<T> operator+(Matrix &);
    Matrix<T> operator-(Matrix &);
    
    // Scalar Operations
    Matrix<T> operator+(double);
    Matrix<T> operator-(double);
    Matrix<T> operator*(double);
    Matrix<T> operator/(double);

    //getter functions
    vector<vector<T>>& getMatrix();
    int getRowSize();
    int getColSize();

    //setter functions
    void setMatrix(vector<vector<T>>& tempMat);

    //utility functions
    Matrix transpose(); // returns the transpose of the matrix
    Matrix matExponentiation(Matrix& M, int pow); // return M^n for the matrix
    void PowerInteration(vector<T> eigenVector, double eigenValue);   // Using Power interation method to find
                                                    // the most dominant eigenVector and its corresponding eigenvalue
                                                    // In this function rather than returning ans we are going to 
                                                    // fill the appropriate values in eigenVector and eigenValue which are passed as param
    
    // Many functionalites can now be added
    // like finding out the PCA of the matrix,
    // finding the Null space of the matrix and so on...
    

}; 
template <typename T>
Matrix<T>::Matrix(int N, int M, T defaultValue){
    mat.resize(N, vector<T>(M, defaultValue));  //initialize the matrix
    rowSize = N;                                     
    colSize = M;
}

template <typename T>
Matrix<T>::Matrix(Matrix& temp){
    *this = temp;
    // this->mat = temp.getMatrix();
    // this->rowSize = temp.getRowSize();
    // this->colSize = temp.getColSize();
}

template <typename T>
void Matrix<T>::printMatrix(){
    cout << "Matrix: " << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << " " << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
vector<vector<T>>& Matrix<T>::getMatrix(){
    return this->mat;
}

template <typename T>
int Matrix<T>::getRowSize(){
    return this->rowSize;
}

template <typename T>
int Matrix<T>::getColSize(){
    return this->colSize;
}

template <typename T>
void Matrix<T>::setMatrix(vector<vector<T>>& tempMat){
    mat = tempMat;
    rowSize = tempMat.size();
    colSize = tempMat[0].size(); 
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix& rhs){
    vector<vector<T>> ansMat(rowSize, vector<T>(rhs.getColSize(), (T)0)); // the matrix which will store the value of multiplication
    vector<vector<T>> B = rhs.getMatrix();

    assert(colSize == rhs.getRowSize());
    int i,j,k;
    T temp;
    for (i = 0; i < rowSize; i++){
        for (j = 0; j < rhs.getColSize(); j++){
            temp = (T)0;
            for (k = 0; k < colSize; k++){
                temp += mat[i][k] * B[k][j];
            }
            ansMat[i][j] = temp;
        }
    }

    Matrix<T> C(rowSize, rhs.getColSize(), (T)0);
    C.setMatrix(ansMat);
    return C;
}

int main(){
    cout<<"elementry tests ->"<<endl;
    
    Matrix<int> a(4, 2, 2);
    a.printMatrix();
    
    Matrix<int> b(a);
    b.printMatrix();
    
    vector<vector<int>> tempMat(3, vector<int>(4, 5));
    a.setMatrix(tempMat);
    a.printMatrix();
    
    (a*b).printMatrix();
    
    return 0;
}