/*
#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class Manager
{
private:
    static Manager* mManagerPtr;
    string mName;
    static mutex mLocker;

    Manager(string Name)
    {
        mName = Name;
    }

public:
    string getName()
    {
        return mName;
    }

    static Manager* getManager(string Name)
    {
        mLocker.lock();
        if (mManagerPtr == nullptr)
        {
            mManagerPtr = new Manager(Name);
        }
        mLocker.unlock();
        return mManagerPtr;
    }
};

Manager* Manager::mManagerPtr = nullptr;
mutex Manager::mLocker;

int main()
{
    Manager* manager1 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager1->getName() << endl;
    Manager* manager2 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager2->getName() << endl;
    Manager* manager3 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager3->getName() << endl;
    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

class Manager
{
private:
    string mName;

    Manager(string Name)
    {
        mName = Name;
    }

public:
    string getName()
    {
        return mName;
    }

    static Manager* getManager(string Name)
    {
        static Manager mManagerPtr(Name);
        return &mManagerPtr;
    }
};

int main()
{
    Manager* manager1 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager1->getName() << endl;
    Manager* manager2 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager2->getName() << endl;
    Manager* manager3 = Manager::getManager("Dung");
    cout << "Quan ly la " << manager3->getName() << endl;
    return 0;
}


