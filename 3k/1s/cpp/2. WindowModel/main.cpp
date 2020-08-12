/**
 * Создать класс InterfaceModel с полями title, text
 * Создать класс WindowModel, дочерний от InterfaceModel.
 * Класс WindowModel должен содержать координаты и размер окна.
 * Реализовать функции перемещения и изменения размеров окна.
 *
 * Подумать о том, какой из подходов предпочтительнее и когда.
 */

#include <iostream>
#include <windows.h>
#include "WindowModel.cpp"

using namespace std;

bool commandExecute(int, WindowModel &model);

void viewHelpCommand();

int main(int argc, char **argv) {
    WindowModel *model = new WindowModel();
    int cmd = -1;
    bool cmdReplay = true;

    char title[256] = "My Window Title";
    model->setTitle(title);

    cout << "\n \n 0. Exit \n 1. Set Title \n 2. Set Text\n 3. Get Current Size \n 4. Set Size \n";
    cout << " 5. Move Aside Window \n 6. Increase the size by a quarter \n 7. Get Current Title \n 8. Set Title (Method 2) \n";
    cout << " 9. Carousel \n 10. Up Window \n 11. Down Window \n 12. Move To Corner \n 13. Get current Point \n 14. Move to Center \n";

    while (cmdReplay) {
        cout << "\n\n -> command: ";
        cin >> cmd;

        if (cmd >= 0) {
            cmdReplay = commandExecute(cmd, *model);
        }
    }

    cout << "\n";

    return 0;
}

bool commandExecute(int command, WindowModel &model) {
    char title[256];
    char text[1024];

    int height, width, px;
    int corner;

    int x, y;

    switch (command) {
        case 0:
            return false;

        case 1:
            cout << "\nNew Title: \n -> ";
            cin >> title;

            model.setTitle(title);

            break;

        case 2:
            cout << "\nNew Text: \n -> ";
            cin >> text;

            model.setText(text);

            break;

        case 3:
            model.refresh();

            cout << "Current height: " << model.getHeight() << endl;
            cout << "Current width: " << model.getWidth() << endl;

            break;

        case 4:
            cout << "New height: \n -> ";
            cin >> height;

            cout << "New width: \n -> ";
            cin >> width;

            if (height >= 50 && width >= 50) {
                model.setSize(height, width);
            } else {
                cout << "Error";
            }

            break;

        case 5:
            cout << "Side: \n 1. Left \n 2. Right \n";
            int side;

            cout << "-> ";
            cin >> side;
            cout << "Pixels: \n -> ";
            cin >> px;

            model.moveToSideByPx(side, px);

            break;

        case 6:
            model.incSizeQuart();
            break;

        case 7:
            cout << "Current title: " << model.getTitle();
            break;

        case 8:
            cout << "\nNew Title: \n -> ";
            cin >> title;

            model.setTitle2(title);

            break;

        case 9:
            int count;
            cout << "\nCount circle \n -> ";
            cin >> count;

            height = model.getHeight();
            width = model.getWidth();
            model.getCurrentPoint(x, y);

            for (int i = 0; i < count; ++i) {
                model.carousel();
                Sleep(40);
            }

            model.setPoints(x, y);
            model.setSize(height, width);

            break;

        case 10:
            cout << "Pixels: \n -> ";
            cin >> px;

            model.up(px);

            break;

        case 11:
            cout << "Pixels: \n -> ";
            cin >> px;

            model.down(px);

            break;

        case 12:
            cout << "Corners: \n" << "1. Upper left\n" << "2. Upper right\n" << "3. Bottom left\n";
            cout << "4. Bottom right\n"  <<" -> ";
            cin >> corner;

            if (corner == 2) {
                model.moveToUpperRightCorner();
            } else if (corner == 3) {
                model.moveToBottomLeftCorner();
            } else if(corner == 4) {
                model.moveToBottomRightCorner();
            } else {
                model.moveToUpperLeftCorner();
            }

            break;

        case 13:
            model.getCurrentPoint(x, y);

            cout << "x = " << x << "\ny = " << y;

            break;

        case 14:
            model.moveToCenter();

            break;

        default:
            cout << "This command is not found";
            break;
    }

    return true;
}
