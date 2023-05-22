# ZIPPER

## File Compression Program

This C++ program demonstrates file compression using the zlib library. It allows you to compress any file using the deflate algorithm and save the compressed data to a new file.

## Features

- Compresses files using the zlib library and the deflate algorithm.
- Supports compression of files of any type.
- Saves the compressed data to a new file.

## Prerequisites

- C++ compiler with C++11 support
- zlib library (Install the zlib development package)

## Usage

1. Clone the repository or download the source files.
2. Compile the program using your preferred C++ compiler, linking against the zlib library. For example:
   ```
   g++ main.cpp -o file_compression -lz
   ```
3. Run the compiled program with the filename of the file you want to compress as a command-line argument. For example:
   ```
   ./file_compression example.txt
   ```
4. If the compression is successful, the program will display the compressed size and save the compressed data to a new file named `compressed.bin` in the same directory.

## Error Handling

The program includes error handling to handle various scenarios:

- If the file cannot be opened or does not exist, an error message is displayed.
- If the file is empty, an error message is displayed.
- If the compression fails, an error message is displayed.
- If there is an error while saving the compressed file, an error message is displayed.

Please note that this program assumes a basic use case and does not handle advanced scenarios like handling directories, compression options, or large files. It is recommended to enhance the program based on your specific requirements.

## Contributing

Contributions to improve the program or add new features are welcome. Please fork the repository, make your changes, and submit a pull request.

## License

This program is licensed under the [MIT License](LICENSE).

## Disclaimer

Usage of this program for any malicious or illegal activities is strictly prohibited. The program is intended for educational and legitimate purposes only. The author and contributors are not responsible for any misuse or damages caused by using this program.

Please use this program responsibly and adhere to ethical guidelines when working with file compression.

## Contact

For any questions, feedback, or suggestions, please contact artemis@dnmx.org.

Feel free to reach out if you have any queries or need further assistance.

## References

- zlib Library Documentation: [https://www.zlib.net/manual.html](https://www.zlib.net/manual.html)
- C++ Reference: [https://en.cppreference.com/](https://en.cppreference.com/)
