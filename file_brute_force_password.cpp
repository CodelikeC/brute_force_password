#include <iostream> 
#include <vector> 
#include <string> 
#include <map> 
#include <functional>
using namespace std; 
// tạo một chương trình brute force tấn công vào một mật khẩu để hiểu rõ cách hoạt động của nó //

void key_password ()
{
    cout <<"Key password"<<endl; 
    map <int, int> key_password; 
    int size_key; 
    if (size_key == NULL)
    {
        bool check = key_password.empty(); 
        return; 
    }
    else 
    {
        int size_key = key_password.size();
    }
    while(size_key == true)
    {
        key_password.insert(pair<int,int>(100,200));
        for (map <int, int>:: iterator i = key_password.begin(); i!= key_password.end(); i++)
        {
            cout <<"The first key of the password:" << i -> first <<"the second key of the password:" << i-> second << endl;
        }
    }
}

void attack_the_password(const string &password)
{
    cout <<"attack the password"<<endl; 
    // Tạo tập hợp các ký tự có thể có trong mật khẩu // 
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@";
    
    // Đệ quy duyệt qua tất cả các khả năng của mật khẩu // 
    vector<string> attempts;
    
    // Hàm đệ quy
    function<void(string, int)> brute_force = [&](string current, int length) 
    {
        if (current.length() == length) 
        {
            attempts.push_back(current);
            return;
        }
        
        for (char c : charset) 
        {
            brute_force(current + c, length);
        }
    };
    
    // Duyệt từ độ dài 1 đến độ dài của mật khẩu cần tìm
    for (int length = 1; length <= password.length(); length++) 
    {
        brute_force("", length);
    }
    
    // Kiểm tra từng mật khẩu thử nghiệm
    for (const string& attempt : attempts) 
    {
        if (attempt == password) 
        {
            cout << "Password found: " << attempt << endl;
            return;
        }
    }
    
    cout << "Password not found" << endl;
}
int main ()
{
    cout <<"The brute force attack the password" << endl; 
    string password = "123z@"; 

    for (int i = 0 ; i < password.size() ; i++)
    {
        cout <<password[i] << endl; 
    }
    // tạo một vector để lưu mật khẩu // 
    vector <string> hash_password; 
    hash_password.push_back(password); 
    
    // xây dựng lớp phòng ngự cho password // 
    while (!password.empty())
    {
        password = hash_password.back(); 
        hash_password.pop_back();  
    }
     
    // Gọi hàm attack_the_password
    attack_the_password(password);
    
    return 0 ; 
}