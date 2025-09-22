// Ejercicio6.cpp — “Caja registradora: Sólo números”

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// Identificadores de controles
#define IDC_EDIT_INPUT  601
#define IDC_STATIC_INFO 602

// Prototipo del procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Handler original del EDIT (para subclasificar)
WNDPROC g_OldEditProc;

LRESULT CALLBACK EditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CHAR: {
        // Solo permitimos dígitos y retroceso
        if ((wParam >= L'0' && wParam <= L'9') ||
            wParam == VK_BACK ||
            wParam == L'\u002D') { // signo menos "-"
            return CallWindowProcW(g_OldEditProc, hwnd, msg, wParam, lParam);
        }
        else {
            // Beep para indicar inválido
            MessageBeep(MB_ICONWARNING);
            return 0; // bloquear entrada
        }
    }
    }
    return CallWindowProcW(g_OldEditProc, hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VentanaCaja";

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
        L"Caja registradora \u2013 S\u00F3lo n\u00FAmeros", // "Sólo números"
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
    static HWND hEdit, hStatic;

    switch (msg) {
    case WM_CREATE: {
        // Texto explicativo con acentos/ñ
        hStatic = CreateWindowW(L"STATIC",
            L"Ingrese el n\u00FAmero de producto (s\u00F3lo d\u00EDgitos y -):",
            WS_VISIBLE | WS_CHILD,
            20, 20, 340, 20,
            hwnd, (HMENU)IDC_STATIC_INFO, nullptr, nullptr);

        // Caja de entrada
        hEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
            20, 50, 200, 25,
            hwnd, (HMENU)IDC_EDIT_INPUT, nullptr, nullptr);

        // Subclasificar el EDIT para filtrar la entrada
        g_OldEditProc = (WNDPROC)SetWindowLongPtrW(hEdit, GWLP_WNDPROC, (LONG_PTR)EditProc);

        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

