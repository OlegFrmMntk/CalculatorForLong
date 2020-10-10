#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LongInteger.h"

using namespace std;

static LongInteger num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_000, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_000000, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_opposite, SIGNAL(clicked()), this, SLOT(opposite()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(opposite()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiplication, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multiplication->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = static_cast<QPushButton *>(sender());
    LongInteger all_numbers((ui->result_show->text() + button->text()).toStdString());

    QString new_label = "";
    string temp = all_numbers.getString();
    for (char sim : temp) {
        new_label += sim;
    }
    ui->result_show->setText(new_label);
}

void MainWindow::opposite()
{
    QPushButton *button = static_cast<QPushButton *>(sender());

    if (button->text() == "+/-") {
        LongInteger all_numbers((ui->result_show->text()).toStdString());
        all_numbers *= -1;

        QString new_label = "";
        string temp = all_numbers.getString();
        for (char sim : temp) {
         new_label += sim;
        }
        ui->result_show->setText(new_label);
    }
    else if (button->text() == "Del") {
        LongInteger all_numbers((ui->result_show->text()).toStdString());

        QString new_label = "";
        string temp = all_numbers.getString();
        if (temp.size() > 0) {
            temp.erase(temp.size() - 1, 1);
            if (temp.size() == 1 && temp[0] == '-') {
                temp = "";
            }
        }
        for (char sim : temp) {
            new_label += sim;
        }
        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = static_cast<QPushButton *>(sender());

    LongInteger a(ui->result_show->text().toStdString()), b;
    num_first = a;
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiplication->setChecked(false);
    ui->pushButton_division->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_answer_clicked()
{
    LongInteger labelNumber, num_second((ui->result_show->text()).toStdString());
    QString new_label;

    if (ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        string temp = labelNumber.getString();
        for (char sim : temp) {
         new_label += sim;
        }
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked()) {
        labelNumber = num_first - num_second;
        string temp = labelNumber.getString();
        for (char sim : temp) {
         new_label += sim;
        }
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_multiplication->isChecked()) {
        labelNumber = num_first * num_second;
        string temp = labelNumber.getString();
        for (char sim : temp) {
         new_label += sim;
        }
        ui->result_show->setText(new_label);
        ui->pushButton_multiplication->setChecked(false);
    }
    else if (ui->pushButton_division->isChecked()) {
        if (num_second == 0) {
            ui->result_show->setText("0");

        }
        else {
                labelNumber = num_first/num_second;

                string temp = labelNumber.getString();
                for (char sim : temp) {
                    new_label += sim;
                }
         ui->result_show->setText(new_label);
        }

        ui->pushButton_division->setChecked(false);
    }
}
