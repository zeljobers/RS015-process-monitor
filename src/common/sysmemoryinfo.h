#include <string>

namespace ProcessMonitor {

// Contains basic information about the current
// state of the system memory.
class SysMemoryInfo {
 public:
  // Total system memory (without swap) in bytes.
  unsigned long total_memory;

  // Total swap memory in bytes.
  unsigned long total_swap;

  // Total system memory usage (without swap) in bytes.
  unsigned long memory_usage;

  // Total swap memory usage in bytes.
  unsigned long swap_usage;
};

}