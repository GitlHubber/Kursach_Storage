#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:Users/Кирилл/Downloads/SQLiteDatabaseBrowserPortable/Data/DataBase.db");
    db.open();
    if(!db.isOpen())
    {
        ui->statusBar->showMessage("Подключение отсутствует!");
    }
    else
    {
        ui->statusBar->showMessage("Соединение с базой данных установлено!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QSqlQuery query;
    int temp = 0;
    int atemp = 0;

    login = ui->loginEdit->text();
    pass = ui->passEdit->text();

    if(login == "Admin")
    {
        QString aName;
        QString aPass;
        query.exec("SELECT Имя, Пароль FROM Пользователи");
        while(query.next())
        {
            aName = query.value(0).toString();
            aPass = query.value(1).toString();
            if(aName == "Admin" && pass == aPass)
            {
                QMessageBox::information(this, "Авторизация", "Авторизация продавца выполнена!");
                AW = new AdminWindow();
                AW->show();
                this->close();
                ++atemp;
            }
        }
        if(atemp == 0)
        {
            QMessageBox::critical(this, "Авторизация", "Ошибка ввода данных!");
            ui->loginEdit->clear();
            ui->passEdit->clear();
        }
    }
    else
    {
        query.exec("SELECT Логин, Пароль, id FROM Пользователи");
        while(query.next())
        {
            if(login == query.value(0).toString() && pass == query.value(1).toString())
            {
                QMessageBox::information(this, "Магазин", "Авторизация выполнена!");
                MF = new MainForm();
                MF->start(query.value(2).toString());
                MF->show();
                this->close();
                temp = 1;
            }
        }

        if(temp == 0)
        {
            QMessageBox::critical(this, "Магазин", "Неверно введены данные");
        }
    }
}

void MainWindow::on_regButton_clicked()
{
    RG = new Registration();
    connect(RG, &Registration::mainForm, this, &MainWindow::show);
    RG->show();
    this->close();
}
