#include <boost/network/protocol/http/client.hpp>
#include <iostream>

#include "Engine.h"

void HttpClientExample(int argc, const char** argv);

int main(int argc, const char** argv) {
  Engine engine(argc, argv);
  engine.Start();
  return 0;
}

void HttpClientExample(int argc, const char** argv) {
  using namespace boost::network;
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " [url]" << std::endl;
    return;
  }

  http::client client;
  http::client::request request(argv[1]);
  request << header("Connection", "close");
  http::client::response response = client.get(request);
  std::cout << body(response) << std::endl;
}
