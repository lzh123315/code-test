#include <Eigen/SparseCore>
#include <iostream>

using namespace std;
int main(){
    Eigen::SparseMatrix<int> mat;
    mat.resize(1, 2);
    mat.insert(0, 0) = 1;
    mat.insert(0, 1) = 2;
    std::cout << mat;
    mat.resize(1, 2);
    std::cout << mat;
    mat.resize(1, 3);
    mat.insert(0, 0) = 3;
    mat.insert(0, 1) = 5;
    mat.insert(0, 2) = 5;
    std::cout << mat;
    mat.coeffRef(0, 0) = 2;
    mat.coeffRef(0, 1) = 7;
    mat.coeffRef(0, 2) = 7;
    std::cout << mat;

  Eigen::MatrixXf m(4,4);
  m <<  1, 2, 3, 4,
        5, 6, 7, 8,
        9,10,11,12,
       13,14,15,16;
  cout << "Block in the middle" << endl;
  cout << m.block<2,2>(1,1) << endl << endl;
  for (int i = 1; i <= 3; ++i)
  {
    cout << "Block of size " << i << "x" << i << endl;
    cout << m.segment(0, i) << endl << endl;
  }
}