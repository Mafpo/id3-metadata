#include "ID3Reader.hpp"

#include <iostream>

int main(int argc, char * argv[]){
    if(argc < 2){
        std::cerr << "Usage: ./app <path_to_mp3>\n";
        return EXIT_FAILURE;
    }
    
    ID3Reader file(argv[1]);

    // Prints title on std::cout
    std::cout << "Title: ";
    std::string title = file.getTitle();
    if(title != ""){
        std::cout << title << std::endl;
    } else {
        std::cout << "Track has no title.\n";
    }

    // Saves track's cover art into current directory
    if(file.extractPicture()){
        std::cout << "Cover art successfully extracted.\n";
    } else {
        std::cout << "No cover art found in the track.\n";
    }

    return EXIT_SUCCESS;
}