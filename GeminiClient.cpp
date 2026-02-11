#include "GeminiClient.h"
#include <curl/curl.h>
#include <cstdlib>
#include <stdexcept>

static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t total = size * nmemb;
    s->append((char*)contents, total);
    return total;
}

GeminiClient::GeminiClient() {
    const char* key = std::getenv("GEMINI_API_KEY");
    if (!key) {
        throw std::runtime_error("GEMINI_API_KEY not set");
    }
    apiKey = key;
}

std::string GeminiClient::sendMessage(const nlohmann::json& conversationJson) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Failed to init curl");

    std::string response;
    std::string url =
        "https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=" + apiKey;

    nlohmann::json payload = {
        {"contents", conversationJson["messages"]}
    };

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.dump().c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    CURLcode res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    if (res != CURLE_OK) {
        throw std::runtime_error("Network error");
    }

    auto json = nlohmann::json::parse(response);

if (!json.contains("candidates") || json["candidates"].empty()) {
    throw std::runtime_error("No response from Gemini");
}

auto& parts = json["candidates"][0]["content"]["parts"];

if (parts.empty() || parts[0]["text"].is_null()) {
    throw std::runtime_error("Gemini returned empty response");
}

return parts[0]["text"].get<std::string>();

}
