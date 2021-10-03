#include <windows.h>
#include <iostream>

using namespace std;

//The class name of the border (The only unique thing to identify this dumb red border)
const wstring className = L"ScreenBorderWindow";

//Forward decleration
BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lParam);

int main()
{
    wcout << "MS Teams Red Border Remover by N00ree\n";
    //Enumerate through all windows
    EnumWindows(enumWindowCallback, NULL);
    wcout << "Red border not found :(" << endl;
    system("pause");
}

BOOL CALLBACK enumWindowCallback(HWND hWnd, LPARAM lParam) {

    //Get class name
    WCHAR* buffer = new WCHAR[19];
    GetClassName(hWnd, buffer, 19);
    wstring hwndClassName = buffer;

    //Compare classname
    if (hwndClassName == className) {
       
        //Remove border and exit
        SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
        BOOL ret = SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, LWA_ALPHA | LWA_COLORKEY);
        if (ret != FALSE) {
            wcout << "Successfully removed border :)" << endl;
        }

        delete[] buffer;
        system("pause");
        exit(0);
    }

    delete[] buffer;
    return TRUE;
}
