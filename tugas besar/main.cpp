#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogProcedure (HWND, UINT, WPARAM, LPARAM);
// fungsi untuk meregister windows dialog
void registerwindow(HINSTANCE, WNDCLASSEX);

//menambahkan variable global (2)
TCHAR ClassName1[]="window1";
TCHAR ClassName2[]="window2"; //window class name (3)
HWND hwnd,dlg; //(4) membuat handler global (supaya bisa berhubungan antar keduanya
HINSTANCE hInstance; //(5) variable untuk membuat windows baru

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

    //pemilihan jenis kelamin
    const wchar_t *gender[]= {L"Pria",L"Wanita"};
    //pemilihan vaksi
    const wchar_t *vaksin[]={L"1",L"2"};

    //Membuat variable global
    HINSTANCE g_combo;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Login"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           450,                 /* The programs width */
           400,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


// windows isian
//menambahkan fungsi untuk mengcreate dialog
void registerwindow(HINSTANCE hThisInstance,WNDCLASSEX dialog){
    dialog.hInstance = hThisInstance;
    dialog.lpszClassName = ClassName2;
    dialog.lpfnWndProc = DialogProcedure; //untuk memanggil perintah fungsi callback prosedure
    dialog.style=CS_DBLCLKS;
    dialog.cbSize=sizeof(WNDCLASSEX);
    dialog.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    dialog.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
    dialog.hCursor=LoadCursor(NULL,IDC_CROSS);
    dialog.lpszMenuName=NULL;
    dialog.cbClsExtra=0;
    dialog.cbWndExtra=0;
    dialog.hbrBackground=(HBRUSH)COLOR_BACKGROUND;

    RegisterClassEx(&dialog);
}

/*  This function is called by the Windows function DispatchMessage()  */
     HWND username_text,password_text;
     HRGN hRgn1;
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            //Title
            //CreateWindow(TEXT("static"),TEXT("Data Pasien Pra Vaksinasi"),WS_VISIBLE|WS_CHILD,358,42,284,28,hwnd,NULL,NULL,NULL);

            //text_box login
            username_text=CreateWindow(TEXT("edit"),TEXT("Username"),WS_VISIBLE|WS_CHILD|WS_BORDER,125,158,199,27,hwnd,NULL,NULL,NULL);
            password_text=CreateWindow(TEXT("edit"),TEXT("Password"),WS_VISIBLE|WS_CHILD|WS_BORDER,125,190,199,27,hwnd,NULL,NULL,NULL);

            //tombol button add data pribadi
            CreateWindow(TEXT("button"),TEXT("Login"),WS_VISIBLE|WS_CHILD|WS_BORDER,135,220,57,27,hwnd,(HMENU) 1,NULL,NULL);
            //tombol button add data kesehatan
            CreateWindow(TEXT("button"),TEXT("Help"),WS_VISIBLE|WS_CHILD|WS_BORDER,257,220,52,27,hwnd,(HMENU) 2,NULL,NULL);
            break;
        case WM_COMMAND:
            switch(message){
                case 1:
//                if(username_text == "admin" && password_text=="admin"){
                    dlg = CreateWindowEx(0,ClassName2,"Data Kesehatan",WS_OVERLAPPEDWINDOW,0,0,1000,550,hwnd,NULL,hInstance,NULL);
                    ShowWindow(dlg,1);
                    EnableWindow(hwnd,false);
                     break;
                }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

/* This function is called by the Windows function DispatchMessage() */
     HWND nama_text,nik_text,gender_text,usia_text,alamat_text,tensi_text,denyut_text,suhu_text,vaksin_text,datatampil;
     //HWND pilihGender, pilihVaksin;
