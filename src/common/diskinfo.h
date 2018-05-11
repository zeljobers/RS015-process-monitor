#include <string>

namespace ProcessMonitor {

// Contains basic information about disk I/O
class DiskInfo {
  public:
    // Name of the partition or drive
    std::string name;

    // Total number of sectors read
    int total_reads;

    // Total number of sectors written
    int total_writes;

    // Number of sector reads since the last call
    int reads;

    // Number of sector writes since the last call
    int writes;
};

}