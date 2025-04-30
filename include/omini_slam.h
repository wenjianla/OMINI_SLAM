/**
 * @file omini_slam.h
 * @brief OMINI_SLAM系统的主要头文件
 */

#ifndef OMINI_SLAM_H
#define OMINI_SLAM_H

#include <Eigen/Core>
#include <opencv2/core.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <memory>
#include <string>
#include <vector>

namespace omini_slam {

/**
 * @brief SLAM系统的主类
 * 
 * 这个类是整个SLAM系统的入口点，负责协调各个模块的工作
 */
class System {
public:
    /**
     * @brief 构造函数
     * @param config_file 配置文件路径
     */
    System(const std::string& config_file);

    /**
     * @brief 析构函数
     */
    ~System();

    /**
     * @brief 处理RGB-D图像
     * @param rgb RGB图像
     * @param depth 深度图像
     * @param timestamp 时间戳
     * @return 当前帧的位姿
     */
    Eigen::Matrix4f ProcessRGBD(const cv::Mat& rgb, const cv::Mat& depth, double timestamp);

    /**
     * @brief 处理激光雷达数据
     * @param cloud 点云数据
     * @param timestamp 时间戳
     * @return 当前帧的位姿
     */
    Eigen::Matrix4f ProcessLidar(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, double timestamp);

    /**
     * @brief 保存地图
     * @param map_path 地图保存路径
     * @return 是否保存成功
     */
    bool SaveMap(const std::string& map_path);

    /**
     * @brief 获取当前轨迹
     * @return 轨迹点列表
     */
    std::vector<Eigen::Matrix4f> GetTrajectory() const;

private:
    // 系统内部状态
    class SystemImpl;
    std::unique_ptr<SystemImpl> impl_;
};

} // namespace omini_slam

#endif // OMINI_SLAM_H