#include "game_rect.h"
#include <QDebug>

game_rect::game_rect()
{
}

QRectF game_rect::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void game_rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    painter->setBrush(Qt::red);
    painter->drawRect(rect);
}

void game_rect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    emit rectClicked();
}


