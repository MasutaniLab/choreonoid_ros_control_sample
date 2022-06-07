#include <ros/ros.h>
#include <std_msgs/Float64.h>

std_msgs::Float64 Hip_cmd, Knee_cmd;
ros::Publisher Hip_command_pub, Knee_command_pub;

const double Hip_amplitude = 1.0;
const double Knee_amplitude = 1.5;
const double Hip_freq = 0.5;
const double Knee_freq = 1.0;

int main(int argc, char** argv){
    ros::init(argc, argv, "simple_leg_controller");
    ros::NodeHandle nh("simple_leg");   // set namespace
    ros::Rate loop_rate(50);

    Hip_command_pub = nh.advertise<std_msgs::Float64>("Hip_position_controller/command", 1);
    Knee_command_pub = nh.advertise<std_msgs::Float64>("Knee_position_controller/command", 1);

    ros::Time t_start = ros::Time::now();

    while(ros::ok()){
        double current_time = (ros::Time::now() - t_start).toSec();

        Hip_cmd.data  = Hip_amplitude * sin(2 * M_PI * Hip_freq * current_time);
        Knee_cmd.data = Knee_amplitude * sin(2 * M_PI * Knee_freq * current_time);

        Hip_command_pub.publish(Hip_cmd);
        Knee_command_pub.publish(Knee_cmd);

        loop_rate.sleep();
    }
    return 0;
}
