#include <iostream>

using namespace std;

// Interface - BackEnd A
class UI_A
{
public:
    virtual void setName(string name) = 0;
    virtual string getName() = 0;
};

// BackEnd A
class BE_A : public UI_A
{
private:
    string mName;

public:
    void setName(string name)
    {
        mName = name;
    }

    string getName()
    {
        return mName;
    }
};

// Interface - BackEnd B
class UI_B
{
    virtual void setFirstName(string firstName) = 0;
    virtual void setLastName(string lastName) = 0;
    virtual string getFirstName() = 0;
    virtual string getLastName() = 0;
};

// BackEnd B
class BE_B
{
private:
    string mFirstName;
    string mLastName;

public:
    void setFirstName(string firstName)
    {
        mFirstName = firstName;
    }

    void setLastName(string lastName)
    {
        mLastName = lastName;
    }

    string getFirstName()
    {
        return mFirstName;
    }

    string getLastName()
    {
        return mLastName;
    }
};

// Adapter
class Adapter : public BE_A
{
private:
    BE_A mUser;
    string mFirstName;
    string mLastName;

public:
    Adapter(BE_A user)
    {
        mUser = user;
        unsigned int splitPostion = user.getName().find_first_of(" ");
        if (splitPostion != string::npos)
        {
            mFirstName = user.getName().substr(0, splitPostion + 1);
            mLastName = user.getName().substr(splitPostion + 1, user.getName().length() - mFirstName.length());
        }
    }

    void setFirstName(string firstName)
    {
        mFirstName = firstName;
    }

    void setLastName(string lastName)
    {
        mLastName = lastName;
    }

    string getFirstName()
    {
        return mFirstName;
    }

    string getLastName()
    {
        return mLastName;
    }
};
int main()
{
    BE_A user;
    user.setName("Dung Nguyen Quang");

    Adapter adapter(user);
    cout << "First Name: " << adapter.getFirstName() << endl;
    cout << "Last Name: " << adapter.getLastName() << endl;

    return 0;
}
