#include <boost/log/trivial.hpp>
#include "HttpServer.h"
#include "HttpClient.h"

const std::string cHttpClient = "[HttpClient]";

HttpClient::HttpClient()
{
}

void
HttpClient::SendRequest(const boost::network::http::server<HttpServer>::request& request)
{
  boost::network::http::client client;
  boost::network::http::client::request request(request);
  // boost::network::http::client::request request(url);
  // request << boost::network::header("Connection", "close");
  boost::network::http::client::response response = client.get(request);
  BOOST_LOG_TRIVIAL(trace) << cHttpClient << ": " << body(response);
}
