// Ejercicio5.cpp — “Panel de ascensor: Último piso solicitado”

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// Identificadores base de botones
#define IDC_BTN_FLOOR1  501
#define IDC_BTN_FLOOR2  502
#define IDC_BTN_FLOOR3  503
#define IDC_BTN_FLOOR4  504
#define IDC_STATIC_INFO 510

// Prototipo del procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Variable global: último piso
int g_ultimoPiso = -1;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VentanaAscensor";

    WNDCLASSEXW wc{};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;
    wc.hIconSm = wc.hIcon;

    RegisterClassExW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Panel de Ascensor \u2013 \u00DAltimo piso solicitado",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 250,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hInfo;

    switch (msg) {
    case WM_CREATE: {
        // Crear botones de pisos
        CreateWindowW(L"BUTTON", L"Piso 1",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            50, 30, 80, 30,
            hwnd, (HMENU)IDC_BTN_FLOOR1, nullptr, nullptr);

        CreateWindowW(L"BUTTON", L"Piso 2",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            150, 30, 80, 30,
            hwnd, (HMENU)IDC_BTN_FLOOR2, nullptr, nullptr);

        CreateWindowW(L"BUTTON", L"Piso 3",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            50, 80, 80, 30,
            hwnd, (HMENU)IDC_BTN_FLOOR3, nullptr, nullptr);

        CreateWindowW(L"BUTTON", L"Piso 4",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            150, 80, 80, 30,
            hwnd, (HMENU)IDC_BTN_FLOOR4, nullptr, nullptr);

        // Etiqueta de información
        hInfo = CreateWindowW(L"STATIC", L"\u00DAltimo piso solicitado: (ninguno)",
            WS_VISIBLE | WS_CHILD,
            50, 140, 250, 30,
            hwnd, (HMENU)IDC_STATIC_INFO, nullptr, nullptr);
        return 0;
    }
    case WM_COMMAND: {
        int id = LOWORD(wParam);
        if (id >= IDC_BTN_FLOOR1 && id <= IDC_BTN_FLOOR4) {
            g_ultimoPiso = id - IDC_BTN_FLOOR1 + 1; // Piso 1..4

            wchar_t buffer[100];
            wsprintfW(buffer, L"\u00DAltimo piso solicitado: %d", g_ultimoPiso);
            SetWindowTextW(hInfo, buffer);
        }
        return 0;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        if (g_ultimoPiso != -1) {
            std::wstring texto = L"(Confirmaci\u00F3n en WM_PAINT) Piso ";
            texto += std::to_wstring(g_ultimoPiso);
            TextOutW(hdc, 50, 180, texto.c_str(), (int)texto.size());
        }

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

