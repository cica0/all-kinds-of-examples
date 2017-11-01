#include "helloworld.pb.h"

#include <fcntl.h>

#include <iostream>
#include <fstream>
#include <cstdio>

#include <google/protobuf/text_format.h>  
#include <google/protobuf/io/zero_copy_stream_impl.h>

using lm::Book;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;

#define INPUT_FILE "test.config"
#define OUTPUT_FILE "test.config"
#define CONFIG_FILE "config.file"

void ListBook(const lm::Book& one_book) {
    cout << "Book ID: " << one_book.id() << endl;
    cout << "Book Name: " << one_book.name() << endl;
}

//将内容通过二进制写到stream流中，本例子使用文件流，将内容写到文件中
//不过这个文件是不可读的，为二进制存放
void SetToStream_book(Book &one_book)
{
    one_book.set_id(7);
    one_book.set_name("bubble");
    if (one_book.has_id() && one_book.has_name())
    {
        fstream output(OUTPUT_FILE, ios::out | ios::trunc | ios::binary);
        if(!one_book.SerializeToOstream(&output)){
            cout << "file to write book"<< endl;
            return;
        }
        output.close();
    }
    else 
        return ;
}

//将内容通过二进制流中读取，并解析成对应结构体
//输入文件是不可读的，为二进制存放
void GetFromStream_book(Book &one_book)
{
    fstream input(INPUT_FILE, ios::in | ios::binary);
    if (!input)
        cout << "file not found ,create a new file"<< endl;
    if (!one_book.ParseFromIstream(&input))
    {
        cout << "failed to parse book" << endl;
        return;
    }
    input.close();
}

//此函数为从配置文件CONFIG.FILE中读取各个字段，读到结构体中
void GetFromConfig_book()
{
    Book two_book;
    int fd = open(CONFIG_FILE, O_RDONLY);
    if (fd < 0)
    {
        cout << "open error";
        return ;
    }
    google::protobuf::io::FileInputStream  f_istream(fd);
    f_istream.SetCloseOnDelete(true);//使得文件描述符在流销毁时关闭
    //如果想要使用close（fd）进行关闭文件描述符，就不能使用这句话
    //弊端：如果close失败了不可察觉
    //如果close是否成功对程序很重要，需要手动关闭fd
    google::protobuf::TextFormat::Parse(&f_istream, &two_book);
    //close(fd);

    ListBook(two_book);
}

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;//使用protobuf程序需要在开头加的
    Book one_book;
    SetToStream_book(one_book);
    ListBook(one_book);
    GetFromStream_book(one_book);
    ListBook(one_book);
    GetFromConfig_book();
    google::protobuf::ShutdownProtobufLibrary();//使用protobuf程序需要在结尾加的
    return 0;
}
