#include <ntp_tcpServer.h>

int main(){
    using namespace http;

    Ntp_TcpServer ntp_server = Ntp_TcpServer("0.0.0.0", 8080);

    return 0;
}