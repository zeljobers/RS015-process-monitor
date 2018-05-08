#include <string>

namespace ProcessMonitor {

// Contains the basic information about a process.
class ProcessInfo {
 public:
  // Name of the process
  std::string name;

  // Process id number
  int pid;

  // Memory used (in bytes)
  int memory;
};

}