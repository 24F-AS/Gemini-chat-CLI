cmake_minimum_required(VERSION 3.10)
project(GeminiChatCLI)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(gemini
    main.cpp
    Conversation.cpp
    GeminiClient.cpp
)

target_include_directories(gemini PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(gemini PRIVATE ${CURL_LIBRARIES})
