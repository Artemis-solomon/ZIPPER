# ZIPPER

## File Compression

1. Clone the repository or download the source files.
2. Ensure you have a C++ compiler installed with C++11 support.
3. Compile the program using your preferred C++ compiler.
   ```
   g++ main.cpp -o file_compression
   ```
4. Run the compiled program with the filename of the file you want to compress as a command-line argument.
   ```
   ./file_compression original.txt
   ```
5. If the compression is successful, the program will create a new file named `compressed.bin` in the same directory, which contains the compressed data.

## File Uncompression

1. Clone the repository or download the source files.
2. Ensure you have a C++ compiler installed with C++11 support.
3. Compile the program using your preferred C++ compiler, linking against the zlib library.
   ```
   g++ main.cpp -o file_uncompression -lz
   ```
4. Run the compiled program with the filename of the file you want to uncompress as a command-line argument.
   ```
   ./file_uncompression compressed.bin
   ```
5. If the uncompression is successful, the program will display the uncompressed size and save the data to a new file named `uncompressed.txt` in the same directory.

Note: Ensure that you have the zlib library installed and accessible during the compilation of the file uncompression program. The zlib development package may need to be installed on your system.

Please remember that these programs support basic use cases and may not handle all compression formats. They are intended for educational and legitimate purposes only. Any misuse or illegal activities with these programs are strictly prohibited. Always use these programs responsibly and adhere to ethical guidelines when working with file compression and uncompression.

If you have any questions or encounter any issues, please refer to the README or contact the project maintainers for further assistance.
