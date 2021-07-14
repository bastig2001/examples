#pragma once

#include <string>

#include "channel.h"
#include "message.h"


// An Object that does something (it's just an example)
class Object {
  private:
    std::string name;
    ReceivingChannel<Message>* inbox;
    SendingChannel<Message>* other;

  public:
    Object(
        std::string name, 
        ReceivingChannel<Message>* inbox, 
        SendingChannel<Message>* other
    ): name{name}, inbox{inbox}, other{other}
    {}

    // the execution loop of the object, 
    // which has to be run in a separate thread
    void operator()();
};
