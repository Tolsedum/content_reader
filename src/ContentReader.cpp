#include "ContentReader.hpp"

ContentReader::ContentReader(
    ContentSettings& contentSetting
){
    contentInit(std::forward<ContentSettings>(contentSetting));
}

ContentReader::ContentReader(
    ContentSettings&& contentSetting
){
    contentInit(std::forward<ContentSettings>(contentSetting));
}

void ContentReader::contentInit(
    ContentSettings&& contentSetting
){
    if(contentSetting.is_content){
        container_ = std::make_shared
            <content_reader::ContainerStr>(
                std::move(contentSetting.getContent())
        );
    }else if(contentSetting.is_file){
        container_ = std::make_shared
            <content_reader::FileContainer>(
                contentSetting.getFileName()
        );
    }
}

void ContentReader::clear(){
    container_->clear();
    container_.reset();
}

bool ContentReader::isEnd(){
    return container_->isEnd();
}

bool ContentReader::isNotEnd(){
    return container_->isNotEnd();
}

char ContentReader::current(){
    return container_->current();
}

char ContentReader::next(){
    return container_->next();
}

int ContentReader::pos(){
    return container_->pos();
}

void ContentReader::setPos(int new_pos){
    return container_->setPos(new_pos);
}

std::size_t ContentReader::find(
    std::string_view str, std::size_t s
){
    return container_->find(str, s);
}

std::size_t ContentReader::find(char c, std::size_t s ){
    return container_->find(c, s);
}

std::size_t ContentReader::size(){
    return container_->size();
}

void ContentReader::print(){
    container_->print();
}
