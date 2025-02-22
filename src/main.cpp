#include <iostream>
#include "ContentReader.hpp"


int main(){ // int argc, char *argv[]
    std::cout << "Hello world!" << std::endl;

    ContentSettings setting;

    setting.setFileName("test.txt");

    ContentReader contentReaderFile(setting);
    contentReaderFile.setPos(2);
    std::cout << contentReaderFile.current() 
        << std::endl << contentReaderFile.next() 
    << std::endl;
    contentReaderFile.print();

    
    setting.setContent("Test text for read content!");

    ContentReader contentReaderStr(setting);
    contentReaderStr.setPos(2);
    std::cout << contentReaderStr.current() 
        << std::endl << contentReaderStr.next() 
    << std::endl;
    contentReaderStr.print();
    return 0;
}
