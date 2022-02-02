//handler.h

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnApply(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnNotify(HWND hwnd, WPARAM wParam, LPARAM lParam);

void OnMenuCloseWindow(HWND hwnd);
void OnMenuAddMember(HWND hwnd);
void OnMenuSelectMember(HWND hwnd);
void OnButtonUpdateMember(HWND hwnd);
void OnButtonDeleteMember(HWND hwnd);