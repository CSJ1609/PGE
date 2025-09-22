// Ejercicio3.cpp — “Portal de noticias: Diseño responsive”

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// Identificadores de controles
#define IDC_STATIC_TITLE  301
#define IDC_EDIT_NEWS     302
#define IDC_BTN_REFRESH   303

// Prototipo del procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VentanaNoticias";

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
        L"Portal de Noticias \u2013 Dise\u00F1o Responsive",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 400,
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
    static HWND hTitle, hNews, hBtn;

    switch (msg) {
    case WM_CREATE: {
        // Título
        hTitle = CreateWindowW(L"STATIC", L"\u00DAltimas Noticias",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            10, 10, 560, 30,
            hwnd, (HMENU)IDC_STATIC_TITLE, nullptr, nullptr);

        // Área de noticias (multilínea)
        hNews = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT",
            L"Aqu\u00ED aparecer\u00E1n las noticias...",
            WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | WS_VSCROLL,
            10, 50, 560, 250,
            hwnd, (HMENU)IDC_EDIT_NEWS, nullptr, nullptr);

        // Botón
        hBtn = CreateWindowW(L"BUTTON", L"Refrescar",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            10, 310, 100, 30,
            hwnd, (HMENU)IDC_BTN_REFRESH, nullptr, nullptr);
        return 0;
    }
    case WM_SIZE: {
        int width = LOWORD(lParam);  // nuevo ancho de la ventana
        int height = HIWORD(lParam);  // nueva altura

        // Ajustar tamaño de controles en función del tamaño de ventana
        MoveWindow(hTitle, 10, 10, width - 20, 30, TRUE);
        MoveWindow(hNews, 10, 50, width - 20, height - 120, TRUE);
        MoveWindow(hBtn, width - 120, height - 60, 100, 30, TRUE);

        return 0;
    }
    case WM_COMMAND: {
        if (LOWORD(wParam) == IDC_BTN_REFRESH) {
            SetWindowTextW(hNews, L"Noticias refrescadas:\r\n- Evento A\r\n- Evento B\r\n- Evento C");
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

