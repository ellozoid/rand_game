#ifndef RAND_GAME_H
#define RAND_GAME_H

#include <QDialog>

namespace Ui {
class rand_game;
}

class rand_game : public QDialog
{
    Q_OBJECT

public:
    explicit rand_game(QWidget *parent = 0);
    ~rand_game();

private:
    Ui::rand_game *ui;
};

#endif // RAND_GAME_H
