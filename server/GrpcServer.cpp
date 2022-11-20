//
// Created by codc on 11/20/22.
//

#include "GrpcServer.h"
#include "grpcpp/server_builder.h"
using namespace grpc;

void GrpcServer::runServer(string serveruri) {

    GreeterServiceImpl greeterService;

    ServerBuilder serverBuilder;

    // setting port and address
    serverBuilder.AddListeningPort(serveruri, InsecureServerCredentials());
    // Embed service to server
    serverBuilder.RegisterService(&greeterService);

    // create server and start
    unique_ptr<Server> server(serverBuilder.BuildAndStart());

    // waiting for request from client
    server->Wait();

}