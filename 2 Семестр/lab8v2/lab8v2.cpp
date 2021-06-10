#include <windows.h> 
#include <time.h>

#define DIVISIONS 10

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
    return LineTo(hdc, x2, y2);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR  szCmdLine, int iCmdShow)
{
    LPCSTR szAppName = "HelloWin";
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = L"HelloWin";
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wndclass);

    hwnd = CreateWindowA(szAppName,
        "Ракета",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Массив, хранящий текущее состояние секции
    static BOOL fState[DIVISIONS][DIVISIONS];
    static int  cxBlock, cyBlock;
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    static HBRUSH hbrush, hbrush1, hbrush2, hbrush3, hbrush4;
    static int  x, y;
    static bool flagtimer;

    switch (iMsg)
    {
    case WM_CREATE:
        srand(time(0));
        x = 500;
        y = 200;
        hdc = GetDC(hwnd);
        return 0;

    case WM_LBUTTONDOWN:
            SetTimer(hwnd, 10, 25, NULL);
            return 0;

    case WM_RBUTTONDOWN:
        KillTimer(hwnd, 10);
        return 0;

    case WM_TIMER:
        y -= 5;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_SIZE:
        cxBlock = LOWORD(lParam) / DIVISIONS;
        cyBlock = HIWORD(lParam) / DIVISIONS;
        return 0;
    case WM_PAINT:
        hbrush = CreateSolidBrush(RGB(0, 64, 0));
        hbrush1 = CreateSolidBrush(RGB(255, 255, 255));
        hbrush2 = CreateSolidBrush(RGB(0, 52, 0));
        hbrush3 = CreateSolidBrush(RGB(255, 100, 0));
        hbrush4 = CreateSolidBrush(RGB(0, 0, 255));

        
        hdc = BeginPaint(hwnd, &ps);

        SelectObject(hdc, hbrush);
        HRGN Rgn2, Rgn3, Rgn4_l, Rgn4_r;
        Rectangle(hdc, x, y, x+100, y+250);
        POINT ptArray1[3], ptArray2[3], ptArray3_l[4], ptArray3_r[4];
        ptArray2[0].x = x; ptArray2[0].y = y;
        ptArray2[1].x = x+50; ptArray2[1].y = y-100;
        ptArray2[2].x = x+100; ptArray2[2].y = y;
        Rgn2 = CreatePolygonRgn(ptArray2, sizeof(ptArray2) / sizeof(POINT), ALTERNATE);
        FillRgn(hdc, Rgn2, hbrush2);
        ptArray1[0].x = x-10; ptArray1[0].y = y+250;
        ptArray1[1].x = x+50; ptArray1[1].y = y+350;
        ptArray1[2].x = x+110; ptArray1[2].y = y+250;
        Rgn3 = CreatePolygonRgn(ptArray1, sizeof(ptArray1) / sizeof(POINT), ALTERNATE);
        FillRgn(hdc, Rgn3, hbrush3);

        ptArray3_l[0].x = x; ptArray3_l[0].y = y+200;
        ptArray3_l[1].x = x-30; ptArray3_l[1].y = y+230;
        ptArray3_l[2].x = x-30; ptArray3_l[2].y = y+300;
        ptArray3_l[3].x = x; ptArray3_l[3].y = y+270;
        Rgn4_l = CreatePolygonRgn(ptArray3_l, sizeof(ptArray3_l) / sizeof(POINT), ALTERNATE);
        FillRgn(hdc, Rgn4_l, hbrush2);

        ptArray3_r[0].x = x+100; ptArray3_r[0].y = y+200;
        ptArray3_r[1].x = x+130; ptArray3_r[1].y = y+230;
        ptArray3_r[2].x = x+130; ptArray3_r[2].y = y+300;
        ptArray3_r[3].x = x+100; ptArray3_r[3].y = y+270;
        Rgn4_r = CreatePolygonRgn(ptArray3_r, sizeof(ptArray3_r) / sizeof(POINT), ALTERNATE);
        FillRgn(hdc, Rgn4_r, hbrush2);

        HRGN Rgn_illume;
        Rgn_illume = CreateEllipticRgn(x+30, y+40, x+70, y+80);
        FillRgn(hdc, Rgn_illume, hbrush4);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
