#include "WindowMain.h"
#include "ui_WindowMain.h"

//Public functions
WindowMain::WindowMain(QWidget *parent) : QMainWindow(parent), v_ui(new Ui::WindowMain) {
    this->v_ui->setupUi(this);
}

WindowMain::~WindowMain() {
    delete this->v_ui;
}

