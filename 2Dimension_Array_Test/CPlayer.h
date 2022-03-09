#pragma once
#include "global.h"
#include "CObject.h"

class CPlayer :
    public CObject
{
private:
    bool click_toggle;

    HANDLE hd;
    INPUT_RECORD irInBuf;
    DWORD dwNOER;
    DWORD fdwSaveOldMode;

public:
    virtual void update();
    virtual void render();
    void consoleinit();

    CLONE(CPlayer);
public:
    CPlayer();
    ~CPlayer();
};

