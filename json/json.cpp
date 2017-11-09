#include <iostream>
#include <fstream>
#include <map>
#include "json/json.h"
#include "json/reader.h"
#include "json/writer.h"
#include "json/value.h"
#include "json/features.h"
#include "json/forwards.h"
#include <typeinfo>
using namespace std;

int ParseJsonFromMap()  
{
    map<string,string> m_r;
    m_r["num"] = 100;
    m_r["name"] = "abc";
    Json::Value root;  
string str_temp;
int int_temp = 1;
    for(map<string,string>::iterator it = m_r.begin();it!=m_r.end();++it)
    {
        cout << it->first  << endl << it->second << endl;
	if(typeid(str_temp).name() == typeid(it->second).name())
{
		cout << "str type is" << typeid(it->second).name() << endl;
		cout << "str type is" << typeid(str_temp).name() << endl;
}
	if(typeid(int_temp).name() == typeid(it->second).name())
{
		cout << "int type is" << typeid(it->second).name() << endl;
		cout << "int type is" << typeid(str_temp).name() << endl;
}
        root[it->first] = Json::Value(it->second);
    }
    Json::FastWriter fw;
    cout << fw.write(root) << endl;
    ofstream os;
    os.open("abc.txt");
    os << fw.write(root);
    return 0;
}
int ParseJsonFromString()  
{  
    const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

    Json::Reader reader;  
    Json::Value root;  
    if (reader.parse(str, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
    {  
        string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"  
        cout << "upload_id:" << upload_id ;
        int code = root["code"].asInt();    // 访问节点，code = 100  
        cout << "code:" << code;
    }  
    return 0;  
}  

int main()
{
    int result = ParseJsonFromMap();
    cout << result << endl;
    return 0;
}
