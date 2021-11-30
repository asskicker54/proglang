//
// Created by ass_kicker54 on 12/1/21.
//

#ifndef FIGURES_MAINWINDOW_H
#define FIGURES_MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QGraphicsScene>
#include <QToolBar>
#include "Figures.h"
//#include "ui_mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
    int w;
    int h;

    Ui::mainwindow *ui;
    QGraphicsScene *scene;
    QToolBar *toolBar;
    QList<QGraphicsItem *>figures;

public slots:
    void slotCreateCircle();
    void slotCreateTriangle();
    void slotCreateRing();
    void slotDelete();

};


#endif //FIGURES_MAINWINDOW_H
