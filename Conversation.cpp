#include "Conversation.h"
#include <fstream>
#include <chrono>
#include <iomanip>

static std::string currentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::gmtime(&t), "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
}

void Conversation::addMessage(const std::string& role, const std::string& content) {
    messages.push_back({role, content, currentTimestamp()});
}

nlohmann::json Conversation::toJson() const {
    nlohmann::json j;
    for (const auto& msg : messages) {
        j["messages"].push_back({
            {"role", msg.role},
            {"content", msg.content},
            {"timestamp", msg.timestamp}
        });
    }
    return j;
}

bool Conversation::saveToFile(const std::string& filename) const {
    std::ofstream out(filename + ".tmp");
    if (!out) return false;
    out << toJson().dump(2);
    out.close();
    std::rename((filename + ".tmp").c_str(), filename.c_str());
    return true;
}

bool Conversation::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;

    nlohmann::json j;
    in >> j;
    messages.clear();

    for (auto& m : j["messages"]) {
        messages.push_back({
            m["role"],
            m["content"],
            m["timestamp"]
        });
    }
    return true;
}

bool Conversation::exportMarkdown(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;

    for (const auto& m : messages) {
        out << "### " << (m.role == "user" ? "User" : "Gemini") << "\n";
        out << m.content << "\n\n";
    }
    return true;
}

void Conversation::clear() {
    messages.clear();
}
