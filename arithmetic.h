#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <QObject>
#include <QtMath>
#include "global_values.h"

class arithmetic : public QObject
{
    Q_OBJECT
public:
    explicit arithmetic(QObject *parent = nullptr);

signals:

private slots:
    void IBLS();
};

#endif // ARITHMETIC_H
