#pragma once
#include "global.h"
#include "CScene.h"

class CMainScene :
    public CScene
{
public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();

public:
    CMainScene();
    ~CMainScene();
};

