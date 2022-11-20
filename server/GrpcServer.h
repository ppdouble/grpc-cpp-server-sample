//
// Created by codc on 11/20/22.
//

#ifndef GRPC_CPP_SERVER_SAMPLE_GRPCSERVER_H
#define GRPC_CPP_SERVER_SAMPLE_GRPCSERVER_H

#include "../service/GreeterServiceImpl.h"
#include "grpcpp/server_builder.h"

class GrpcServer {

public:
    void runServer(string serveruri);
};


#endif //GRPC_CPP_SERVER_SAMPLE_GRPCSERVER_H
