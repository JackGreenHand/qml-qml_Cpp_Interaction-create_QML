#include "myqmlclass.h"

MyQmlClass::MyQmlClass(QObject *parent)
    : QObject{parent}
{}

void MyQmlClass::setValue(int value)
{
    m_value =value;
}
int MyQmlClass::getValue()
{

    return m_value;
}
