#ifndef GAME_RECT_H
#define GAME_RECT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>


class game_rect : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    game_rect();
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void rectClicked();
};

#endif // GAME_RECT_H
