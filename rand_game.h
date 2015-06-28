#ifndef RAND_GAME_H
#define RAND_GAME_H

#include <QDialog>
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include "game_rect.h"


namespace Ui {
class rand_game;
}

class rand_game : public QDialog
{
    Q_OBJECT

public:
    explicit rand_game(QWidget *parent = 0);
    ~rand_game();
    void scoreup();
    int points; // count of points;

private:
    int rectX, rectY; // coord. of rect
    int rectSize; // width and height of rect
    int sceneW, sceneH; // size of scene
    Ui::rand_game *ui;
    QGraphicsScene* scene;
    QTimer* gameTimer;
    QTimer* rectRespawn;
    QTimer* perThousand;
    int labelTimer;
    game_rect* gameRect;

private slots:
    void startgame();
    void gameover();
    void redraw();
};

#endif // RAND_GAME_H
