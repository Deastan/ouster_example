#pragma once
#define PCL_NO_PRECOMPILE
#include <pcl/point_types.h>

namespace ouster_ros {
namespace OS1 {

struct EIGEN_ALIGN16 PointOS1 {
    PCL_ADD_POINT4D;
    float t;
    float reflectivity;
    // Issue on cartographer: Failed to find match for field 'intensity'. :
    // https://github.com/googlecartographer/cartographer_ros/issues/1018
    // uint16_t intensity;
    float intensity;
    uint8_t ring;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}
}

POINT_CLOUD_REGISTER_POINT_STRUCT(ouster_ros::OS1::PointOS1,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, t, t)
    (uint16_t, reflectivity, reflectivity)
    // Issue on cartographer: Failed to find match for field 'intensity'. :
    // https://github.com/googlecartographer/cartographer_ros/issues/1018
    // uint16_t intensity;
    // (uint16_t, intensity, intensity)
    (float, intensity, intensity)
    (uint8_t, ring, ring)
)
