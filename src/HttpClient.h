#pragma once
#include <boost/network/protocol/http/client.hpp>

class HttpServer;
class HttpClient {
  public:
    explicit HttpClient();

    /**
     * @param url The url to which we wish to send the request to
     */
    void SendRequest(const boost::network::http::server<HttpServer>::request& request);
};
