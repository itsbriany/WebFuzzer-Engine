#include "Engine.h"

Engine::Engine(int argc, const char **argv) {
}

void Engine::Start() {
  httpProxy_.Run();
}
