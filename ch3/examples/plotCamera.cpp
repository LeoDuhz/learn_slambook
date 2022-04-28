#include <iostream>
#include <fstream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <unistd.h>
#include <pangolin/pangolin.h>
#include "Draw.h"

using namespace std;
using namespace Eigen;

int main(){
    string traj_file = "/home/leodu/learn_slambook/ch3/examples/trajectory.txt";
    vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses;
    ifstream fin(traj_file);
    if(!fin){
        cout << "File not found." << endl;
        return 1;
    }
    while(!fin.eof()){
        double time, tx, ty, tz, qw, qx, qy, qz;
        fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;
        Isometry3d Twr(Quaterniond(qw,qx,qy,qz));
        Twr.pretranslate(Vector3d(tx,ty,tz));
        poses.push_back(Twr);
//        cout << "Twr = \n" << Twr.matrix() << endl;
    }
    Draw draw(poses);
    draw.drawTraj();

}