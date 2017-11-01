#include "Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "student_types.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
//using namespace ::apache::thrift::server;
using std::vector;
using std::string;
using std::endl;
using std::cout;
using boost::shared_ptr;

int main()
{
    shared_ptr<TSocket> socket (new TSocket("localhost", 9090));

    shared_ptr<TTransport> transport(new TFramedTransport(socket));
    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport)); 
    ServClient client(protocol);

    transport->open();

    Student tom;
    tom.id = 180;
    tom.name = "Tom";

    int ret = client.put(tom);
    cout << "client ret is:" << ret;
    transport->close();
}
