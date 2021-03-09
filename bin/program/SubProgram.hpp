/**
 * File: SubProgram.cpp
 * Author: Antonius Torode
 * Date: 03/01/2021
 * Description:
 */

#ifndef MIA2_SUBPROGRAM_HPP
#define MIA2_SUBPROGRAM_HPP

#include <string>
#include <thread>

class SubProgram : public std::thread
{
public:

    /// Disallow the default constructor.
    SubProgram() = delete;

    /**
     * Main constructor for the SubProgram object.
     */
    explicit SubProgram(std::string programName = "MIA Sub-Program");

    /**
     * Main destructor for the SubProgram class.
     */
    ~SubProgram() = default;


protected:

private:

    /// A name for the SubProgram object.
    std::string subProgramName;

};

#endif //MIA2_SUBPROGRAM_HPP
