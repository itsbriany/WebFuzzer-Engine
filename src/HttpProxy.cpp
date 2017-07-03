#include "HttpProxy.h"

HttpProxy::HttpProxy()
  : httpClient_(),
    httpServer_(*this)
{
}

void
HttpProxy::HttpProxy::HandleHttpRequest(const boost::network::http::server<HttpServer>::request& request)
{
  std::cout << "Handled an http request!" << std::endl;
}

void
HttpProxy::Run()
{
  httpServer_.Run();
}
