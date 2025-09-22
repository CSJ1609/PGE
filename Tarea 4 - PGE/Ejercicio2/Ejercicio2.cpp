// Ejercicio2.cpp — “Taquilla de cine: Contador de entradas”

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// Identificadores de controles
#define IDC_BTN_VENDER   201
#define IDC_BTN_RESET    202
#define IDC_STATIC_COUNT 203

// Prototipo del procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Variable global del contador
int g_contador = 0;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VentanaCine";

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
        L"Taquilla de Cine \u2013 Contador de Entradas",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
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
    static HWND hStatic;

    switch (msg) {
    case WM_CREATE: {
        // Botón Vender
        CreateWindowW(L"BUTTON", L"Vender entrada",
            WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            30, 30, 150, 30,
            hwnd, (HMENU)IDC_BTN_VENDER, nullptr, nullptr);

        // Botón Resetear
        CreateWindowW(L"BUTTON", L"Reiniciar",
            WS_VISIBLE | WS_CHILD,
            200, 30, 100, 30,
            hwnd, (HMENU)IDC_BTN_RESET, nullptr, nullptr);

        // Texto contador
        hStatic = CreateWindowW(L"STATIC", L"Entradas vendidas: 0",
            WS_VISIBLE | WS_CHILD,
            30, 80, 250, 30,
            hwnd, (HMENU)IDC_STATIC_COUNT, nullptr, nullptr);
        return 0;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == IDC_BTN_VENDER) {
            g_contador++;
        }
        else if (LOWORD(wParam) == IDC_BTN_RESET) {
            g_contador = 0;
        }

        // Actualizar el texto del contador
        wchar_t buffer[100];
        wsprintfW(buffer, L"Entradas vendidas: %d", g_contador);
        SetWindowTextW(hStatic, buffer);

        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

