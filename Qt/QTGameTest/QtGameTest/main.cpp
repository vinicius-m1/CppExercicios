#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QImage>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene

    MyRect * rect = new MyRect();

    rect->setRect(0,0,30,10);
    QPen pen(Qt::NoPen); // remove ugly border
    rect->setPen(pen);
    // add the item to the scene
    scene->addItem(rect);
    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    //rect->grabKeyboard();


    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // hide scrollbar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    //definir tamanho da janela
    view->setFixedSize(800,600);

    //setando localizacao(na janela) e tamanho da cena
    scene->setSceneRect(0,0,800,600);

    rect->setPos(view->width()/2, view->height() - rect->rect().height());
    rect->setPos(370,65); //top middle
    scene->setBackgroundBrush(QBrush(QImage(":/images/Untitled.png")));


    // setting score panel
    rect->score = new QGraphicsTextItem;
    scene->addItem(rect->score);
    rect->score->setDefaultTextColor(Qt::white);
    QFont font("Helvetica", 16);
    font.setBold(true);
    rect->score->setFont(font);
    rect->score->setPos(700,111);

    rect->next_piece_pic = new QGraphicsRectItem;
    rect->next_piece_pic->setRect(690,145,60,60);
    rect->next_piece_pic->setPen(pen);

    scene->addItem(rect->next_piece_pic);

    return a.exec();
}
