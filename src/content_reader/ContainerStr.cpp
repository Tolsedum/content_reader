#include "content_reader/ContainerStr.hpp"

void content_reader::ContainerStr::constructor_(){
    content_size_= container_.size();
    begin_ = container_.begin();
    end_ = container_.end();
    is_end_ = begin_ == end_;
    pos_ = 0;
}

bool content_reader::ContainerStr::isEnd(){
    auto begin = begin_;
    return content_size_ <= 0 || (is_end_ || (++begin == end_));
};

bool content_reader::ContainerStr::isNotEnd(){
    auto begin = begin_;
    return content_size_ > 0 || !(is_end_ || (++begin == end_));
};

char content_reader::ContainerStr::current(){
    return begin_[0];
}

char content_reader::ContainerStr::next(){
    if(!is_end_){
        begin_++;
        pos_++;
        if(begin_ == end_){
            begin_--;
            is_end_ = true;
        }
    }
    return begin_[0];
}

int content_reader::ContainerStr::pos(){
    return pos_;
}

void content_reader::ContainerStr::setPos(int new_pos){
    if(pos_ != new_pos){
        begin_ = container_.begin() + new_pos;
        pos_ = new_pos;
    }
}

std::size_t content_reader::ContainerStr::find(
    std::string_view str, std::size_t p
){
    return container_.find(str, p);
}

std::size_t content_reader::ContainerStr::find(
    char c, std::size_t p
){
    return container_.find(c, p);
}

std::size_t content_reader::ContainerStr::size(){
    return content_size_;
}