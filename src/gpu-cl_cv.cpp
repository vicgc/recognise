#include <iostream>  
#include <CL/cl.hpp>  
#include <boost/foreach.hpp>

// simple openCL test
// check if device is working and 
// report on number of devices that
// shall be used - cores
int main(int, char**) {
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    BOOST_FOREACH(cl::Platform platform, platforms) {
        std::cout << "Platform: " << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
        std::vector<cl::Device> devices;
        platform.getDevices(CL_DEVICE_TYPE_GPU | CL_DEVICE_TYPE_CPU, &devices);
        
        BOOST_FOREACH(cl::Device device, devices) {
            std::cout << "Device: " << device.getInfo<CL_DEVICE_TYPE>();
            std::cout << " (" << CL_DEVICE_TYPE_GPU << " means GPU, "
                << CL_DEVICE_TYPE_CPU << " means CPU)" << std::endl;
        }
    }
}
