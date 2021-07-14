#pragma once

#include <string>
#include <variant>


// Types of Messages the objects can send each other 
enum class MsgType {
    PrintHello,
    PrintMessage,
    GetValue,
    Value,
    SendToOther
};

struct Message;

// A restricted Message that one can send in a Message
struct RestrictedMessage {
    MsgType type;
    std::variant<int, std::string> argument;

    Message to_message();
};

using Argument = std::variant<int, std::string, RestrictedMessage>;

// Message the objects can send each other
struct Message {
    MsgType type;

    // to be able to transfer data depending on the type of the Message
    // one could also use polymorphism
    Argument argument;
};

Message RestrictedMessage::to_message() {
    return Message{
        type, 
        std::holds_alternative<int>(argument) 
            ? Argument(std::get<int>(argument))
            : Argument(std::get<std::string>(argument))
    };
}
