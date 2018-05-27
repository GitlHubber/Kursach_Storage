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

    login = ui->loginEdit->text();
    pass = ui->passEdit->text();

    query.exec("SELECT Логин, Пароль FROM Пользователи");
    while(query.next())
    {
        if(login == query.value(0).toString() && pass == query.value(1).toString())
        {
            QMessageBox::information(this, "Магазин", "Авторизация выполнена!");
            MF = new MainForm();
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

void MainWindow::on_regButton_clicked()
{
    RG = new Registration();
    connect(RG, &Registration::mainForm, this, &MainWindow::show);
    RG->show();
    this->close();
}
