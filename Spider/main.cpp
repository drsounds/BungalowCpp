	// .cpp : Defines the entry point for the application.
//

#include <Windows.h>
#include "libspider.h"
#include "SpiderWin32WindowElement.h"
#include "Resource.h"

#define MAX_LOADSTRING 100



using namespace spider;
// Global Variables:

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

HINSTANCE hInst;								// current instance
	TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name


	
	
Win32WindowElement *window  = new Win32WindowElement();




int APIENTRY WinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SPIDER, szWindowClass, MAX_LOADSTRING);
	window->MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!window->InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SPIDER));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM Win32WindowElement::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SPIDER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SPIDER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

void sample_click(spider::Element *elm, void *data) {
	MessageBox(((Win32WindowElement *)elm->getWindowNode())->getHandle(), L"Test", (LPCWSTR)"A", 0);
}

void Win32WindowElement::SampleLayout() {
	/*spider::HBoxElement *header = new spider::HBoxElement();
	header->set("bgcolor", "#888888");
	header->set("height", "56");
	header->getPadding()->top = 3;
	header->getPadding()->left = 3;
	header->getPadding()->bottom = 3;
	header->getPadding()->right =  3;
	this->appendChild(header);
	
	

	
	// Add header children
	
	spider::HBoxElement *body = new spider::HBoxElement();
	body->set("bgcolor", "#474747");
	body->set("flex", "1");
	body->set("height", "100");
	this->appendChild(body);

		// Inside body
	spider::VBoxElement *sidebar = new spider::VBoxElement();
	sidebar->set("width", "220");
	sidebar->set("bgcolor", "#373737");
	body->appendChild(sidebar);

	// 

	spider::HBoxElement *footer = new spider::HBoxElement();
	footer->set("bgcolor", "#444444");
	footer->set("height", "56");
	this->appendChild(footer);
	// Add header buttons
	spider::Element *btn1 = new spider::ButtonElement();
	btn1->setWidth(128);
	btn1->setId(new string("id"));
	btn1->addEventListener(new string("click"), (spider::s_event)sample_click);
	header->appendChild(btn1);
	btn1 = new spider::HBoxElement();
	btn1->set("height", "56");
	btn1->set("flex", "1");
	btn1->set("bgcolor", "#111111");
	btn1->setId(new string("id"));
	btn1->addEventListener(new string("click"), (spider::s_event)sample_click);
	header->appendChild(btn1);
	this->pack();
	btn1 = new spider::ButtonElement();
	btn1->set("width", "56");
	btn1->setId(new string("id"));
	btn1->addEventListener(new string("click"), (spider::s_event)sample_click);
	header->appendChild(btn1);
	this->pack();*/

}




//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL Win32WindowElement::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
   
	this->hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   
	this->hWnd = hWnd;
	this->SampleLayout();
   // Add sample elements
	

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	winspider::Win32GraphicsContext *gc2;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT clientRect;
	HDC memDC ;
	HBITMAP btp ;
	HGDIOBJ t ;
	HGDIOBJ f;
	int iPosX, iPosY;
	switch (message)
	{
	case WM_SIZE:
		window->pack();
		GetClientRect(hWnd,&clientRect);
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		btp = CreateCompatibleBitmap(hdc, clientRect.right, clientRect.bottom);
		t = SelectObject(memDC, btp);
		gc2 = new winspider::Win32GraphicsContext(memDC);
		
		
		window->Draw(gc2);
		f = SelectObject(hdc, btp);
		
		BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, memDC, 0, 0, SRCCOPY);
		// TODO: Add any drawing code here...
		ReleaseDC(hWnd, memDC);
		EndPaint(hWnd, &ps);
	case WM_LBUTTONDOWN:
		iPosX = LOWORD(lParam);
		iPosY = HIWORD(lParam);
		window->click(0, iPosX, iPosY);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		GetClientRect(hWnd,&clientRect);
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		btp = CreateCompatibleBitmap(hdc, clientRect.right, clientRect.bottom);
		t = SelectObject(memDC, btp);
		gc2 = new winspider::Win32GraphicsContext(memDC);
		
		
		window->Draw(gc2);
		f = SelectObject(hdc, btp);
		
		BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, memDC, 0, 0, SRCCOPY);
		// TODO: Add any drawing code here...
		ReleaseDC(hWnd, memDC);
		EndPaint(hWnd, &ps);
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
