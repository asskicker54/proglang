#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QToolBar>
#include <QInputDialog>
#include <QColorDialog>
#include "shapes.h"
#include <list>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QToolBar *toolbar;
    QGraphicsScene* scene;
    QString path;
public slots:
            void slotCreateCircle();
    void slotCreateTriangle();
    void slotCreateRectangle();
    void slotDelete();

};
#endif // MAINWINDOW_H
