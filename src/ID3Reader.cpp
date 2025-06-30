#include "ID3Reader.hpp"

#include <fstream>
#include <algorithm>

#include <taglib/fileref.h>
#include <taglib/mpegfile.h>
#include <taglib/tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/attachedpictureframe.h>

ID3Reader::ID3Reader(const std::string & filePath) : filePath_(filePath), tagFile_(filePath.c_str()){
    if(tagFile_.isNull() || !tagFile_.file()->isValid()){
        throw std::runtime_error("File is invalid");
    }

    TagLib::MPEG::File * mpegFile = dynamic_cast<TagLib::MPEG::File*>(tagFile_.file());
    if(!mpegFile){
        throw std::runtime_error("File is not MP3");
    }

    if(!mpegFile->hasID3v1Tag() && !mpegFile->hasID3v2Tag()){
        throw std::runtime_error("MP3 file has no ID3 tag");
    }
}

std::string ID3Reader::getTitle() const{
    return tagFile_.tag()->title().to8Bit();
}

bool ID3Reader::extractPicture() const{
    TagLib::MPEG::File file(filePath_.c_str());

    TagLib::ID3v2::Tag * tag = file.ID3v2Tag();

    if(!tag){
        return false;
    }

    TagLib::ID3v2::FrameList frames = tag->frameList("APIC");
    if(frames.isEmpty()){
        return false;
    }

    TagLib::ID3v2::AttachedPictureFrame * cover = dynamic_cast<TagLib::ID3v2::AttachedPictureFrame *>(frames.front());
    if(!cover){
        return false;
    }
    
    std::string title = "Cover_" + getTitle();
    std::replace(title.begin(), title.end(), ' ', '_');
    title += ".jpg";
    
    std::ofstream coverFile(title, std::ios_base::out | std::ios::binary);
    if(!coverFile){
        return false;
    }

    coverFile.write(cover->picture().data(), cover->picture().size());
    coverFile.close();

    return true;
}
