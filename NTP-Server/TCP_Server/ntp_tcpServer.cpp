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
        m_socketAddress.sin_family = AF_INET;
        m_socketAddress.sin_port = htons(m_port);
        m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
    }
    Ntp_TcpServer::~Ntp_TcpServer(){
        closeServer();
    }

//-------------[Running the Server]----------------
    int Ntp_TcpServer::startServer(){
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        
        // Binding the socket address to the given socket
        if( bind(m_socket,(sockaddr *)&m_socketAddress, m_socketAddress_len) < 0 ){
            exitWithError("Cannot connect socket to address");
            return 1;
        }

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
//-------------[Connecting to the Server]----------------
    // Listening for incomming connections
    void Ntp_TcpServer::startListen(){
        if(listen(m_socket, 20) < 0)
            exitWithError("Socket listen failed");
        std::ostringstream ss;
        ss  << "\n*** Listening on Address: "
            << inet_ntoa(m_socketAddress.sin_addr)
            << " Port: " << ntohs(m_socketAddress.sin_port)
            << " ***\n\n";
        log(ss.str());
    }
    //Accepting the connection
    void Ntp_TcpServer::acceptConnection(SOCKET &new_socket){
        new_socket = accept(m_socket, (sockaddr *)&m_socketAddress, &m_socketAddress_len);
        if(new_socket < 0){
            std::ostringstream ss;
            ss  << "Server failed to accept incoming connection from Address: "
                << inet_ntoa(m_socketAddress.sin_addr) << "; PORT: "
                << ntohs(m_socketAddress.sin_port);
            exitWithError(ss.str());
        }
    }
}