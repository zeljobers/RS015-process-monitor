#include "core.h"

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sys/types.h>

namespace ProcessMonitor {

Core::Core() {
  pids_ = std::vector<int>(1024);

  proc_dir_ = opendir("/proc");
  if (proc_dir_ == NULL)
    throw std::runtime_error("Failed to open /proc directory.");
}

Core& Core::getInstance() {
  static Core instance;
  return instance;
}

std::vector<int>& Core::get_pid_list() {
  return pids_;
}

ProcessInfo Core::get_pid_info(int pid) {
  ProcessInfo ret;
  std::ifstream infile; 
  std::string temp;
  
  infile.open("/proc/" + std::to_string(pid) + "/stat");
  infile >> ret.pid;
  infile >> ret.name;
  
  // TODO: Use some of this info later... also optimize?
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;
  infile >> temp;

  infile >> ret.memory;

  infile.close();
  return ret;
}

void Core::refresh_pids() {
  pids_.clear();

  struct dirent* entry;
  int curnum;

  seekdir(proc_dir_, 0);
  while ((entry = readdir(proc_dir_)) != NULL) {
    curnum = 0;

    for (int i = 0; i < 256; i++) {
      if (isdigit(entry->d_name[i])) {
        // TODO: optimize?
        curnum = curnum * 10 + (entry->d_name[i] - 48);
      } else {
        if (entry->d_name[i] != '\0')
          curnum = -1;

        break;
      }
    }

    if (curnum != -1) // TODO: Ensure array size
      pids_.push_back(curnum);
  }
}

}