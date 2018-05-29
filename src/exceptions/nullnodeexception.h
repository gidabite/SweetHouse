#ifndef NULLNODEEXCEPTION_H
#define NULLNODEEXCEPTION_H

#include <QException>

class NullNodeException : public QException
{
public:
    void raise() const { throw *this; }
    NullNodeException *clone() const { return new NullNodeException(*this); }
};

#endif // NULLNODEEXCEPTION_H
