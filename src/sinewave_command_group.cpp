#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

std_msgs::Float64MultiArray cmd;
ros::Publisher command_pub;

const double Hip_amplitude = 1.0;
const double Knee_amplitude = 1.5;
const double Hip_freq = 0.5;
const double Knee_freq = 1.0;

int main(int argc, char** argv){
    ros::init(argc, argv, "simple_leg_controller_group");
    ros::NodeHandle nh("simple_leg");   // set namespace
    ros::Rate loop_rate(50);

    command_pub = nh.advertise<std_msgs::Float64MultiArray>("joint_group_position_controller/command", 1);

    ros::Time t_start = ros::Time::now();

    while(ros::ok()){
        double current_time = (ros::Time::now() - t_start).toSec();

        cmd.data.resize(2);
        cmd.data[0] = Hip_amplitude * sin(2 * M_PI * Hip_freq * current_time);
        cmd.data[1] = Knee_amplitude * sin(2 * M_PI * Knee_freq * current_time);

        command_pub.publish(cmd);

        loop_rate.sleep();
    }
    return 0;
}
