#include <QApplication>
#include <QLabel>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.resize(250, 250);
    window.setWindowTitle("Figures");
    window.show();
    return app.exec();
}