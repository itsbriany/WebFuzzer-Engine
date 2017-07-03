#include <boost/log/trivial.hpp>
#include "Engine.h"

const std::string cEngine = "[Engine]";

Engine::Engine(int argc, const char **argv) {
}

void Engine::Start() {
  BOOST_LOG_TRIVIAL(info) << cEngine << ": Running...";
  httpProxy_.Run();
}
