#include <iostream>

using namespace std;

class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image
{
    string filename;
public:
    RealImage(const string& file) : filename(file) {
        loadFromDisk();
    }

    void display() override {
        cout << "Displaying " << filename << endl;
    }

    void loadFromDisk() {
        cout << "Loading " << filename << " from disk." << endl;
    }
};

class ProxyImage : public Image
{
    RealImage* realImage;
    string filename;
public:
    ProxyImage(const string& file) : filename(file), realImage(nullptr) {}
    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }

    ~ProxyImage() {
        delete realImage;
    }
};

int main() {
    Image* image1 = new ProxyImage("image1.jpg");
    Image* image2 = new ProxyImage("image2.jpg");

    // Image will be loaded from disk and displayed
    image1->display();
    // Image will not be loaded from disk again, just displayed
    image1->display();

    // Image will be loaded from disk and displayed
    image2->display();
    // Image will not be loaded from disk again, just displayed
    image2->display();

    delete image1;
    delete image2;

    return 0;
}