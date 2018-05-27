#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QSqlQuery>

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

public slots:
    void start(QString id);
private:
    Ui::MainForm *ui;
    QString ID;
    QSqlQuery query;
};

#endif // MAINFORM_H
