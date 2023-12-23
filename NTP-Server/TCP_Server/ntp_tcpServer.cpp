#include <ntp_tcpServer.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

namespace{
    void log(const std::string &message){
        std::cout << message << std::endl;
    }

    void exitWithError(const std::string &errorMessage){
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace http{
    Ntp_TcpServer::Ntp_TcpServer(std::string ip_address, int port)
        :   m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(), m_incomingMessage(),
            m_socketAddress(), m_socketAddress_len(sizeof(m_socketAddress)), m_serverMessage(buildResponse())
    {
    }
    Ntp_TcpServer::~Ntp_TcpServer(){
        closeServer();
    }

    int Ntp_TcpServer::startServer(){
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }        return 0;
    }
    
    void Ntp_TcpServer::closeServer(){
        close(m_socket);
        close(m_new_socket);
        exit(0);
    }
}