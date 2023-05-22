//ZIPPER File Compression Program
//Wriiten by: Artemis Solomon

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <zlib.h>

std::vector<unsigned char> compressFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    // Read file contents into a buffer
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});

    // Check if the file is empty
    if (buffer.empty()) {
        std::cerr << "File is empty." << std::endl;
        return {};
    }

    // Compress the buffer
    uLong sourceSize = static_cast<uLong>(buffer.size());
    uLong destSize = compressBound(sourceSize);
    std::vector<unsigned char> compressed(destSize);

    if (compress(compressed.data(), &destSize, buffer.data(), sourceSize) != Z_OK) {
        std::cerr << "Compression failed." << std::endl;
        return {};
    }

    // Resize the compressed buffer to the actual compressed size
    compressed.resize(destSize);

    return compressed;
}

int main() {
    std::string filename = "example.txt";

    // Compress the file
    std::vector<unsigned char> compressedData = compressFile(filename);

    if (!compressedData.empty()) {
        std::cout << "Compression successful. Compressed size: " << compressedData.size() << " bytes." << std::endl;

        // Save the compressed data to a new file
        std::string compressedFilename = "compressed.bin";
        std::ofstream compressedFile(compressedFilename, std::ios::binary);
        if (compressedFile) {
            compressedFile.write(reinterpret_cast<const char*>(compressedData.data()), compressedData.size());
            compressedFile.close();
            std::cout << "Compressed file saved as: " << compressedFilename << std::endl;
        } else {
            std::cerr << "Error saving compressed file." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Compression failed or input file is empty." << std::endl;
        return 1;
    }

    return 0;
}