//menambahkan fungsi callback function
LRESULT CALLBACK DialogProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){
            case WM_CREATE:
            //Title
            CreateWindow(TEXT("static"),TEXT("Data Pasien Pra Vaksinasi"),WS_VISIBLE|WS_CHILD,358,42,284,28,hwnd,NULL,NULL,NULL);
            //Data Pasien
            CreateWindow(TEXT("static"),TEXT("Data Pribadi"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,96,122,112,28,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Nama  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,31,164,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("NIK   :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,31,205,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Gender   :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,31,246,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Usia  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,31,287,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Alamat  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,31,328,76,22,hwnd,NULL,NULL,NULL);

            //Data Kesehatan
            CreateWindow(TEXT("static"),TEXT("Data Kesehatan"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,572,122,146,24,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Tensi  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,323,164,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Denyut  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,323,219,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Suhu  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,702,164,76,22,hwnd,NULL,NULL,NULL);
            CreateWindow(TEXT("static"),TEXT("Vaksin  :"),WS_VISIBLE|WS_CHILD|WS_BORDER|WS_ACTIVECAPTION,702,219,76,22,hwnd,NULL,NULL,NULL);

            //text_box data pribadi
            nama_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,153,161,103,27,hwnd,NULL,NULL,NULL);
            nik_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,153,202,103,27,hwnd,NULL,NULL,NULL);
            //gender_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,153,243,103,27,hwnd,NULL,NULL,NULL);
            usia_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,153,284,103,27,hwnd,NULL,NULL,NULL);
            alamat_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,153,325,103,27,hwnd,NULL,NULL,NULL);
            //combo box gender_combo
            gender_text=CreateWindowW(L"Combobox",NULL,WS_CHILD|WS_VISIBLE|CBS_DROPDOWN,153,243,103,27,hwnd,NULL,g_combo,NULL);

            //text_box data kesehatan
            tensi_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,445,161,103,27,hwnd,NULL,NULL,NULL);
            denyut_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,445,216,103,27,hwnd,NULL,NULL,NULL);
            suhu_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,824,161,103,27,hwnd,NULL,NULL,NULL);
            //vaksin_text=CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_BORDER,824,216,103,27,hwnd,NULL,NULL,NULL);
            vaksin_text=CreateWindowW(L"Combobox",NULL,WS_CHILD|WS_VISIBLE|CBS_DROPDOWN,824,216,103,27,hwnd,NULL,g_combo,NULL);

            //tombol button add data pribadi
            CreateWindow(TEXT("button"),TEXT("Add Data"),WS_VISIBLE|WS_CHILD|WS_BORDER,113,386,78,27,hwnd,(HMENU) 1,NULL,NULL);
            //tombol button add data kesehatan
            CreateWindow(TEXT("button"),TEXT("Add Data"),WS_VISIBLE|WS_CHILD|WS_BORDER,606,246,78,27,hwnd,(HMENU) 2,NULL,NULL);

            //tombol save,edit,delete
            CreateWindow(TEXT("button"),TEXT("SAVE"),WS_VISIBLE|WS_CHILD|WS_BORDER,385,474,56,27,hwnd,(HMENU) 3,NULL,NULL);
            CreateWindow(TEXT("button"),TEXT("EDIT"),WS_VISIBLE|WS_CHILD|WS_BORDER,601,474,54,27,hwnd,(HMENU) 4,NULL,NULL);
            CreateWindow(TEXT("button"),TEXT("DELETE"),WS_VISIBLE|WS_CHILD|WS_BORDER,824,474,75,27,hwnd,(HMENU) 5,NULL,NULL);

            //tombol logout
            CreateWindow(TEXT("button"),TEXT("Logout"),WS_VISIBLE|WS_CHILD|WS_BORDER,178,421,78,27,hwnd,(HMENU) 6,NULL,NULL);

            //kotak untuk menampilkan data
            datatampil= CreateWindow(TEXT("edit"),TEXT(""),WS_VISIBLE|WS_CHILD|WS_VSCROLL|WS_HSCROLL|ES_MULTILINE|WS_BORDER,
                               307,304,642,149,hwnd,NULL,NULL,NULL);
           // hRgn1 = CreateRectRgn( 22, 106,  250, 347);
            break;

            //menampilkan combo
            for (int i = 0; i < 2; i++ ) {
            SendMessage(gender_text, CB_ADDSTRING, 0, (LPARAM)
            gender[i]);}
            break;
    //case WM_CREATE:
       // CreateWindow(TEXT("button"),TEXT("close dialog"),WS_VISIBLE|WS_CHILD|WS_BORDER,90,70,100,20,hwnd,(HMENU) 1,NULL,NULL);
        //break;
    case WM_COMMAND:
        switch (message){
        case 6:
       // hwnd = CreateWindowEx(0,ClassName1,"Dialog Windows App",WS_OVERLAPPEDWINDOW,50,50,300,500,dlg,NULL,hInstance,NULL);
        //CloseWindow(dlg);
        EnableWindow(hwnd,true);
        DestroyWindow(hwnd);
        break;
    }
    case WM_CLOSE :
        EnableWindow(hwnd,true);
        DestroyWindow(hwnd);
        break;
        default:
        return DefWindowProc(hwnd, message, wParam, lParam);

    /*case WM_DESTROY:
        CloseWindow(dlg);
        DestroyWindow(hwnd);
        //EnableWindow(hwnd,true);
        ShowWindow(hwnd,1);
        break;
        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
        //break;
        //default:                      /* for messages that we don't deal with */
        //return DefWindowProc (hwnd, message, wParam, lParam);
    }
}


