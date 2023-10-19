#pragma once

class Timer {
public:
    /**
     * @brief Construct a new Timer object
     *
     * @param time The initial time of the timer
     * @param completed Whether to start the timer in a completed state
     */
    Timer(float time = 0, bool completed = false) : m_time(time) {
        if (completed) m_current = time;
    }

    /**
     * @brief Updates the current time of the timer
     *
     * @param dt The time (in seconds) since the last update
     */
    inline void update(float dt) { m_current += dt; }

    /**
     * @brief Checks whether the timer is complete
     */
    inline bool isComplete() const { return m_current >= m_time; }

    /**
     * @brief Resets the time on the timer
     */
    inline void reset() { m_current = 0; }

    /**
     * @brief REsets the time on the timer
     */
    inline void tick() { m_current -= m_time; }

    inline void setTime(float time) { m_time = time; }
    inline float getTime() const { return m_time; }
    inline float getCurrent() const { return m_current; }

    /**
     * @brief Retrieves the completion status as a percentage
     *
     * @return float The completion percentage in the range [0, 1]
     */
    inline float getProgress() const { return m_current / m_time; }

private:
    float m_time;
    float m_current = 0;
};