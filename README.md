# Gemini Chat CLI

A lightweight command-line interface for interacting with Google's Gemini API, built in C++.

## Overview

Gemini Chat CLI is a C++ application that provides a terminal-based chat interface for Google's Gemini AI models. It allows users to have conversational interactions with Gemini directly from the command line, featuring conversation management and a clean, efficient implementation.

## Features

- **Interactive Chat Interface**: Engage in real-time conversations with Gemini AI from your terminal
- **Conversation Management**: Maintains chat history and context throughout your session
- **C++ Implementation**: Fast, efficient, and lightweight native application
- **Clean Architecture**: Modular design with separate components for client and conversation handling

## Project Structure

```
Gemini-chat-CLI/
├── main.cpp              # Application entry point
├── GeminiClient.h        # Gemini API client header
├── GeminiClient.cpp      # Gemini API client implementation
├── Conversation.h        # Conversation management header
├── Conversation.cpp      # Conversation management implementation
├── CMakeLists.txt        # CMake build configuration
├── LICENSE               # MIT License
└── README.md             # This file
```

## Prerequisites

Before building and running this project, ensure you have:

- **C++ Compiler**: Support for C++11 or later (GCC, Clang, or MSVC)
- **CMake**: Version 3.10 or higher
- **cURL library**: For making HTTP requests to the Gemini API
- **Google Gemini API Key**: Obtain one from [Google AI Studio](https://makersuite.google.com/app/apikey)

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/24F-AS/Gemini-chat-CLI.git
cd Gemini-chat-CLI
```

### 2. Install Dependencies

**On Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential cmake libcurl4-openssl-dev
```

**On macOS:**
```bash
brew install cmake curl
```

**On Windows:**
- Install [Visual Studio](https://visualstudio.microsoft.com/) with C++ support
- Install [CMake](https://cmake.org/download/)
- Install cURL library or use vcpkg: `vcpkg install curl`

### 3. Set Up API Key

You'll need to configure your Gemini API key. You can either:

**Option A: Environment Variable**
```bash
export GEMINI_API_KEY="your_api_key_here"
```

**Option B: Configuration File**
Create a config file (check the source code for the expected format and location)

### 4. Build the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Or use the traditional approach:
```bash
mkdir build
cd build
cmake ..
make
```

## Usage

After building, run the executable:

```bash
./GeminiChatCLI
```

### Basic Commands

Once the application starts:
- Type your messages and press Enter to send them to Gemini
- The AI will respond in the terminal
- Type `exit` or `quit` to end the session (check the source code for exact commands)

### Example Session

```
You: Hello! What can you help me with?
Gemini: Hello! I'm Gemini, an AI assistant. I can help you with a wide variety of tasks...

You: Can you explain what a binary search tree is?
Gemini: A binary search tree (BST) is a data structure that...
```

## Configuration

The application may support various configuration options. Common configurations include:

- **API Key**: Required for authentication with Google's Gemini API
- **Model Selection**: Choose which Gemini model to use (if supported)
- **Conversation Settings**: Adjust context length, temperature, or other parameters

Check the source code or create a configuration file for detailed options.

## Development

### Building in Debug Mode

```bash
mkdir build-debug
cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

### Code Structure

- **GeminiClient**: Handles all communication with the Gemini API, including authentication, request formatting, and response parsing
- **Conversation**: Manages the conversation state, message history, and context
- **main.cpp**: Coordinates the CLI interface and user interaction

### Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

Please ensure your code:
- Follows the existing code style
- Includes appropriate comments
- Builds without warnings
- Works as expected

## Troubleshooting

### Common Issues

**Problem**: `libcurl not found` error during build
- **Solution**: Install the cURL development library (see Installation section)

**Problem**: API authentication fails
- **Solution**: Verify your API key is correctly set and valid

**Problem**: Build errors with CMake
- **Solution**: Ensure you have CMake 3.10+ and a compatible C++ compiler

**Problem**: Connection timeout or network errors
- **Solution**: Check your internet connection and firewall settings

## API Rate Limits

Be aware of Google's Gemini API rate limits:
- Free tier: Limited requests per minute
- Check [Google AI Studio](https://makersuite.google.com/) for current limits
- The application may need error handling for rate limit responses

## Security Notes

- **Never commit your API key** to version control
- Store API keys securely using environment variables or secure configuration files
- Be cautious about sharing conversation logs that may contain sensitive information
- Review Google's terms of service for the Gemini API

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Google Gemini API for providing the AI capabilities
- The C++ and CMake communities for excellent tools and documentation

## Links

- [Google Gemini API Documentation](https://ai.google.dev/docs)
- [Google AI Studio](https://makersuite.google.com/)
- [Project Repository](https://github.com/24F-AS/Gemini-chat-CLI)

## Roadmap

Potential future enhancements:
- [ ] Support for multimodal inputs (images, files)
- [ ] Persistent conversation history across sessions
- [ ] Configuration file support
- [ ] Multiple model selection
- [ ] Streaming responses
- [ ] Color-coded terminal output
- [ ] Command history with arrow keys
- [ ] Export conversation to file

## Contact

For questions, issues, or suggestions, please open an issue on the [GitHub repository](https://github.com/24F-AS/Gemini-chat-CLI/issues).

---

**Note**: This project is not officially affiliated with Google. It is an independent implementation for educational and practical purposes.
