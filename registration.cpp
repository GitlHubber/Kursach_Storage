#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    connect(this, &Registration::asb, this, &Registration::sb);
    emit asb();
}

Registration::~Registration()
{
    delete ui;
}

void Registration::sb()
{
    qDebug() << "OK" << endl;
}

void Registration::on_regButton_clicked()
{
    Surname = ui->surnameEdit->text();
    Name = ui->nameEdit->text();
    ThirdName = ui->thirdnameEdit->text();
    login = ui->loginEdit->text();
    pass = ui->passEdit->text();

    if(Surname == "" || Name == "" || ThirdName == "" || login == "" || pass == "")
    {
        QMessageBox::critical(this, "Регистрация", "Ошибка! Не все поля введены!");
    }
    else
    {
         insert();
    }
}

void Registration::insert()
{
    query.prepare("INSERT INTO Пользователи(Фамилия, Имя, Отчество, Логин, Пароль)"
                  "VALUES(?, ?, ?, ?, ?)");
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    query.addBindValue(Surname);
    query.addBindValue(Name);
    query.addBindValue(ThirdName);
    query.addBindValue(login);
    query.addBindValue(pass);
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();



    if(query.exec() == true)
    {
        QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно!");
    }
    else
    {
        QMessageBox::critical(this, "Регистрация", "Ошибка базы данных!");
    }
}

void Registration::on_backButton_clicked()
{
    this->close();
    emit mainForm();
}
