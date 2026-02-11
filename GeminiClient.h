#ifndef GEMINI_CLIENT_H
#define GEMINI_CLIENT_H

#include <string>
#include <nlohmann/json.hpp>

class GeminiClient {
private:
    std::string apiKey;

public:
    GeminiClient();
    std::string sendMessage(const nlohmann::json& conversationJson);
};

#endif
