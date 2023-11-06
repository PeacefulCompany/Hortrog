#pragma once

class Application {
public:
    virtual void run() {
        init();
        while (isRunning()) {
            gameLoop();
        }
        cleanup();
    }

    inline void setRunning(bool r) { running_ = r; }
    inline bool isRunning() const { return running_; }

    virtual void gameLoop() = 0;
    virtual void init() = 0;
    virtual void cleanup() = 0;

private:
    bool running_ = true;
};