#include <iostream>

using namespace std;

// Data analytics tool that expects JSON data
// Adaptee
class JSONAnalyticsTool
{
    string pJsonData;

public:
    void setJsonData(string jsonData) {
        pJsonData = jsonData;
    }
    void AnalyzeData()
    {
        if (pJsonData.find("json") != string::npos) {
            cout << "Analysing JSON Data - " << pJsonData << endl;
        } else {
            cout << "Not correct format. Can't analyse! " << endl;
        }
    }
};

class AnalyticsToolAdapter
{
public:
    virtual void setData(string data) = 0;
    virtual void AnalyzeData() = 0;
    virtual ~AnalyticsToolAdapter() = default;
};

class XMLToJSONAdapter : public AnalyticsToolAdapter, public JSONAnalyticsTool
{
public:
    void setData(string data) override {
        // Convert XML to JSON (dummy conversion for demonstration)
        string jsonData = "<xml>" + data + "</xml>"; // Dummy conversion
        setJsonData(jsonData);
    }

    void AnalyzeData() override {
        JSONAnalyticsTool::AnalyzeData();
    }
};

int main() {
    AnalyticsToolAdapter* adapter = new XMLToJSONAdapter();
    adapter->setData("<data>Sample XML Data</data>");
    adapter->AnalyzeData();

    delete adapter;
    return 0;
}