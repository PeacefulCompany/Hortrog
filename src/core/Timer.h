#pragma once

class Timer {
public:
    /**
     * @brief Construct a new Timer object
     *
     * @param duration The duration of the timer (in seconds)
     * @param completed Whether to initialise the timer as completed
     */
    Timer(float duration = 0, bool completed = false) : duration_(duration) {
        if (completed) current_ = duration;
    }

    /**
     * @brief Increments the current time of the timer
     *
     * @param dt The time (in seconds) since the last update
     */
    inline void update(float dt) { current_ += dt; }

    /**
     * @brief Checks whether the timer has expired
     */
    inline bool expired() const { return current_ >= duration_; }

    /**
     * @brief Resets the time on the timer
     */
    inline void reset() { current_ = 0; }

    /**
     * @brief Resets the timer, but maintains any residual time
     */
    inline void tick() { current_ -= duration_; }

    /**
     * @brief Retrieves the completion status as a percentage
     *
     * @return float The completion percentage in the range [0, 1]
     */
    inline float progress() const { return current_ / duration_; }

    inline void duration(float time) { duration_ = time; }
    inline float duration() const { return duration_; }

    inline float current() const { return current_; }
    inline float remaining() const { return duration_ - current_; }

private:
    float duration_;
    float current_ = 0;
};