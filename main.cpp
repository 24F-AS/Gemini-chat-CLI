#include <iostream>
#include "Conversation.h"
#include "GeminiClient.h"

int main() {
    Conversation convo;
    convo.loadFromFile("chat_history.json");

    GeminiClient client;

    std::cout << "Gemini Chat CLI\n";
    std::cout << "Commands: /new, /load file.json, /export file.md\n";

    std::string input;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) break;

        if (input == "/new") {
            convo.clear();
            std::cout << "New conversation started\n";
            continue;
        }

        if (input.rfind("/load", 0) == 0) {
            std::string file = input.substr(6);
            if (convo.loadFromFile(file))
                std::cout << "Loaded conversation\n";
            else
                std::cout << "Failed to load file\n";
            continue;
        }

        if (input.rfind("/export", 0) == 0) {
            std::string file = input.substr(8);
            if (convo.exportMarkdown(file))
                std::cout << "Exported to " << file << "\n";
            else
                std::cout << "Export failed\n";
            continue;
        }

        convo.addMessage("user", input);

        try {
            std::string reply = client.sendMessage(convo.toJson());
            convo.addMessage("model", reply);
            std::cout << reply << "\n";
            convo.saveToFile("chat_history.json");
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}
