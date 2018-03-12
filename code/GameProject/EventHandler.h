#ifndef EventHandler_H
#define EventHandler_H

class InputManager;

class EventHandler
{
public:
    void Init();
    void HandleEvents();

private:
	    
    void OnQuit();
};

#endif