//
// Created by codc on 11/19/22.
//

#include "GreeterServiceImpl.h"

Status GreeterServiceImpl::SayHello (ServerContext* serverContext, const HelloRequest* helloRequest, HelloResponse* helloResponse) {

    // build response message
    string responsePrefix("Hello ");
    helloResponse->set_responsemsg(responsePrefix + helloRequest->myname());
    return Status::OK;
}