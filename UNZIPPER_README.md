# File Uncompression Program

This C++ program demonstrates file uncompression using the zlib library. It allows you to uncompress files that are compressed using various compression formats, including the deflate format.

## Features

- Uncompresses files using the zlib library and supports various compression formats.
- Supports uncompression of files of any type.
- Saves the uncompressed data to a new file.

## Prerequisites

- C++ compiler with C++11 support
- zlib library (Install the zlib development package)

## Usage

1. Clone the repository or download the source files.
2. Compile the program using your preferred C++ compiler, linking against the zlib library. For example:
   ```
   g++ main.cpp -o file_uncompression -lz
   ```
3. Run the compiled program with the filename of the file you want to uncompress as a command-line argument. For example:
   ```
   ./file_uncompression compressed.bin
   ```
4. If the uncompression is successful, the program will display the uncompressed size and save the data to a new file named `uncompressed.txt` in the same directory.

## Error Handling

The program includes error handling to handle various scenarios:

- If the file cannot be opened or does not exist, an error message is displayed.
- If the file is empty, an error message is displayed.
- If the uncompression fails or the compression format is not supported, an error message is displayed.
- If there is an error while saving the uncompressed file, an error message is displayed.

Please note that this program assumes a basic use case and may not support all compression formats. It is recommended to extend the program to handle additional compression formats as needed.

## Contributing

Contributions to improve the program or add new features are welcome. Please fork the repository, make your changes, and submit a pull request.

## License

This program is licensed under the [MIT License](LICENSE).

## Disclaimer

Usage of this program for any malicious or illegal activities is strictly prohibited. The program is intended for educational and legitimate purposes only. The author and contributors are not responsible for any misuse or damages caused by using this program.

Please use this program responsibly and adhere to ethical guidelines when working with file uncompression.

## Contact

For any questions, feedback, or suggestions, please contact artemis@dnmx.org.

Feel free to reach out if you have any queries or need further assistance.

## References

- zlib Library Documentation: [https://www.zlib.net/manual.html](https://www.zlib.net/manual.html)
- C++ Reference: [https://en.cppreference.com/](https://en.cppreference.com/)
