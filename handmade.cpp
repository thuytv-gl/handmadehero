#include "handmade.h"

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd
) {
    MessageBoxA(0, "Hello handmade hero", "Handmade Hero",
            MB_OK|MB_ICONINFORMATION);
    return(0);
}
