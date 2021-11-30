//
// Created by ass_kicker54 on 12/1/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include <QDialog>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow) {

        ui->setupUi(this);
    }

mainwindow::~mainwindow() {
    delete ui;
}
