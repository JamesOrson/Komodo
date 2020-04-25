#include <spdlog/spdlog.h>

int main(/*int argc, const char **argv*/)
{
  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");
}
