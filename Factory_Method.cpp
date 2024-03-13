#include <iostream>
#include <string>
using namespace std;

// Interface DongVat
class DongVat {
public:
    virtual void TiengKeu() = 0;
};

class Cho : public DongVat {
public:
    void TiengKeu(){
        cout << "Go go!" << endl;
    }
};

class Meo : public DongVat {
public:
    void TiengKeu(){
        cout << "Meo meo!" << endl;
    }
};

enum eTiengType
{
    TIENG_CHO = 0,
    TIENG_MEO
};

// Factory Method
class DongVatFactory {
public:
    static DongVat* CreateDongVat(const int& type) {
        if (type == TIENG_CHO) {
            return new Cho();
        } else if (type == TIENG_MEO) {
            return new Meo();
        } else {
            return nullptr;
        }
    }
};

int main() {
    DongVat* cho = DongVatFactory::CreateDongVat(TIENG_CHO);
    if (cho != nullptr) {
        cho->TiengKeu();
        delete cho;
    }

    DongVat* meo = DongVatFactory::CreateDongVat(TIENG_MEO);
    if (meo != nullptr) {
        meo->TiengKeu();
        delete meo;
    }

    return 0;
}

