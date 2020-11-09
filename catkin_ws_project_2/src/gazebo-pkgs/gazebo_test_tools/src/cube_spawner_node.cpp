#include <gazebo_test_tools/gazebo_cube_spawner.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "gazebo_cube_spawner");

    if (argc < 5)
    {
        ROS_INFO("Usage: %s <name> [x y z dimx dimy dimz] [frame_id].",argv[0]);
        return 0;
    }

    ros::NodeHandle node; 
    gazebo_test_tools::GazeboCubeSpawner spawner(node);

    ROS_INFO("Running spawn cube once..");

    std::string name=argv[1];
    float x=0;
    float y=0;
    float z=0;
    float dimx=0;
    float dimy=0;
    float dimz=0;


    std::string frame_id="world";
    if (argc>2) x=atof(argv[2]);
    if (argc>3) y=atof(argv[3]);
    if (argc>4) z=atof(argv[4]);
    if (argc>5) dimx=atof(argv[5]);
    if (argc>6) dimy=atof(argv[6]);
    if (argc>7) dimz=atof(argv[7]);
    if (argc>8) frame_id=argv[8];

    float dim=0.05;   
    float mass=0.05;

    spawner.spawnCube(name,frame_id,x,y,z,0,0,0,1,dimx,dimy,dimz,mass);
    return 0;
}
