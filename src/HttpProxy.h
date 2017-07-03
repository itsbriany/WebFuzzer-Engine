#pragma once

#include "HttpServer.h"
#include "HttpClient.h"

class HttpProxy : public HttpServer::CallbackInterface
{
  public:
    // ----------- HttpServer::CallbackInterface ----------

    /*
     * Send an HTTP request
     * @param request The request object to handle
     */
    virtual void HandleHttpRequest(const boost::network::http::server<HttpServer>::request& request) override;

    // ---------------------- Interface -------------------
    explicit HttpProxy();
    void Run();

  private:
    // ---------------------- Data Members ----------------
    HttpServer httpServer_;
    HttpClient httpClient_;
};
