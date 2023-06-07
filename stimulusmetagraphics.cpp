#include "stimulusmetagraphics.h"

StimulusmetaGraphics::StimulusmetaGraphics(QWidget *parent) : QWidget(parent)
{

}

void StimulusmetaGraphics::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int widgetWidth = parentWidget()->width();
    int widgetHeight = parentWidget()->height();
    int rectSize = 100;

    // 绘制上方矩形和三角形
    int rectUX = (widgetWidth - rectSize) / 2;
    int rectUY = 30;
    QRect topRect(rectUX, rectUY, rectSize, rectSize);
    painter.fillRect(topRect, rectColor[0]);
    painter.setPen(Qt::black);
    painter.drawRect(topRect);

    QPolygon topTriangle;
    topTriangle << QPoint(topRect.center().x(), topRect.top()+15)
                << QPoint(topRect.left()+15, topRect.bottom()-15)
                << QPoint(topRect.right()-15, topRect.bottom()-15);
    painter.drawPolygon(topTriangle);

    // 绘制下方矩形和三角形
    int rectDX = (widgetWidth - rectSize) / 2;
    int rectDY = widgetHeight  -130;
    QRect bottomRect(rectDX, rectDY, rectSize, rectSize);
    painter.fillRect(bottomRect, rectColor[2]);
    painter.setPen(Qt::black);
    painter.drawRect(bottomRect);

    QPolygon bottomTriangle;
    bottomTriangle << QPoint(bottomRect.center().x(), bottomRect.bottom()-15)
                   << QPoint(bottomRect.left()+15, bottomRect.top()+15)
                   << QPoint(bottomRect.right()-15, bottomRect.top()+15);
    painter.drawPolygon(bottomTriangle);

    // 绘制中间矩形和圆形
    int rectCX = (widgetWidth - rectSize) / 2;
    int rectCY = (widgetHeight - rectSize) / 2;
    QRect centerRect(rectCX, rectCY, rectSize, rectSize);
    painter.fillRect(centerRect, rectColor[4]);
    painter.setPen(Qt::black);
    painter.drawRect(centerRect);

    QPoint centerPoint(centerRect.center());
    int radius = rectSize / 3;
    QRect circleRect(centerPoint.x() - radius, centerPoint.y() - radius, radius * 2, radius * 2);
    painter.drawEllipse(circleRect);

    // 绘制左方矩形和三角形
    int rectLX = 100;
    int rectLY = (widgetHeight - rectSize) / 2;
    QRect leftRect(rectLX, rectLY, rectSize, rectSize);
    painter.fillRect(leftRect, rectColor[3]);
    painter.setPen(Qt::black);
    painter.drawRect(leftRect);

    QPolygon leftTriangle;
    leftTriangle << QPoint(leftRect.left()+15, leftRect.center().y())
                 << QPoint(leftRect.right()-15, leftRect.top()+15)
                 << QPoint(leftRect.right()-15, leftRect.bottom()-15);
    painter.drawPolygon(leftTriangle);

    // 绘制右方矩形和三角形
    int rectRX = widgetWidth-200;
    int rectRY = (widgetHeight - rectSize) / 2;
    QRect rightRect(rectRX, rectRY, rectSize, rectSize);
    painter.fillRect(rightRect, rectColor[1]);
    painter.setPen(Qt::black);
    painter.drawRect(rightRect);

    QPolygon rightTriangle;
    rightTriangle << QPoint(rightRect.right()-15, rightRect.center().y())
                  << QPoint(rightRect.left()+15, rightRect.top()+15)
                  << QPoint(rightRect.left()+15, rightRect.bottom()-15);
    painter.drawPolygon(rightTriangle);
}
