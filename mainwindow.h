#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "mainform.h"
#include "registration.h"
#include "adminwindow.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSqlDatabase db;
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_regButton_clicked();

private:
    Ui::MainWindow *ui;
    QString login;
    QString pass;
    MainForm *MF;
    Registration *RG;
    AdminWindow *AW;
};

#endif // MAINWINDOW_H
