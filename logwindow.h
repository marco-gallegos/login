#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>

namespace Ui {
class logWindow;
}

class logWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit logWindow(QWidget *parent = 0);
    ~logWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::logWindow *ui;
    QSqlDatabase mdatabase;
};

#endif // LOGWINDOW_H
