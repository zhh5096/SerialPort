#ifndef STIMULUSMETAGRAPHICS_H
#define STIMULUSMETAGRAPHICS_H

#include <QWidget>
#include <QtWidgets>
#include "global_values.h"

class StimulusmetaGraphics : public QWidget
{
    Q_OBJECT

public:
    explicit StimulusmetaGraphics(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // STIMULUSMETAGRAPHICS_H
