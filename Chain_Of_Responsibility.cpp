#include <iostream>
#include <string>

using namespace std;

// Abstract Handler
class Handler {
protected:
    Handler *nextHandler;

public:
    virtual ~Handler() {}
    void setNext(Handler *handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(const string &request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

// Handler 1: Manager
class Manager : public Handler {
public:
    void handleRequest(const string &request) {
        if (request == "Truong phong") {
            cout << "OK toi cho ban lam truong phong." << endl;
        } else {
            cout << "De toi bao giam doc nha." << endl;
            Handler::handleRequest(request);
        }
    }
};

// Handler 2: Director
class Director : public Handler {
public:
    void handleRequest(const string &request){
        cout << "OK toi cho ban lam pho giam doc." << endl;
    }
};

int main() {
    Manager manager;
    Director director;

    manager.setNext(&director);

    cout << "Khach hang: Toi muon lam truong phong" << endl;
    manager.handleRequest("Truong phong");

    cout << "Khach hang: Toi muon lam pho giam doc" << endl;
    manager.handleRequest("Pho giam doc");

    return 0;
}
