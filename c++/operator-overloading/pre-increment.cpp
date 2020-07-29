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

public:
    Family() : name(FATHER) {}

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
    void operator++()
    {
        switch(name) {
            case FATHER: name = MOTHER; break;
            case MOTHER: name = DAUGHTER; break;
            case DAUGHTER: name = SON; break;
            case SON: name = FATHER; break;
        }
    }
    
    void operator++(int)
    {
        switch(name) {
            case FATHER: name = MOTHER; break;
            case MOTHER: name = DAUGHTER; break;
            case DAUGHTER: name = SON; break;
            case SON: name = FATHER; break;
        }
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
    cout << f1.getName() << endl;
    ++f1;
    ++f1;
    f1++;
    //cout << f1.getName() << endl;
    cout << f1 << endl;
}
