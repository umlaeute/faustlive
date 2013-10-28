//
//  HTTPWindow.h
//  
//
//  Created by Sarah Denoux on 13/05/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

// HTTPWindow creates a QrCode which correspond to an httpd interface of your faust application so that you can control it within distance. 

#ifndef _HTTPWindow_h
#define _HTTPWindow_h

#include <string>
#include <QMainWindow>
#include <QObject>
#include <QPixmap>
#include <QString>

#include "faust/audio/dsp.h"

class httpdUI;

using namespace std;

class HTTPWindow : public QMainWindow{
    
    Q_OBJECT
    
    private : 
    
    string      fIPaddress;
    string      fEntireAddress;
    char*       fTitle;
    httpdUI*    fInterface; //Httpd interface for distance control
    QPixmap     fQrCode;
    bool        fShortcut;
    
    public : 
    
    //------------------------HTTPD WINDOW ACTIONS
    
    HTTPWindow();
    
    ~HTTPWindow();
    
    void        displayQRCode(char* url);
    
    void        frontShow_Httpd(string windowTitle);
    
    void        display_HttpdWindow(int x, int y);
    
    bool        is_httpdWindow_active();
    
    void        hide_httpdWindow();

    void        search_IPadress();
    string&     getUrl();
    
    bool        build_httpdInterface(char* error, string windowTitle, dsp* current_DSP, int port);
    
    void        launch_httpdInterface();
    
    void        toPNG();
    
    virtual void contextMenuEvent(QContextMenuEvent* ev);
    
    void        keyPressEvent(QKeyEvent* event);
    void        keyReleaseEvent(QKeyEvent* event);
    void        closeEvent(QCloseEvent* event);
    
signals:
    void        closeAll();
};

#endif
