#include "ID3Reader.hpp"

#include <taglib/fileref.h>
#include <taglib/mpegfile.h>

ID3Reader::ID3Reader(const std::string & filePath) : filePath_(filePath), tagFile_(filePath.c_str()){
    if(tagFile_.isNull() || !tagFile_.file()->isValid()){
        throw std::runtime_error("File is invalid");
    }

    auto mpegFile = dynamic_cast<TagLib::MPEG::File*>(tagFile_.file());
    if(!mpegFile){
        throw std::runtime_error("File is not MP3");
    }

    if(!mpegFile->hasID3v1Tag() && !mpegFile->hasID3v2Tag()){
        throw std::runtime_error("MP3 file has no ID3 tag");
    }
}

std::string ID3Reader::getTitle() const{

}

bool ID3Reader::extractPicture() const{

}
