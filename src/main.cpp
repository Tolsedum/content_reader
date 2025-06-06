#include <iostream>
#include "ContentReader.hpp"


int main(){ // int argc, char *argv[]
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
