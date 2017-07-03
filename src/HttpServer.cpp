#include <iostream>
#include <cstdint>
#include <sstream>

#include "HttpServer.h"

HttpServer::CallbackInterface::CallbackInterface()
{
}

HttpServer::CallbackInterface::~CallbackInterface()
{
}

HttpServer::HttpServer(CallbackInterface &callbackInterface)
  : callbackInterface_(callbackInterface)
{
}

void
HttpServer::Run()
{
  try {
    boost::network::http::server<HttpServer>::options options(*this);
    boost::network::http::server<HttpServer> server(options.address("0.0.0.0").port("8080"));
    std::cout << "About to run" << std::endl;
    server.run();
    std::cout << "Running" << std::endl;
  }
  catch (std::exception &error) {
    std::cerr << error.what() << std::endl;
    return;
  }
}

void
HttpServer::HttpServer::operator()(
  const boost::network::http::server<HttpServer>::request& request,
  boost::network::http::server<HttpServer>::connection_ptr connection)
{
  callbackInterface_.HandleHttpRequest(request);
}

void
HttpServer::HttpServer::SendResponse(const std::string& response)
{
  // TODO Let the HttpClient callback return here
  /*
  boost::network::http::server<HttpRequestHandler>::string_type ip = source(request);
  uint16_t port = request.source_port;
  std::ostringstream data;
  data << "Hello, " << ip << ':' << port << '!';
  connection->write(data.str());
  */
}
