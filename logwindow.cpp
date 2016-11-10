#include "logwindow.h"
#include "ui_logwindow.h"

logWindow::logWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logWindow)
{
    ui->setupUi(this);
    mdatabase = QSqlDatabase::addDatabase("QMYSQL");
    mdatabase.setHostName("localhost");
}

logWindow::~logWindow()
{
    delete ui;
}

void logWindow::on_pushButton_clicked()
{
    QString user = ui->lineedit_user->text();
    QString pass = ui->lineedit_pass->text();

    mdatabase.setUserName(user);
    mdatabase.setPassword(pass);
    ui->label_stat->text().append("alo");
    if (!mdatabase.open()) {
        QMessageBox::critical(this,"error",mdatabase.lastError().text());
        QString msg = "ERROR -> " + mdatabase.lastError().text();
        ui->label_stat->setText(msg);
    }
    else {
        QMessageBox::about(this,"Conexion realizada","ningun problema");
        ui->label_stat->setText("ok -> todo bien");

    }
}
