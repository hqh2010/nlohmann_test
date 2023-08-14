#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>

// filesystem是C++ 17才支持
// #include <filesystem>

using json = nlohmann::json;

int main()
{
    // 文件绝对路径不存在时会上报nlohmann::json_abi_v3_11_2::detail::parse_error异常
    // std::ifstream i("/home/uos/Desktop/nlohmann_test/src/input.json");
    // filesystem是C++ 17才支持
    // std::filesystem::path currentPath = std::filesystem::current_path();
    // std::cout << "当前路径: " << currentPath << std::endl;
    char buffer[FILENAME_MAX];
    if (getcwd(buffer, sizeof(buffer)) != nullptr)
    {
        std::cout << "当前路径: " << buffer << std::endl;
    }
    else
    {
        std::cout << "无法获取当前路径" << std::endl;
    }

    json j;
    // 文件绝对路径不存在时会上报nlohmann::json_abi_v3_11_2::detail::parse_error异常
    std::ifstream i("/home/uos/Desktop/nlohmann_test/src/input.json");
    try
    {
        j = json::parse(i);
    }
    catch (const std::exception &exp)
    {
        std::cout << "parse json file error" << std::endl;
        std::cout << exp.what() << std::endl;
    }
    std::cout << "close json file handler" << std::endl;
    i.close();

    // 打印output对象【也可以用j["output"].at("width")】
    std::cout << j.at("output").at("width") << std::endl;
    std::cout << j.at("output").at("height") << std::endl;
    std::cout << j.at("output").at("frameRate") << std::endl;
    std::cout << j.at("output").at("crf") << std::endl;
    // 打印tracks数组对象
    for (int i = 0; i < j["tracks"].size(); i++)
    {
        std::cout << j["tracks"][i].at("name") << std::endl;

        // 打印pieces子数组对象
        json j2 = j["tracks"][i].at("pieces");
        for (int k = 0; k < j2.size(); k++)
        {
            std::cout << j2[k].at("file") << std::endl;
            std::cout << j2[k].at("startTime") << std::endl;
            std::cout << j2[k].at("endTime") << std::endl;
        }
    }

    return 0;
}