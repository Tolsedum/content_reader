#ifndef CONTENT_READER
#define CONTENT_READER

/**
 *  __________________________________________ 
 * |                                          |
 * |   ╭━━━━┳━━━┳╮╱╱╭━━━┳━━━┳━━━┳╮╱╭┳━╮╭━╮    |
 * |   ┃╭╮╭╮┃╭━╮┃┃╱╱┃╭━╮┃╭━━┻╮╭╮┃┃╱┃┃┃╰╯┃┃    |
 * |   ╰╯┃┃╰┫┃╱┃┃┃╱╱┃╰━━┫╰━━╮┃┃┃┃┃╱┃┃╭╮╭╮┃    |
 * |   ╱╱┃┃╱┃┃╱┃┃┃╱╭╋━━╮┃╭━━╯┃┃┃┃┃╱┃┃┃┃┃┃┃    |
 * |   ╱╱┃┃╱┃╰━╯┃╰━╯┃╰━╯┃╰━━┳╯╰╯┃╰━╯┃┃┃┃┃┃    |
 * |   ╱╱╰╯╱╰━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻╯╰╯╰╯    |
 * |__________________________________________|
 * |                                          |
 * | Permission is hereby granted, free of    |
 * | charge, to any person obtaining a copy of|
 * | of this software and accompanying files, |
 * | to use them without restriction,         |
 * | including, without limitation, the       |
 * | rights to use, copy, modify, merge,      |
 * | publish, distribute, sublicense and/or   |
 * | sell copies of the software. The authors |
 * | or copyright holders shall not be liable |
 * | for any claims, damages or other         |
 * | liability, whether in contract, tort or  |
 * | otherwise, arising out of or in          |
 * | connection with the software or your use |
 * | or other dealings with the software.     |
 * |__________________________________________|
 * |   website: tolsedum.ru                   |
 * |   email: tolsedum@gmail.com              |
 * |   email: tolsedum@yandex.ru              |
 * |__________________________________________|
 */
#include "content_reader/ContainerStr.hpp"
#include "content_reader/FileContainer.hpp"

/**
 * @version 1
 */
struct ContentSettings{
    bool is_file, is_content;

    ContentSettings(){
        is_file  = false;
        is_content = false;
    };
    ~ContentSettings(){};

    void setFileName(const std::string& file_name){
        is_file = true;
        is_content = false;
        content_or_file_name_ = file_name;
    }
    void setContent(const std::string& content){
        is_file = false;
        is_content = true;
        content_or_file_name_ = content;
    }
    std::string& getContent(){
        return content_or_file_name_;
    }
    std::string& getFileName(){
        return content_or_file_name_;
    }
private:
    std::string content_or_file_name_;
};

class ContentReader{

    std::shared_ptr<content_reader::Container> container_;
    
public:
    ContentReader(){};
    ContentReader(
        ContentSettings& contentParser
    );
    ContentReader(
        ContentSettings&& contentParser
    );
    ~ContentReader(){};

    /**
     * For class constructor
     */
    void contentInit(ContentSettings&& contentSettings);

    bool isEnd();
    bool isNotEnd();
    char current();
    char next();
    int pos();
    void setPos(int);
    std::size_t find(std::string_view, std::size_t s = 0);
    std::size_t find(char, std::size_t s = 0);
    std::size_t size();

    void print();
};

#endif // CONTENT_READER