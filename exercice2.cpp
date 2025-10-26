
#include <iostream>
#include <iomanip>
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:
   
    Buffer() : size(0), data(nullptr) {
        cout << "Buffer de 0 octet(s)" << endl;
    }

    
    Buffer(size_t n) : size(n) {
        data = new unsigned char[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = 0;
        cout << "Buffer de " << size << " octet(s) : ";
        printHex();
    }

    
    Buffer(const Buffer& autre) : size(autre.size) {
        if (size > 0) {
            data = new unsigned char[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = autre.data[i];
        } else {
            data = nullptr;
        }
        cout << "Copie : " << size << " octet(s) : ";
        printHex();
    }

   
    void fill(unsigned char value) {
        for (size_t i = 0; i < size; ++i)
            data[i] = value;
    }

    void printHex() const {
        for (size_t i = 0; i < size; ++i)
            cout << setw(2) << setfill('0') << hex << uppercase << (int)data[i] << " ";
        cout << dec << endl;
    }


    ~Buffer() {
        cout << "Destruction du buffer de " << size << " octets" << endl;
        delete[] data;
    }
};


int main() {
    Buffer buf1;           

    Buffer buf2(8);        
    buf2.fill(0xAA);       

    Buffer buf3 = buf2;    

    return 0; 
}
