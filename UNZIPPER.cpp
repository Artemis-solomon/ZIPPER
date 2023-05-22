//UNZIPPER
//Decompress files
//Written by: Artemis Solomon

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <zlib.h>

std::vector<unsigned char> uncompressFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    // Read file contents into a buffer
    std::vector<unsigned char> compressedData(std::istreambuf_iterator<char>(file), {});

    // Check if the file is empty
    if (compressedData.empty()) {
        std::cerr << "File is empty." << std::endl;
        return {};
    }

    // Determine the compression format
    int windowBits = 0;
    if (compressedData.size() >= 2) {
        if ((compressedData[0] & 0x0F) == 0x08 && (compressedData[0] >> 4) <= 7) {
            windowBits = -((compressedData[0] >> 4) + 8);
        }
    }

    // Calculate the uncompressed size
    uLong destSize = 0;
    uLong sourceSize = static_cast<uLong>(compressedData.size());

    if (uncompress(nullptr, &destSize, compressedData.data(), sourceSize) != Z_OK) {
        std::cerr << "Failed to determine uncompressed size." << std::endl;
        return {};
    }

    // Uncompress the data
    std::vector<unsigned char> uncompressedData(destSize);

    if (uncompress(uncompressedData.data(), &destSize, compressedData.data(), sourceSize) != Z_OK) {
        std::cerr << "Uncompression failed." << std::endl;
        return {};
    }

    // Resize the uncompressed buffer to the actual uncompressed size
    uncompressedData.resize(destSize);

    return uncompressedData;
}

int main() {
    std::string filename = "compressed.bin";

    // Uncompress the file
    std::vector<unsigned char> uncompressedData = uncompressFile(filename);

    if (!uncompressedData.empty()) {
        std::cout << "Uncompression successful. Uncompressed size: " << uncompressedData.size() << " bytes." << std::endl;

        // Save the uncompressed data to a new file
        std::string uncompressedFilename = "uncompressed.txt";
        std::ofstream uncompressedFile(uncompressedFilename, std::ios::binary);
        if (uncompressedFile) {
            uncompressedFile.write(reinterpret_cast<const char*>(uncompressedData.data()), uncompressedData.size());
            uncompressedFile.close();
            std::cout << "Uncompressed file saved as: " << uncompressedFilename << std::endl;
        } else {
            std::cerr << "Error saving uncompressed file." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Uncompression failed or input file is empty." << std::endl;
        return 1;
    }

    return 0;
}
