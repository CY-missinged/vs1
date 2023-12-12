#include <iostream>
#include <string.h>

using namespace std;

class Mammal
{
public:
    virtual void sp() const = 0;
    Mammal()
    {
        strcpy(s, "");
    }
    void Speak()
    {
        sp();
    }

private:
    char s[10];
};

class Dog : public Mammal
{
public:
    Dog()
    {
        strcpy(s, "ÍôÍôÍô");
    }
    ~Dog()
    {
        ;
    }
    void sp() const
    {
        cout << s << endl;
    }

private:
    char s[10];
};

class Cat : public Mammal
{
public:
    Cat()
    {
        strcpy(s, "ß÷ß÷ß÷");
    }
    ~Cat()
    {
        ;
    }
    void sp() const
    {
        cout << s << endl;
    }

private:
    char s[10];
};

void CallSpeak(Mammal &m)
{
    m.Speak();
}

int main()
{
    Dog dog;
    Cat cat;
    CallSpeak(dog);
    CallSpeak(cat);
    return 0;
}
