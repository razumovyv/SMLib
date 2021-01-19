//--------------------------- File MainWin32.cpp ------------------------------

//-----------------------------------------------------------------------------
// Include the base config file with platform detection
//-----------------------------------------------------------------------------
#include <SMLib/Config.h>

//-----------------------------------------------------------------------------
// Define the WinMain entry point
//-----------------------------------------------------------------------------
#ifdef SML_WINDOWS_SYSTEM

#include <windows.h>

extern int main(int argc, char* argv[]);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
    return main(__argc, __argv);
}

#endif // !SML_WINDOWS_SYSTEM

//------------------------ End of file MainWin32.cpp --------------------------