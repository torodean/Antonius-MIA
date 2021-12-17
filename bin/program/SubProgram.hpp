/**
 * File: SubProgram.hpp
 * Author: Antonius Torode
 * Creation Date: 03/01/2021
 * Description: This is the main sub-program class for MIA sub-programs.
 */

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