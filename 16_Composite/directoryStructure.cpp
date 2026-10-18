#include <iostream>
#include <vector>

using namespace std;

class FileSystemComponent
{
public:
    virtual void listOfContents() = 0;
    virtual double getSize() = 0;
    virtual ~FileSystemComponent() = default;
};

class File : public FileSystemComponent
{
    string name;
    double size;
public:
    File(const string& fileName, double fileSize) : name(fileName), size(fileSize) {}

    void listOfContents() override {
        cout<< "File: " << name << ", Size: " << size << " MB" << endl;
    }

    double getSize() override {
        return size;
    }
};

class Directory : public FileSystemComponent
{
    string name;
    vector<FileSystemComponent*> components;
public:
    Directory(const string& dirName) : name(dirName) {}

    void addComponent(FileSystemComponent* component) {
        components.push_back(component);
    }

    void listOfContents() override {
        cout << "Directory: " << name << endl;
        for (auto component : components) {
            component->listOfContents();
        }
    }

    double getSize() override {
        double totalSize = 0;
        for (auto component : components) {
            totalSize += component->getSize();
        }
        return totalSize;
    }
};

int main() {
    Directory* root = new Directory("Root");
    File* file1 = new File("File1.txt", 1.5);
    File* file2 = new File("File2.txt", 2.0);
    Directory* subDir = new Directory("SubDirectory");
    File* file3 = new File("File3.txt", 3.0);

    root->addComponent(file1);
    root->addComponent(file2);
    subDir->addComponent(file3);
    root->addComponent(subDir);

    root->listOfContents();
    cout << "Total Size: " << root->getSize() << " MB" << endl;

    delete file1;
    delete file2;
    delete file3;
    delete subDir;
    delete root;

    return 0;
}