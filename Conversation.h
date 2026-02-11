#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

struct Message {
    std::string role;
    std::string content;
    std::string timestamp;
};

class Conversation {
private:
    std::vector<Message> messages;

public:
    void addMessage(const std::string& role, const std::string& content);
    nlohmann::json toJson() const;
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
    bool exportMarkdown(const std::string& filename) const;
    void clear();
};

#endif
