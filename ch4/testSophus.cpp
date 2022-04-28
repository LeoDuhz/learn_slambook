#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d R = AngleAxisd(M_PI/2, Vector3d(0,0,1)).toRotationMatrix();
    Quaterniond q(R);
    Sophus::SO3d SO3_R(R);
    Sophus::SO3d SO3_q(q);

    cout << "SO3 from matrix: \n" << SO3_R.matrix() << endl;
    cout << "SO3 from quaternion: \n" << SO3_q.matrix() << endl;

    Vector3d so3 = SO3_R.log();
    cout << "so3 = " << so3.transpose() << endl;
    cout << "so3 hat = \n" << Sophus::SO3d::hat(so3) << endl;
    cout << "so3 hat vee = " << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() << endl;

    Vector3d update_so3(1e-4,0,0);
    Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3)*SO3_R;
    cout << "SO3 updated = \n" << SO3_updated.matrix();

    cout << "------------------------------------------" << endl;

    Vector3d t(1,0,0);
    Sophus::SE3d SE3R_t(R,t);
    Sophus::SE3d SE3q_t(q,t);
    cout << "SE3 from R,t = \n" << SE3R_t.matrix() << endl;
    cout << "SE3 from q,t = \n" << SE3q_t.matrix() << endl;

    Eigen::Matrix<double,6,1> se3 = SE3R_t.log();
    cout << "se3 = " << se3.transpose() << endl;

    cout << "se3 hat = \n" << Sophus::SE3d::hat(se3) << endl;
    cout << "se3 hat vee = " << Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose() << endl;

    Eigen::Matrix<double,6,1> se3_update;
    se3_update << 1e-4,0,0,0,0,0;
    Sophus::SE3d SE3_updated = Sophus::SE3d::exp(se3_update)*SE3R_t;
    cout << "SE3 updated = \n" << SE3_updated.matrix() << endl;

}