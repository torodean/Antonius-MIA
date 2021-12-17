/**
 * File: MIAWorkout.hpp
 * Author: Antonius Torode
 * Date: 03/07/2021
 * Description:
 */

#include "../program/Configurator.hpp"

class MIAWorkout
{
public:

    MIAWorkout() = default;

    ~MIAWorkout() = default;

    /**
     * Returns a workout generated based on a difficulty.
     * @param difficulty
     * @param weekly
     */
    void generateWorkout(double difficulty, bool weekly) const;

protected:

private:

    Configurator config;

    /**
     * Convert input file line to proper format (doubles.
     * @param line
     * @return
     */
    static double convertWorkoutWeight(const std::string& line);

    /**
     * Returns the maximumNumberOfXXX based on a difficulty.
     * Custom formula chosen for desired workout curves.
     * @param min
     * @param max
     * @param difficulty
     * @return
     */
    static double maxNumModifier(double min, double max, double difficulty);

    /**
     * Returns the manimumNumberOfXXX based on a difficulty.
     * Custom formula chosen for desired workout curves.
     * @param min
     * @param max
     * @param difficulty
     * @return
     */
    static double minNumModifier(double min, double max, double difficulty);
};
