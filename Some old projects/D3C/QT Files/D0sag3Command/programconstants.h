#ifndef PROGRAMCONSTANTS_H
#define PROGRAMCONSTANTS_H
#include <QString>


class ProgramConstants{
private:
    QString programVersion;
public:
    ProgramConstants();
    QString getProgramVersion();
    ~ProgramConstants();
};

#endif // PROGRAMCONSTANTS_H
