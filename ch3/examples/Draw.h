//
// Created by leodu on 2022/4/28.
//

#ifndef CHAPTER3_DRAWTRAJ_H
#define CHAPTER3_DRAWTRAJ_H

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <pangolin/pangolin.h>

using namespace std;
using namespace Eigen;

class Draw {
public:
    vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses;
    Draw(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses){
        this->poses = poses;
    }
    void drawTraj();
};


#endif //CHAPTER3_DRAWTRAJ_H
