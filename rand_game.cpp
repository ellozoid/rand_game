#include "rand_game.h"
#include "ui_rand_game.h"
#include <QDebug>


rand_game::rand_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rand_game)
{
    ui->setupUi(this);
    rectRespawn = new QTimer(this);
    gameTimer = new QTimer(this);
    perThousand = new QTimer(this);
    scene = new QGraphicsScene(ui->graphicsView);
    gameRect = new game_rect();
    scene->addItem(gameRect);
    sceneW = ui->graphicsView->width();
    sceneH = ui->graphicsView->height();
    rectSize = 50;
    connect(ui->startButton, &QPushButton::clicked, this, &rand_game::startgame);
    connect(gameTimer, &QTimer::timeout, this, &rand_game::gameover);
    connect(rectRespawn, &QTimer::timeout, this, &rand_game::redraw);
    connect(perThousand, &QTimer::timeout, [=]() {
        ui->timeLabel->setText(QString::number(--labelTimer));
    });
    connect(gameRect, &game_rect::rectClicked, [=]() {
        points++;
        ui->scores_label->setText(QString("Points: ") + QString::number(points));
    });
}

rand_game::~rand_game()
{
    delete ui;
}

void rand_game::scoreup()
{
    points++;
    ui->scores_label->setText(QString("Points: ") + QString::number(points));
    qDebug() << "im here" << points;
}

void rand_game::startgame()
{
    ui->diffLabel->setVisible(0);
    ui->diffBox->setVisible(0);
    points = 0;
    ui->startButton->setVisible(0);
    ui->scoreLabel->setVisible(0); //Score after game
    ui->scores_label->setVisible(1);
    ui->scores_label->setText(QString("Points: ") + QString::number(points));
    gameTimer->start(30*1000);
    ui->timeLabel->setVisible(1);
    ui->timeLabel->setText("30");
    labelTimer = 30;
    perThousand->start(1000);
    if(ui->diffBox->currentText() == "Nightmare")
        rectRespawn->start(350);
    else if(ui->diffBox->currentText() == "Hard")
        rectRespawn->start(400);
    else if(ui->diffBox->currentText() == "Normal")
        rectRespawn->start(750);
    else if(ui->diffBox->currentText() == "Easy")
        rectRespawn->start(1000);
}

void rand_game::gameover()
{
    gameTimer->stop();
    perThousand->stop();
    rectRespawn->stop();
    scene->clear();
    ui->scores_label->setVisible(0);
    ui->startButton->setVisible(1);
    ui->scoreLabel->setText("Score: " + QString::number(points));
    ui->scoreLabel->setVisible(1);
    ui->timeLabel->setVisible(0);
    ui->diffLabel->setVisible(1);
    ui->diffBox->setVisible(1);
}
void rand_game::redraw(){
    //scene->clear();

    rectX = (qrand() % (sceneW - sceneW/4));
    rectY = (qrand() % (sceneH - sceneH/4));

    //game_rect* gameRect = new game_rect();
    gameRect->setPos(rectX, rectY);
    gameRect->update();

    //scene->addItem(gameRect);
    ui->graphicsView->setScene(scene);
}
