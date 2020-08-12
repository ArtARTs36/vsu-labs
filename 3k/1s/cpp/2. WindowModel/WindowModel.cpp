#include <windows.h>
#include "InterfaceModel.cpp"

class WindowModel : public InterfaceModel {
private:
    // Здесь храним точку расположения по горизонтали
    long int pointX;

    // по вертикали
    long int pointY;

    // Ширина
    int width;

    // Высота
    int height;

    // Ширина экрана
    int desktopWidth;

    // Высота экрана
    int desktopHeight;

    /**
     * Узнаем текущее расположение, координаты
     */
    void findCurrentPoint() {
        HWND hWndParent = GetParent(myHWND);
        POINT p = {0, 0};

        MapWindowPoints(myHWND, hWndParent, &p, 1);

        pointX = p.x;
        pointY = p.y;

        //move();
    }

    /**
     * Узнаем разрешение экрана
     */
    void findDesktopResolution() {
        RECT coordDesktop;

        HWND desktop = GetDesktopWindow();

        GetWindowRect(desktop, &coordDesktop);

        desktopWidth = coordDesktop.right;
        desktopHeight = coordDesktop.bottom;
    }

    /**
     * Узнаем текущий размер
     */
    void findCurrentSize() {
        RECT rc;
        GetWindowRect(myHWND, &rc);
        width = rc.right - rc.top;
        height = rc.bottom - rc.left;
//
//        cout << rc.left << " " << rc.right << " " << rc.top << " " << rc.bottom;
    }

    /**
     * Перемещение по текущим координатам
     */
    void move() {
        MoveWindow(myHWND, pointX, pointY, width, height, true);
    }

public:
    WindowModel() {
        findDesktopResolution();
        refresh();
    }

    void refresh() {
        findCurrentSize();
        findCurrentPoint();
    }

    /**
     * Переместить в сторону
     *
     * side:
     *  1 - влево
     *  2 - вправо
     */
    void moveToSideByPx(int side, int px) {
        pointX = (side == 1) ? pointX - px : pointX + px;

        move();
    }

    /**
     * Увеличить размер на четверть
     */
    void incSizeQuart() {
        setSize(height * 1.25, width * 1.25);
    }

    /**
     * Установить размер
     *
     * @param newHeight
     * @param newWidth
     */
    void setSize(int newHeight, int newWidth) {
        height = newHeight;
        width = newWidth;

        move();
    }

    /**
     * Делаем карусель:
     *  Отправляем окно в левый верхний угол и пускаем по кругу))
     */
    void carousel() {
//        height = 150;
//        width = 150;
        height = desktopHeight / 9;
        width = desktopWidth / 9;
        moveToUpperLeftCorner();

        for (int i = 0; i < 8; ++i) {
            Sleep(150);
            moveToSideByPx(2, width);
        }

        for (int i = 0; i < 8; ++i) {
            Sleep(150);
            down(height);
        }

        for (int i = 0; i < 8; ++i) {
            Sleep(150);
            moveToSideByPx(1, width);
        }

        findCurrentPoint();

        for (int i = 0; i < 8; ++i) {
            Sleep(150);
            up(height);
        }
    }

    /**
     * Опустить окно
     *
     * @param px
     */
    void down(int px) {
        pointY += px;
        move();
    }

    /**
     * Поднять окно
     *
     * @param px
     */
    void up(int px) {
        pointY -= px;
        Sleep(10);
        move();
    }

    /**
     * Переместить в левый верхний угол
     */
    void moveToUpperLeftCorner() {
        pointX = 0;
        pointY = 0;

        move();
    }

    /**
    * Переместить в правый верхний угол
    */
    void moveToUpperRightCorner() {
        pointX = desktopWidth - width;
        pointY = 0;

        move();
    }

    /**
    * Переместить в левый нижний угол
    */
    void moveToBottomLeftCorner() {
        pointX = 0;
        pointY = desktopHeight - height;

        move();
    }

    /**
    * Переместить в правый нижний угол
    */
    void moveToBottomRightCorner() {
        pointX = desktopWidth - width;
        pointY = desktopHeight - height;

        move();
    }

    void getCurrentPoint(int &x, int &y) {
        x = pointX;
        y = pointY;
    }

    void setPoints(int x, int y){
        pointX = x;
        pointY = y;

        move();
    }

    /**
     * Перемещение окна в центр
     *  Мысленно делим экран на 4 части
     */
    void moveToCenter()
    {
        pointX = (desktopWidth / 2) - (width / 2);
        pointY = (desktopHeight / 2) - (height / 2);

        move();
    }

    int getHeight() {
        return height;
    }

    int getWidth() {
        return width;
    }
};
