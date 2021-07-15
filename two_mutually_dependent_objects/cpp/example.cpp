#include <iostream>
#include <thread>

#include "channel.h"
#include "message.h"
#include "object.h"

using namespace std;


int main() {
    Channel<Message> a_to_b;
    Channel<Message> b_to_a;

    Object a("A", 42, b_to_a, a_to_b);
    Object b("B", 64, a_to_b, b_to_a);

    thread thread_a{a};
    thread thread_b{b};

    thread_a.join();
    thread_b.join();
}
