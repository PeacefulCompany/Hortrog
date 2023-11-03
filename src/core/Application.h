#pragma once

class Application {
public:
    virtual void run() {
        init();
        while (!shouldQuit()) {
            gameLoop();
        }
        cleanup();
    }

protected:
    virtual bool shouldQuit() const = 0;
    virtual void gameLoop() = 0;
    virtual void init() = 0;
    virtual void cleanup() = 0;
};