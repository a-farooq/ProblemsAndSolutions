#include <iostream>

using namespace std;

class Family
{
private:
    enum _name
    {
        FATHER,
        MOTHER,
        DAUGHTER,
        SON
    } name;

    string getName() const
    {
        switch(name) {
            case FATHER: return "FATHER"; break;
            case MOTHER: return "MOTHER"; break;
            case DAUGHTER: return "DAUGHTER"; break;
            case SON: return "SON"; break;
            default: return ""; break;
        }
    }

    void increment()
    {
        switch(name) {
            case FATHER: name = MOTHER; break;
            case MOTHER: name = DAUGHTER; break;
            case DAUGHTER: name = SON; break;
            case SON: name = FATHER; break;
        }
    }
public:
    Family() : name(FATHER) {}

    Family operator++()
    {
        increment();
        return *this;
    }
    
    Family operator++(int)
    {
        const Family temp(*this);
        ++(*this);
        return temp;
    }

    friend ostream& operator << (ostream& out, const Family& f);
};

ostream& operator << (ostream& out, const Family& f)
{
    out << f.getName();
    return out;
}

int main()
{
    Family f1;
    //cout << f1.getName() << endl;
    cout << ++f1 << endl;
    //++f1;
    cout << f1++ << endl;
    //cout << f1.getName() << endl;
    cout << f1 << endl;
}
