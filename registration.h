#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

signals:
    void mainForm();
    void asb();

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:
    void on_regButton_clicked();
    void insert();
    void sb();

    void on_backButton_clicked();

private:
    Ui::Registration *ui;
    QString Surname;
    QString Name;
    QString ThirdName;
    QString login;
    QString pass;
    QSqlQuery query;

};

#endif // REGISTRATION_H
