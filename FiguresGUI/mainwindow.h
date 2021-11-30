#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qt5/QScreen>
#include "figures.h"
#include <QScreen>
#include <QToolBar>

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
    int h;
    int w;

    Ui::MainWindow *ui;
    QGraphic

};
#endif // MAINWINDOW_H
