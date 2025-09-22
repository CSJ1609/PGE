// Ejercicio1.cpp — “Recepción de hotel: Ficha de check-in”

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN
#pragma execution_character_set("utf-8") // no hace daño; los escapes evitan mojibake

#include <windows.h>
#include <string>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

//Identificadores de controles
#define IDC_EDIT_NOMBRE 101
#define IDC_EDIT_APELLIDO 102
#define IDC_EDIT_HAB 103
#define IDC_BTN_CHECKIN 104

//Prototipo del procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VentanaCheckIn";

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
        L"Recepci\u00F3n de Hotel \u2013 Ficha de Check-in",
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
    switch (msg) {
    case WM_CREATE: {
        // Etiquetas
        CreateWindowW(L"STATIC", L"Nombre:", WS_VISIBLE | WS_CHILD,
            20, 20, 80, 20, hwnd, nullptr, nullptr, nullptr);
        CreateWindowW(L"STATIC", L"Apellido:", WS_VISIBLE | WS_CHILD,
            20, 60, 80, 20, hwnd, nullptr, nullptr, nullptr);
        CreateWindowW(L"STATIC", L"Habitaci\u00F3n:", WS_VISIBLE | WS_CHILD,
            20, 100, 80, 20, hwnd, nullptr, nullptr, nullptr);

        // Cuadros de texto
        CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
            120, 20, 200, 20,
            hwnd, (HMENU)IDC_EDIT_NOMBRE, nullptr, nullptr);

        CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
            120, 60, 200, 20,
            hwnd, (HMENU)IDC_EDIT_APELLIDO, nullptr, nullptr);

        CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL,
            120, 100, 200, 20,
            hwnd, (HMENU)IDC_EDIT_HAB, nullptr, nullptr);

        // Botón
        CreateWindowW(L"BUTTON", L"Check-in",
            WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            120, 150, 100, 30,
            hwnd, (HMENU)IDC_BTN_CHECKIN, nullptr, nullptr);
        return 0;
    }

    case WM_COMMAND: {
        if (LOWORD(wParam) == IDC_BTN_CHECKIN) {
            // Obtener textos de los cuadros
            wchar_t nombre[100], apellido[100], habitacion[100];
            GetWindowTextW(GetDlgItem(hwnd, IDC_EDIT_NOMBRE), nombre, 100);
            GetWindowTextW(GetDlgItem(hwnd, IDC_EDIT_APELLIDO), apellido, 100);
            GetWindowTextW(GetDlgItem(hwnd, IDC_EDIT_HAB), habitacion, 100);

            std::wstring mensaje = L"Check-in realizado:\n";
            mensaje += L"Nombre: " + std::wstring(nombre) + L"\n";
            mensaje += L"Apellido: " + std::wstring(apellido) + L"\n";
            mensaje += L"Habitaci\u00F3n: " + std::wstring(habitacion);

            MessageBoxW(hwnd, mensaje.c_str(), L"Confirmaci\u00F3n", MB_OK | MB_ICONINFORMATION);
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

