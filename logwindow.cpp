#include "logwindow.h"
#include "ui_logwindow.h"

logWindow::logWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logWindow)
{
    ui->setupUi(this);
    //instanceamos nuestra base de datos
    mdatabase = QSqlDatabase::addDatabase("QMYSQL");
    mdatabase.setHostName("localhost");
}

logWindow::~logWindow()
{
    delete ui;
}

void logWindow::on_pushButton_clicked()
{

    //Conectamos a la BD con los datos dados por la interfaz
    //el usuario debe existir en el SGBD

    //obtener el texto de la interfaz
    QString user = ui->lineedit_user->text();
    QString pass = ui->lineedit_pass->text();

    mdatabase.setUserName(user);
    mdatabase.setPassword(pass);

    if (!mdatabase.open()) {
        //QMessageBox::critical(this,"error",mdatabase.lastError().text());
        QString msg = "ERROR -> " + mdatabase.lastError().text();
        ui->label_stat->setText(msg);
    }
    else {
        //QMessageBox::about(this,"Conexion realizada","ningun problema");
        ui->label_stat->setText("ok -> todo bien");

    }
}
