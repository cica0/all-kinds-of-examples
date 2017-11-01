struct Student{
    1: i32 id
    2: string name
}

service Serv{
    i32 put(1:Student s)
}
