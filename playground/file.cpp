#include <bits/stdc++.h>

#include <filesystem>
#include <fstream>
#include <string>

void PrintFileState(std::fstream& file)
{
    std::cout << "p=" << file.tellp() << "; good=" << file.good() << "; eof=" << file.eof() << "; fail=" << file.fail()
    << "; bad=" << file.bad() << "; rstate=" << file.rdstate() << std::endl;
}

int main()
{
    std::string str = "hello";


    std::filesystem::path path = std::filesystem::current_path() / std::filesystem::path("files/file.txt");

    std::cout << path.parent_path().string() << std::endl;

    std::filesystem::create_directories(path.parent_path());

    std::fstream file(path, std::ios::out | std::ios::in);


    // for (int i = 0; i < 8; ++i)
    // {
    //     std::cout << "iter" << std::endl;
    //     PrintFileState(file);
    //     file.get();
    //     PrintFileState(file);
    //     std::cout << std::endl;
    // }


    file.seekp(0, std::ios::end);
    std::cout << (char)file.get() << std::endl;

    // char strp[20];
    // while(file.getline(strp, 20, ' '))
    // {
    //     PrintFileState(file);
    //     std::cout << strp << std::endl;
    //     PrintFileState(file);
    // }


    // PrintFileState(file);
    // file.write(str.c_str(), str.size());
    // PrintFileState(file);
    // file.clear();
    // PrintFileState(file);
    // file.write(str.c_str(), str.size());
    // PrintFileState(file);


    // std::fstream file("file.txt", std::ios::out | std::ios::in);

    // if (file.is_open())
    // {
    //     char buff[20];
    //     while(file.getline(buff, 20))
    //     {
    //         std::cout << buff << std::endl;
    //         if (file.eof())
    //         {
    //             break;
    //         }
    //     }
    //     PrintFileState(file);
    //     file.clear();
    //     file.seekp(0);
    //     PrintFileState(file);
    //     std::string str = "hello\n";
    //     file.write(str.c_str(), str.size());
    //     PrintFileState(file);
    // }
    // else
    // {
    //     std::cout << "fail" << std::endl;
    // }
}