#include <boost/log/trivial.hpp>
#include "HttpProxy.h"

const std::string cHttpProxy = "[HttpProxy]";

HttpProxy::HttpProxy()
  : httpClient_(),
    httpServer_(*this)
{
}

void
HttpProxy::HttpProxy::HandleHttpRequest(const boost::network::http::server<HttpServer>::request& request)
{
  BOOST_LOG_TRIVIAL(info) << cHttpProxy << ": Got an HTTP Request[" << request.destination << ']';
  httpClient_.SendRequest(request);
}

void
HttpProxy::Run()
{
  BOOST_LOG_TRIVIAL(debug) << cHttpProxy << ": Running...";
  httpServer_.Run();
}
