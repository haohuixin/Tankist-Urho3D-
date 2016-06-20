#pragma once


class WindowGameESC : public Object
{
#pragma warning(push)
#pragma warning(disable:4640)
    URHO3D_OBJECT(WindowGameESC, Object)
#pragma warning(pop)


public:
    WindowGameESC(Context *context);

    void Hide();
    void Show();

private:
    WindowGameESC(WindowGameESC const&) : Object(nullptr) {};
    WindowGameESC operator=(WindowGameESC const&) {};

    SharedPtr<UIElement> window;

    void HandleButtonExit(StringHash, VariantMap&);
    void HandleButtonOptions(StringHash, VariantMap&);
    void HandleButtonLanguage(StringHash, VariantMap&);
    void HandleLanguageChanged(StringHash, VariantMap&);
};
