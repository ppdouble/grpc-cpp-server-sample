#include <iostream>
#include "server/GrpcServer.h"


int main(int argc, char *argv[]) {

    GrpcServer grpcServer;

    grpcServer.runServer("0.0.0.0:9906");

    std::cout << "=== End ===" << std::endl;
    return 0;
}
