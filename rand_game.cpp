#include "rand_game.h"
#include "ui_rand_game.h"

rand_game::rand_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rand_game)
{
    ui->setupUi(this);
}

rand_game::~rand_game()
{
    delete ui;
}
