#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Shapes.h"
#include <QFormLayout>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QSvgGenerator>
#include <QGraphicsView>
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Figures");


    toolbar = addToolBar("toolbar");
    toolbar->isRightToLeft();

    QAction* createCircle = toolbar->addAction("Circle");
    connect(createCircle, SIGNAL(triggered()), this, SLOT(slotCreateCircle()));

    QAction* createTriangle = toolbar->addAction("Triangle");
    connect(createTriangle, SIGNAL(triggered()), this, SLOT(slotCreateTriangle()));

    QAction* createRectangle = toolbar->addAction("Rectangle");
    connect(createRectangle, SIGNAL(triggered()), this, SLOT(slotCreateRectangle()));

    QAction* Del = toolbar->addAction("Delete");
    connect(Del, SIGNAL(triggered()), this, SLOT(slotDelete()));

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(ui->graphicsView->rect());
    setCentralWidget(ui->graphicsView);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    qDeleteAll(scene->items());
    delete ui;
    delete toolbar;
    delete scene;
}

void MainWindow::slotCreateCircle()
{
    bool ok;
    int r = QInputDialog::getInt(this,"Circle", "Radius", 0, 1, 1000, 1, &ok);
    if(ok)
    {
        CircleShape* circleItem = new CircleShape(Circle(r), QPoint(0, 0));
        scene->addItem(circleItem);
    }
}

void MainWindow::slotCreateTriangle()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Triangle");

    QFormLayout* formLayout = new QFormLayout();

    QSpinBox* X1 = new QSpinBox();
    X1->setMinimum(0);
    X1->setMaximum(1000);

    QSpinBox* Y1 = new QSpinBox();
    Y1->setMinimum(0);
    Y1->setMaximum(1000);

    QSpinBox* X2 = new QSpinBox();
    X2->setMinimum(0);
    X2->setMaximum(1000);

    QSpinBox* Y2 = new QSpinBox();
    Y2->setMinimum(0);
    Y2->setMaximum(1000);

    QSpinBox* X3 = new QSpinBox();
    X3->setMinimum(0);
    X3->setMaximum(1000);

    QSpinBox* Y3 = new QSpinBox();
    Y3->setMinimum(0);
    Y3->setMaximum(1000);

    formLayout->addRow("x1", X1);
    formLayout->addRow("y1:", Y1);
    formLayout->addRow("x2:", X2);
    formLayout->addRow("y2:", Y2);
    formLayout->addRow("x3:", X3);
    formLayout->addRow("y3:", Y3);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    formLayout->addWidget(buttonBox);
    dialog->setLayout(formLayout);

    int result = dialog->exec();

    if(result == QDialog::Accepted)
    {
        try
        {
            TriangleShape* triangleItem = new TriangleShape(Triangle(X1->value(), Y1->value(),X2->value(), Y2->value(),X3->value(), Y3->value()), QPoint(0, 0));
            scene->addItem(triangleItem);
        }
        catch(...) {}
    }

    delete X1;
    delete Y1;
    delete X2;
    delete Y2;
    delete X3;
    delete Y3;
    delete formLayout;
    delete buttonBox;
    delete dialog;
}

void MainWindow::slotCreateRectangle()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Rectangle");

    double v1 = QInputDialog::getDouble(0, "Input", "Height", 100);
    double v2 = QInputDialog::getDouble(0, "Input", "Weight", 100);

    try
    {
        RectangleShape* rect = new RectangleShape(Rectangle(v1, v2), QPoint(0, 0));
        scene->addItem(rect);
    }
    catch(...) {}
}




void MainWindow::slotDelete()
{
    qDeleteAll(scene->selectedItems());
}
