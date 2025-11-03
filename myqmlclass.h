#ifndef MYQMLCLASS_H
#define MYQMLCLASS_H

#include <QObject>

class MyQmlClass : public QObject
{
    Q_OBJECT
public:
    explicit MyQmlClass(QObject *parent = nullptr);
    Q_INVOKABLE void setValue(int value);
    Q_INVOKABLE int getValue();
private:
    int m_value;

signals:
};

#endif // MYQMLCLASS_H
