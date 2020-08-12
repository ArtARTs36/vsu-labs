#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class InterfaceModel {
protected:
    HWND myHWND;
private:
    char title[256];

    char *text;

public:

    InterfaceModel() {
        myHWND = GetConsoleWindow();
        GetConsoleTitle(title, 256);
    }

    char *getTitle() {
        return title;
    }

    void setTitle(char *newTitle) {
        SetConsoleTitle(newTitle);

        /**
         * Не делаю title = newTitle
         * Потому что что-то может обрезаться при установке title в консоль
         * Поэтому заберу title прямо из консоли
         */
        GetConsoleTitle(title, 256);
    }

    void setTitle2(char *newTitle) {
        SetWindowText(myHWND, newTitle);

        GetWindowText(myHWND, title, 256);
    }

    void setText(char *newText) {
        system("cls");

        text = new char[strlen(newText) + 1];
        strcpy(text, newText);

        cout << text;
    }
};

