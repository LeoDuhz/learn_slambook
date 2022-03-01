#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char ** argv){
    Matrix<double, 2, 3> matrix_23;
    matrix_23 << 1,2,3,4,5,6;
    cout << matrix_23 << endl;

    Matrix<int, 2, 3> matrix_232;
    matrix_232 << 1,2,3,4,5,6;

    Matrix<double, Dynamic, Dynamic> matrix_dd;
    matrix_dd = matrix_23 * matrix_232.cast<double>().transpose();
    // cout << matrix_23*matrix_232.cast<double>().transpose() << endl;
    cout << matrix_dd << endl;
    cout << matrix_dd.sum() << endl;
    cout << matrix_dd.trace() << endl;
    cout << matrix_dd.inverse() << endl;
    cout << matrix_dd.determinant() << endl;

    Matrix<double, 5, 5> matrix_nn = MatrixXd::Random(5,5);
    matrix_nn = matrix_nn * matrix_nn.transpose();
    Matrix<double, 5, 1> vector_n = MatrixXd::Random(5,1);
    Matrix<double, Dynamic, Dynamic> x = matrix_nn.inverse()*vector_n;
    cout << x << endl;
    x = matrix_nn.colPivHouseholderQr().solve(vector_n);
    cout << x << endl;
    x = matrix_nn.ldlt().solve(vector_n);
    cout << x << endl;
}