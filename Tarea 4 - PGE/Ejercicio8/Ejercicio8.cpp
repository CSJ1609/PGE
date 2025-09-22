//Ejercicio 8 - Panel de Mostrador

#include <windows.h>
#include <string>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static std::wstring buffer; // Texto ingresado por el usuario

    switch (msg) {
    case WM_CHAR: {
        wchar_t c = (wchar_t)wParam;

        if (c == 8) { // BACKSPACE
            if (!buffer.empty()) buffer.pop_back();
        }
        else if (c == 13) { // ENTER
            buffer += L"\n";
        }
        else if (c >= 32) { // Cualquier caracter imprimible (espacio incluido)
            buffer += c;
        }

        InvalidateRect(hwnd, NULL, TRUE); // Redibuja ventana
        break;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        RECT rect;
        GetClientRect(hwnd, &rect); // Obtener tamaño actual de la ventana

        if (buffer.empty()) {
            // Mostrar mensaje inicial si no hay texto
            DrawTextW(hdc, L"Panel de mostrador", -1, &rect,
                DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
        else {
            // Mostrar lo que el usuario escribió, adaptado al tamaño
            DrawTextW(hdc, buffer.c_str(), -1, &rect,
                DT_LEFT | DT_TOP | DT_WORDBREAK);
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
    const wchar_t CLASS_NAME[] = L"PanelMostrador";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Panel de Mostrador",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 600, 400,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
