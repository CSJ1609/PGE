//Ejercicio 7 - Zona de Pruebas

#include <windows.h>
#include <string>
#include <vector>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static std::vector<std::wstring> eventos; // lista de eventos a mostrar

    switch (msg) {
    case WM_CHAR: {
        wchar_t c = (wchar_t)wParam;
        std::wstring texto = L"Tecla: ";
        texto += c;
        eventos.push_back(texto);
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    }
    case WM_LBUTTONDOWN:
        eventos.push_back(L"Click izquierdo en la ventana");
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_SIZE:
        eventos.push_back(L"Ventana redimensionada");
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        int y = 10;
        for (auto& e : eventos) {
            TextOutW(hdc, 10, y, e.c_str(), e.size());
            y += 20;
        }
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"ZonaPruebas";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Zona de Pruebas",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

