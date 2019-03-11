#ifndef CAMERA_H //防止头文件重复引用ifndef
#define CAMERA_H
#include "myslam/common_include.h" //把常用的头文件放在common_incude.h文件中，这样就可以避免每次书写一个很长的一串
namespace myslam
{
//Pinhole RGB-D camera model
class Camera 
{
public:
    typedef std::shared_ptr<Camera> Ptr; //#把智能指针定义成 Camera 的指针类型,因此以后在传递参数时,只需用 Cam-era::Ptr 类型即可。
    float fx_, fy_, cx, cy_, depth_sclae_; //Camera intrinsics

    Camera();
    Camera(float fx, float fy, float cx, float cy,float depth_scale=0 ):
    fx_ ( fx ),fy_ ( fy ) ,cx_ (cx ), cy_ (cy ), depth_sclae_ (depth_scal )
    {}

    //我们用 Sophus::SE3 来表达相机的位姿。Sophus 库在李代数章节已经介绍过了。
    //coordinate transform:world, camera, pixel 
    Vector3d world2camera( const Vector3d& p_w,const SE3& T_c_w);
    Vector3d camera2world( const Vector3d& p_c,const SE3& T_c_w);
    Vector2d camera2pixel( const Vector3d& p_c);
    Vector3d pixel2camera( const Vector3d& p_p,double depth=1);
    Vector3d pixel2world( const Vector3d& p_p,const SE3& T_c_w, double depth = 1);
    Vector2d world2pixel( const Vector3d& p_w,const SE3& T_c_w);
};
}
#endif //CAMERA_H