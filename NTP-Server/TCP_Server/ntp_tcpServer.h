#ifndef INCLUDED_NTP_TCPSERVER
#define INCLUDED_NTP_TCPSERVER

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

namespace http{
    class Ntp_TcpServer{
        public:
            Ntp_TcpServer(std::string ip_address, int port);
            ~Ntp_TcpServer();
        
        private:
            std::string m_ip_address;
            int m_port;
            int m_socket;
            int m_new_socket;
            long m_incomingMessage;
            struct sockaddr_in m_socketAddress;
            unsigned int m_socketAddress_len;
            std::string m_serverMessage;

            int startServer();
            void closeServer();
    };
}
#endif