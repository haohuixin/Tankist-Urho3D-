#pragma once


enum TypeApplication
{
    Type_None,      // Before initialization
    Type_Server,    // Online server
    Type_Client     // Online client
};


class Vehicle;


class Tankist : public Application
{

#pragma warning(push)
#pragma warning(disable:4640)
    URHO3D_OBJECT(Tankist, Application);
#pragma warning(pop)

public:
    Tankist(Context* context);
    
    virtual void Setup();
    virtual void Start();
    virtual void Stop();

    void UpdateMessages();

    void SetPing(float pingMS);
    void SetLoadCPU(float loadCPU);
    void SetNumClients(int numClients);
    void SetBytesInPerSec(float bytesInPerSec);
    void SetBytesOutPerSec(float bytesOutPerSec);
    
private:
    void CreateScene();
    void CreateInstructions();

    void CreateUI();
    void MoveCamera();
    void SetWindowTitleAndIcon();
    void CreateConsoleAndDebugHud();
    bool ParseArguments(Vector<String> &arguments, TypeApplication &type, String &address, unsigned short &port);
    bool GetNumPort(String &str, unsigned short &port);

    void HandleKeyDown(StringHash eventType, VariantMap& eventData);
    void HandleEnterMessageEdit(StringHash eventType, VariantMap& eventData);

    void SubscribeToEvents();

    void HandlePostUpdate(StringHash eventType, VariantMap &eventData);
    void HandlePhysicsPreStep(StringHash eventType, VariantMap &eventData);

    // Client functions
    void ConnectToServer();

    // Server functions
    void HandleNewConnection(StringHash eventType, VariantMap &eventData);
    void HandleCloseConnection(StringHash eventType, VariantMap &eventData);

    Vehicle* CreateVehicle();

    HashMap<Connection*, WeakPtr<Vehicle>> serverObjects;

    Tankist(Tankist const&) : Application(nullptr) {};
    Tankist operator=(Tankist const &) {};

    bool exit = false;

    SharedPtr<Text> chatHistoryText;
    SharedPtr<LineEdit> messageEdit;

    SharedPtr<Text> statisticsWindow;

    float ping = 0.0f;
    float loadCPU = 0.0f;
    int numClients = 0;
    float bytesInPerSec = 0.0f;
    float bytesOutPerSec = 0.0f;

    void UpdateStatisticWindow();
};
