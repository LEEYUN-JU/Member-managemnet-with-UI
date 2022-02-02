//std.h

#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")
#include <vector>
using namespace std;

#define WM_APPLY WM_USER+100

#include "resource.h"
#include "controlinfo.h"
#include "handler.h"
#include "member.h"
#include "ui.h"
#include "newmemberproc.h"
#include "selectmemberproc.h"