#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif
#include <cstring>
#include <ctime>
#include <iostream>

#include <gnu/libc-version.h>

//------------------------------------------------------------------------------
int main(/*int argc, char **argv*/) {
  auto lambda = [](auto x){ return x; };
  std::cout << lambda("Hello, World!") << std::endl;

  printf("GLibc version: %s\n", gnu_get_libc_version());
  printf("GLibc release: %s\n", gnu_get_libc_release());

  timespec ts{};
  if (clock_gettime(CLOCK_REALTIME_COARSE, &ts) != 0) {
    std::cerr << "Error: " << strerror(errno) << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Current time: " << std::ctime(&ts.tv_sec) << std::endl;

  return EXIT_SUCCESS;
}