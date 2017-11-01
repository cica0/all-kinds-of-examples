struct Student{
	1:i32 sno,
	2:string sname,
	3:bool ssex,
	4:i16 sage,
}

service putin{
	void put(1:Student s)
}

service getout{
	Student get(1:i32 sno) 
}
