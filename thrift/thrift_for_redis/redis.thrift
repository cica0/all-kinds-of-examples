
struct Book{
    1:optional i32 Number       //书的序列号
    2:optional string Author    //书的作者
    3:optional i32 pages        //书的页数
    4:optional Bookshelf shelf  //书在哪个书架上 
}


struct Bookshelf{
    1:optional i32 No           //书架号 
    2:optional list<Book> books //书架上面所有的书
}

service GetBookService{
    Book GetBook(1:Bookshelf request)
}

service GetBookshelfService{
    Bookshelf GetBookshelf(1:Book request)
}
