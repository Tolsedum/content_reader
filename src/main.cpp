#include <iostream>
#include "ContentReader.hpp"


int main(){ // int argc, char *argv[]

    std::string file_name{"public/view/html/index/index.html"};
    std::string output{};

    ContentSettings contentSettings;
    
    
    std::ifstream file_p_(file_name);
    std::string content{};
    std::string tmp{};
    while (std::getline(file_p_, tmp)){
        content.append(tmp);
    }
    
    // contentSettings.setFileName(file_name);
    contentSettings.setContent(content);

    if(std::filesystem::exists(file_name)){
        std::cout << "is exists: " << std::endl;
        ContentReader container_;
        container_.contentInit(
            std::forward<ContentSettings>(contentSettings)
        );
        container_.print();
    }
    return 0;
    
    
    ContentSettings setting;

    setting.setFileName("test.txt");

    ContentReader contentReaderFile(setting);
    contentReaderFile.setPos(2);
    std::cout << contentReaderFile.current() 
        << std::endl << contentReaderFile.next() 
        << std::endl << contentReaderFile.size() 
    << std::endl;
    contentReaderFile.print();

    setting.setContent("Test text for read content!");

    ContentReader contentReaderStr(setting);
    contentReaderStr.setPos(2);
    std::cout << contentReaderStr.current() 
        << std::endl << contentReaderStr.next() 
        << std::endl << contentReaderStr.size() 
    << std::endl;
    contentReaderStr.print();
    return 0;
}
