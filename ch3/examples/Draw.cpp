//
// Created by leodu on 2022/4/28.
//

#include "Draw.h"

void Draw::drawTraj() {
    pangolin::CreateWindowAndBind("camera_pose", 1024, 768);
    glEnable(GL_DEPTH_TEST);

    pangolin::OpenGlRenderState s_cam_ = pangolin::OpenGlRenderState(
            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
            pangolin::ModelViewLookAt(5, -3, 5, 0, 0, 0, pangolin::AxisY)
    );

    pangolin::View& d_cam_ = pangolin::CreateDisplay()
            .SetBounds(0., 1., 0., 1., -1024/ 768.)
            .SetHandler(new pangolin::Handler3D(s_cam_));

    for(int i=0; i<poses.size(); i++){
        if(pangolin::ShouldQuit()){
            cout << "Pangolin Quit!" << endl;
            break;
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        d_cam_.Activate(s_cam_);

        //axis
        glLineWidth(3);
        glBegin ( GL_LINES );
        glColor3f ( 1.0f,0.f,0.f );
        glVertex3f( 0,0,0 );
        glVertex3f( 1,0,0 );
        glColor3f( 0.f,1.0f,0.f);
        glVertex3f( 0,0,0 );
        glVertex3f( 0,1,0 );
        glColor3f( 0.f,0.f,1.f);
        glVertex3f( 0,0,0 );
        glVertex3f( 0,0,1 );
        glEnd();

        //draw
        Isometry3d pose = poses.at(i);
        Matrix3d R = pose.rotation();
        Vector3d t = pose.translation();
        glPushMatrix();
        std::vector<GLdouble> Twc = {R(0, 0), R(1,0), R(2, 0), 0.,
                                     R(0, 1), R(1, 1), R(2, 1), 0.,
                                     R(0, 2), R(1, 2), R(2, 2), 0.,
                                     t(0), t(1), t(2), 1.};
        glMultMatrixd(Twc.data());
        // 绘制相机轮廓线
        const float w = 0.2;
        const float h = w * 0.75;
        const float z = w * 0.6;

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(0,0,0);		glVertex3f(w,h,z);
        glVertex3f(0,0,0);		glVertex3f(w,-h,z);
        glVertex3f(0,0,0);		glVertex3f(-w,-h,z);
        glVertex3f(0,0,0);		glVertex3f(-w,h,z);
        glVertex3f(w,h,z);		glVertex3f(w,-h,z);
        glVertex3f(-w,h,z);		glVertex3f(-w,-h,z);
        glVertex3f(-w,h,z);		glVertex3f(w,h,z);
        glVertex3f(-w,-h,z);    glVertex3f(w,-h,z);
        glEnd();
        glPopMatrix();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.f, 1.f, 0.f);
        for(size_t j=0; j<i; j++){
            glVertex3d(poses.at(j).translation()(0), poses.at(j).translation()(1), poses.at(j).translation()(2));
            glVertex3d(poses.at(j+1).translation()(0), poses.at(j+1).translation()(1), poses.at(j+1).translation()(2));
        }
        glEnd();
        pangolin::FinishFrame();

    }
}
