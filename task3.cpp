#include <iostream>
#include <string>
using namespace std;

class Software { //any program
protected:
    string name;
public:
    Software() : name("Unknown Software") {}
    Software(string n) : name(n) {}
    virtual ~Software() {
        cout << "Destructor: Software\n";
    }

    friend istream& operator>>(istream& in, Software& s) {
        cout << "Enter software name: ";
        in >> s.name;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Software& s) {
        out << "Software Name: " << s.name << endl;
        return out;
    }
};

class SystemSoftware : virtual public Software { //drivers, utilites
protected:
    string systemType;
public:
    SystemSoftware() : systemType("Unknown System") {}
    SystemSoftware(string name, string systemType)
        : Software(name), systemType(systemType) {
    }
    virtual ~SystemSoftware() {
        cout << "Destructor: SystemSoftware\n";
    }

    friend istream& operator>>(istream& in, SystemSoftware& s) {
        cout << "Enter software name (system): ";
        in >> s.name;
        cout << "Enter system type: ";
        in >> s.systemType;
        return in;
    }

    friend ostream& operator<<(ostream& out, const SystemSoftware& s) {
        out << "Software Name (system): " << s.name << endl;
        out << "System Type: " << s.systemType << endl;
        return out;
    }
};

class AppliedSoftware : virtual public Software { //apps
protected:
    string appType;
public:
    AppliedSoftware() : appType("Unknown Application") {}
    AppliedSoftware(string name, string appType)
        : Software(name), appType(appType) {
    }
    virtual ~AppliedSoftware() {
        cout << "Destructor: AppliedSoftware\n";
    }

    friend istream& operator>>(istream& in, AppliedSoftware& a) {
        cout << "Enter software name (application): ";
        in >> a.name;
        cout << "Enter application type: ";
        in >> a.appType;
        return in;
    }

    friend ostream& operator<<(ostream& out, const AppliedSoftware& a) {
        out << "Software Name (application): " << a.name << endl;
        out << "Application Type: " << a.appType << endl;
        return out;
    }
};

class OperatingSystem : virtual public SystemSoftware, virtual public AppliedSoftware { //Windows, Linux
public:
    OperatingSystem() {}
    virtual ~OperatingSystem() {
        cout << "Destructor: OperatingSystem\n";
    }

    friend istream& operator>>(istream& in, OperatingSystem& os) {
        cout << "--- Enter Operating System Info ---\n";
        cout << "Enter common software name: ";
        in >> os.name;
        cout << "Enter application type: ";
        in >> os.appType;
        cout << "Enter system type: ";
        in >> os.systemType;
        return in;
    }

    friend ostream& operator<<(ostream& out, const OperatingSystem& os) {
        out << "Software Name: " << os.name << endl;
        out << "Application Type: " << os.appType << endl;
        out << "System Type: " << os.systemType << endl;
        return out;
    }
};

int main() {
    OperatingSystem os;
    cin >> os;
    cout << endl;
    cout << os;
    return 0;
}