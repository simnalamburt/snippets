// x86_64-w64-mingw32-gcc -mwindows win32.c

// Reference:
//   https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types
#define WINAPI __stdcall
typedef void *HWND;
typedef void *HINSTANCE;
typedef char *PSTR;
typedef const char *LPCSTR;
typedef unsigned int UINT;
typedef unsigned long DWORD;

extern int WINAPI MessageBoxA(HWND, LPCSTR, LPCSTR, UINT);
extern void WINAPI Sleep(DWORD);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {
  MessageBoxA(0, "title", "body", 0);
  Sleep(1000);
  MessageBoxA(0, "title", "body", 0);
  return 0;
}
