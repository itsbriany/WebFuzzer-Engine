#pragma once

#include "HttpProxy.h"

class Engine {
  public:
    explicit Engine(int argc, const char** argv);
    void Start();

  private:
    HttpProxy httpProxy_;
};
