/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 12/23/2021
 * Description: This is a file for storing and dealing with credentials for a user.
 */

#include <string>

/**
 * This is a class for storing credentials for a user.
 */
class Credentials
{
public:
    /// Main default constructor for a Credentials object.
    Credentials() = default;
    ~Credentials()
    {
        clear();
    };

    Credentials(std::string user, std::string pw)
    {
        username = user;
        hash = hashPassword(pw);
    };

    /**
     * Set's the username of this object.
     * @param user std::string username to set.
     */
    void setUsername(std::string user)
    { username = user; }

    /**
     * This will set the hash value from a possword.
     * @param pw std::string password to set the hash value from.
     */
    void setPassword(std::string pw)
    { hash = hashPassword(pw); }

    /**
     * This will set the hash value to a hash that was already hashed from a password.
     * @param hashedPW
     */
    void setHash(std::string hashedPW)
    { hash = hashedPW; }

    /**
     * Clears the current user credential values.
     */
    void clear()
    {
        username.clear();
        hash.clear();
    };

    /// Returns the hash of the password for this user's crednetials.
    std::string getHash()
    { return hash; }

    /**
     * Checks a password to see if it matches the user's hashed credentials.
     * @param in std::string of the password to check against.
     * @return true if hash matches, false otherwise.
     */
    bool checkPassword(std::string pw)
    { return hashPassword(pw) == hash; }

    /**
     * Checks a hash to see if it matches the user's credentials.
     * @param in std::string of the hash to check against.
     * @return true if hash matches, false otherwise.
     */
    bool checkHash(std::string hashedPW)
    { return hashedPW == hash; }

private:
    /**
     * A method for turning a password into a hash string.
     * @param pw std::String password to hash.
     * @return returns the hash value.
     */
    std::string hashPassword(std::string pw)
    {
        //@TODO - write hashing algorithm.
        return pw;
    }

    std::string username;       ///< The username of the credentials.
    std::string hash;           ///< The hash associated with the password for the user.
};
