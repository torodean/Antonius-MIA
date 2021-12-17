/**
 * File: MathUtils.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */


class MathUtils
{
public:

    MathUtils() = default;

    ~MathUtils() = default;

    /**
     * Generates a random integer between two values.
     * @param min[int] - lower bound value to use.
     * @param max[int] - higher bound to use.
     * @param seed[int] - a seed to randomize output.
     * @param useTime[bool] - uses teh time to determine the seed (default = true).
     * @return
     */
    static int randomInt(int min, int max, int seed, bool useTime = true);

/**
 * Rolls a dice based on input.
 * @param input[std::string&] - Input string. Must be of the form #d#, #d##, ##d##, etc.
 * @return [int] - returns the total dice roll.
 */
static int roll(const std::string &input);

protected:

private:

    /**
     * Returns a 1dXX dice roll total output.
     * @param xx[int] - Size of dice.
     * @param seed[int] - A seed ot use for randomization.
     * @return [int] returns the total.
     */
    static int rolldXX(int xx, int seed);
};

