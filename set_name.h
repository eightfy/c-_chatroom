#ifndef SET_NAME_H
#define SET_NAME_H

#include <QWidget>

namespace Ui {
class set_name;
}

class set_name : private QWidget
{
    Q_OBJECT

public:
    QString name;
    explicit set_name(QWidget *parent = nullptr);
    ~set_name();
    int check();
    void showw();
private slots:
    void on_quit1_clicked();

    void on_ok1_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    int flag;
    int mode;
    Ui::set_name *ui;
};

#endif // SET_NAME_H
