#pragma once

#include <boost/network/protocol/http/server.hpp>
#include "HttpRequestHandler.h"

class HttpServer {
  public:
    // ------------------- Types -----------------------
    /*
     * Implement this interface to hook HttpServer events
     */
    class CallbackInterface
      {
        public:
          explicit CallbackInterface();
          virtual ~CallbackInterface();

          /*
           * Send an HTTP request
           * @param request The request object to handle
           */
          virtual void HandleHttpRequest(const boost::network::http::server<HttpServer>::request& request) = 0;
      };

    // ------------------- Interface -----------------------
    explicit HttpServer(CallbackInterface &callbackInterface);

    /**
     *  The functor that executes each time we get a new request
     *  @param request The inbound HTTP request
     *  @param connection Our connection object
     */
    void operator()(
        const boost::network::http::server<HttpServer>::request& request,
        boost::network::http::server<HttpServer>::connection_ptr connection);

    void Run();

  private:
    // ------------------- Private Interface -----------------------

    /**
     * @param response The response to be sent back to the HTTP client
     */
    void SendResponse(const std::string& response);

    // ------------------- Data Members -------------------
    CallbackInterface &callbackInterface_;
};
