//
// Created by codc on 11/19/22.
//

#ifndef GRPC_CPP_SERVER_SAMPLE_GREETERSERVICEIMPL_H
#define GRPC_CPP_SERVER_SAMPLE_GREETERSERVICEIMPL_H

#include "../api/helloworld.grpc.pb.h"

// using the namespace provided by generated source file
using namespace helloworld;
using namespace grpc;
using namespace std;

// Implement the service interface

class GreeterServiceImpl final : public Greeter::Service {

    Status SayHello (ServerContext* serverContext, const HelloRequest* helloRequest, HelloResponse* helloResponse);

};


#endif //GRPC_CPP_SERVER_SAMPLE_GREETERSERVICEIMPL_H
