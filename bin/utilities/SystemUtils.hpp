/**
 * File: SystemUtils.hpp
 * Author: Antonius Torode
 * Date: 03/09/2021
 * Description:
 */

/**
 * This class contains system related functions.
 */
class SystemUtils
{
public:
    /**
     * Main default constructor for the SystemUtils object.
     */
    SystemUtils() = default;

    /**
     * Main destructor for the SystemUtils object.
     */
    ~SystemUtils() = default;

    /**
     * Causes the current thread to sleep.
     * @param time[int] - Time to sleep.
     */
    static void sleepMilliseconds(int time);

    /**
     * Causes the current thread to sleep.
     * @param time[int] - Time to sleep.
     */
    static void sleepMinutes(int time);

    /**
     * Causes the current thread to sleep.
     * @param time[int] - Time to sleep.
     */
    static void sleepSeconds(int time);

};
