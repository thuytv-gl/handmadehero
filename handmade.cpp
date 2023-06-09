#include "handmade.h"

static char running = 1;
static DWORD color = WHITENESS;

LRESULT CALLBACK
MainWindowCallback(
  HWND Window,
  UINT Message,
  WPARAM WParam,
  LPARAM LParam)
{
    LRESULT Result = 0;
    switch(Message)
    {
        case WM_SIZE: 
        {
            OutputDebugStringA("WM_SIZE\n");
        } break;
        case WM_DESTROY: 
        {
            OutputDebugStringA("WM_DESTROY\n");
        } break;
        case WM_CLOSE: 
        {
            running = 0;
            OutputDebugStringA("WM_CLOSE\n");
        } break;
        case WM_ACTIVATEAPP: 
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;
        case WM_PAINT: 
        {
            OutputDebugStringA("WM_PAINT\n");
            PAINTSTRUCT Paint;
            HDC DeviceContext = BeginPaint(Window, &Paint);
            int x = Paint.rcPaint.left;
            int y = Paint.rcPaint.top;
            int w = Paint.rcPaint.right - Paint.rcPaint.left;
            int h = Paint.rcPaint.bottom - Paint.rcPaint.top;
            PatBlt(DeviceContext, x, y, w, h, color);
            EndPaint(Window, &Paint);
            if (color == WHITENESS) {
                color = BLACKNESS;
            }
            else {
                color = WHITENESS;
            }
        } break;
        default:
        {
            Result = DefWindowProc(Window, Message, WParam, LParam);
        } break;
    }

    return(Result);
}

int CALLBACK
WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
    WNDCLASS WindowClass = {};
    WindowClass.style = CS_OWNDC|CS_VREDRAW|CS_HREDRAW;
    WindowClass.lpfnWndProc = MainWindowCallback;
    WindowClass.hInstance = hInstance;
    // WindowClass.hIcon;
    WindowClass.lpszClassName = "HandmadeHeroWindowClass";

    if(RegisterClass(&WindowClass))
    {
        HWND WindowHandle = CreateWindowExA(
                0,
                WindowClass.lpszClassName,
                "Handmade Hero",
                WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                0,
                0,
                hInstance,
                0);
        if (WindowHandle)
        {
            MSG Message;
            while(running) {
                BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
                if (MessageResult > 0)
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                } else break;
            }
        } else {
            // TODO(thuytv): logging
        }

    } else {
        // TODO(thuytv): logging
    }

    return(0);
}
