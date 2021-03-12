/**
 * File: MIAEncrypt.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description:
 */

#ifndef MIA2_MIAENCRYPT_HPP
#define MIA2_MIAENCRYPT_HPP

#include <string>
#include <vector>
#include "../FileUtils.hpp"


class Etaoin
{
    /**
     * The etaoinChar represents a single character of the Etaoin encoding.
     * This can be translated into any value within an extended ascii table.
     */
    typedef uint8_t etaoinChar;

    Etaoin() = default;

    explicit Etaoin(std::string input);

    ~Etaoin() = default;

    etaoinChar mirrorVertically(etaoinChar input);

    etaoinChar mirrorHorizontally(etaoinChar input);

    /**
     *
     */
     static char toEtaoin(const char& input);

    /**
     * This will take any english string and convert it to Etaoin.
     */
    static std::string toEtaoin(const std::string& input);


private:
    /**
     * This is the main container for the data contained by the Etaoin content.
     */
    std::vector<etaoinChar> data;

};

class MIAEncrypt
{
public:

    /**
     * Main constructor for the MIAEncrypt object.
     */
    MIAEncrypt() = default;

    /**
     * Main destructor of a MIAEncrypt object.
     */
     ~MIAEncrypt() = default;

    /**
     * This method will take a string and perform simple encryption on it.
     * @param input[std::string&] - A reference to a string to encrypt.
     * @return [std::string] - returns an encrypted string.
     */
    std::string encryptedString(const std::string& input);

protected:

private:

};

#endif //MIA2_MIAENCRYPT_HPP
