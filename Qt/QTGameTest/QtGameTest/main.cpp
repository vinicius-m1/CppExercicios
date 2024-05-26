#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
Prereqs:
-basic knowledge of c++ (pointers and memory management)
-VERY basic knowledge of Qt (widgets)
Tutorial Topics:
-QGraphicsScene
-QGraphicsItem (QGraphicsRectItem)
-QGraphicsView
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene

    MyRect * rect = new MyRect();

    rect->setRect(0,0,50,50);


    // add the item to the scene
    scene->addItem(rect);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    //rect->grabKeyboard();


    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    return a.exec();
}
