#pragma once
#include <string>
#include <taglib/fileref.h>

/** 
 * @class ID3Reader
 * @brief Class for reading ID3 metadata from MP3 files.
 * 
 * Opens the specified file and checks for a valid ID3 tag.
 * Throws an exception if the file is invalid or the tag is missing.
 * 
 */
class ID3Reader{
public:
    /**
     * @brief Constructs an ID3Reader for the given MP3 file.
     *
     * Opens the specified file and checks for a valid ID3 tag.
     * 
     * @param filePath Path to the MP3 file to read.
     * @throws std::runtime_error if the file is invalid or ID3 tag is missing.
     */
    ID3Reader(const std::string & filePath);

    /**
     * @brief Returns the track title (TIT2 tag).
     * 
     * @return Track title as std::string.
     */
    std::string getTitle() const;

    /**
     * @brief Extracts the track's cover (APIC tag).
     * 
     * If a picture is found, it is saved into current directory and method returns true.
     * If no APIC tag is present, method returns false.
     * 
     * @return True if picture was found and saved, false otherwise.
     */
    bool extractPicture() const;

private:
    std::string filePath_;
    TagLib::FileRef tagFile_;
};