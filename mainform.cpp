#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::start(QString id)
{
    ID = id;
    query.exec("SELECT Фамилия, Имя, Отчество FROM Пользователи WHERE id = '"+ID+"'");
    while(query.next())
    {
        ui->label->setText("Добро пожаловать, "+query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString());
    }
}
