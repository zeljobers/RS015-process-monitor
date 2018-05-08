#ifndef PROCESSMONITOR_COMMON_CORE_H_
#define PROCESSMONITOR_COMMON_CORE_H_

#include <dirent.h>
#include <vector>
#include <sys/types.h>

#include "processinfo.h"

namespace ProcessMonitor {

// Used to get system information.
// Use getInstance() to use it.
//
// Example:
//    Core::getInstance().refresh_pids();
class Core {
 public:
  Core(Core const&) = delete;
  void operator=(Core const&) = delete;

  // Returns an instance of the Core class.
  static Core& getInstance();

  // Gets the REFERENCE to the pid list. Use
  // refresh_pids() to actually update the list.
  std::vector<int>& get_pid_list();

  // Return info related to the passed pid.
  ProcessInfo get_pid_info(int pid);

  // Reloades the pid list.
  void refresh_pids();

private:
  Core();

  bool init_;
  DIR* proc_dir_;
  std::vector<int> pids_;
};

}

#endif