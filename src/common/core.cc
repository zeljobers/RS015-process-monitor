#include "core.h"

#include <sys/types.h>
#include <sys/sysinfo.h>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <string>

namespace ProcessMonitor {

Core::Core() {
  pids_ = std::vector<int>(1024);
  disk_info_ = std::map<std::string, DiskInfo>();

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
  std::ifstream infile("/proc/" + std::to_string(pid) + "/stat");
  std::string temp;
  
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

SysMemoryInfo& Core::get_memory_usage() {
  return mem_info_;
}

std::map<std::string, DiskInfo>& Core::get_disk_usage_info() {
  return disk_info_;
}

void Core::refresh_resources() {
  std::string temp;

  // Poll RAM
  struct sysinfo sinfo; // TODO: Make a local variable instead
  if (sysinfo(&sinfo) == 0) {
    mem_info_.memory_usage = sinfo.totalram - sinfo.freeram;
    mem_info_.swap_usage = sinfo.totalswap - sinfo.freeswap;
    mem_info_.total_memory = sinfo.totalram;
    mem_info_.total_swap = sinfo.totalswap;
  }

  // Poll Drives
  std::ifstream infile("/proc/diskstats");

  while (!infile.eof()) // TODO: Optimize...
  {
    DiskInfo dinfo;
    infile >> temp;
    infile >> temp;
    infile >> dinfo.name;
    infile >> temp;
    infile >> temp;
    infile >> dinfo.total_reads;
    infile >> temp;
    infile >> temp;
    infile >> temp;
    infile >> dinfo.total_writes;
    infile >> temp;
    infile >> temp;
    infile >> temp;
    infile >> temp;
    
    dinfo.reads = 0;
    dinfo.writes = 0;

    if (dinfo.name.find("sd") == 0)
    {
      auto elem = disk_info_.find(dinfo.name);
      if (elem != disk_info_.end()) {
        dinfo.reads = dinfo.total_reads - elem->second.total_reads;
        dinfo.writes = dinfo.total_writes - elem->second.total_writes;
      }
      disk_info_[dinfo.name] = dinfo;
    }
  }
}

}