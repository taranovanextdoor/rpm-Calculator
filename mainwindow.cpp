#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button_0, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_1, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_2, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_3, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_4, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_5, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_6, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_7, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_8, SIGNAL(clicked()), this, SLOT(digits_numbers()) );
    connect(ui->button_9, SIGNAL(clicked()), this, SLOT(digits_numbers()) );

    //number conversations
    connect(ui->button_sign, SIGNAL(clicked()), this, SLOT(operations()) );
    connect(ui->button_percent, SIGNAL(clicked()), this, SLOT(operations()) );

    //standart math operations
    connect(ui->butt_divide, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->butt_multiply, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->butt_minus, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->butt_plus, SIGNAL(clicked()), this, SLOT(math_operations()) );

    //extra math operations
    connect(ui->button_root, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->butt_stepen, SIGNAL(clicked()), this, SLOT(math_operations()) );

    //single math opearations
    connect(ui->button_tg, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(math_operations()) );
    connect(ui->button_log, SIGNAL(clicked()), this, SLOT(math_operations()) );


    ui->butt_divide->setCheckable(true);
    ui->butt_multiply->setCheckable(true);
    ui->butt_minus->setCheckable(true);
    ui->butt_plus->setCheckable(true);

    ui->button_root->setCheckable(true);
    ui->butt_stepen->setCheckable(true);
    ui->button_log->setCheckable(true);
    ui->button_tg->setCheckable(true);
    ui->button_cos->setCheckable(true);
    ui->button_sin->setCheckable(true);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;

    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_label = ui->result_show->text() + button->text();
    }else{
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers,'g', 15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_butt_comma_clicked(){
    if( ! (ui->result_show->text().contains('.'))) {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}


void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    all_numbers = ( ui->result_show->text() ).toDouble();
    if(button->text() == "+/-"){
        all_numbers = all_numbers * -1;
    }else if(button->text() == "%"){
        all_numbers = all_numbers * 0.01;
    }
    new_label = QString::number(all_numbers,'g', 15);
    ui->result_show->setText(new_label);
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_button_AC_clicked(){
    ui->butt_plus->setChecked(false);
    ui->butt_minus->setChecked(false);
    ui->butt_multiply->setChecked(false);
    ui->butt_divide->setChecked(false);

    ui->butt_stepen->setChecked(false);
    ui->button_root->setChecked(false);
    ui->button_log->setChecked(false);
    ui->button_tg->setChecked(false);
    ui->button_cos->setChecked(false);
    ui->button_sin->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_butt_ravno_clicked(){
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if( ui->butt_plus->isChecked() ){

        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_plus->setChecked(false);

    }else if( ui->butt_minus->isChecked() ){

        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_minus->setChecked(false);

    }else if( ui->butt_multiply->isChecked() ){

        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_multiply->setChecked(false);

    }else if( ui->butt_divide->isChecked() ){
        if(num_second != 0){
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber,'g',15);
            ui->result_show->setText(new_label);
        }else{
            ui->result_show->setText("attempt to divide on zero");
        }
        ui->butt_divide->setChecked(false);


    }else if( ui->button_root->isChecked() ){

        labelNumber = pow(num_first, (1/num_second));
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->button_root->setChecked(false);

    }else if( ui->butt_stepen->isChecked() ){

        labelNumber = pow(num_first, num_second);
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_stepen->setChecked(false);

    }else if( ui->button_sin->isChecked() ){

        labelNumber = qSin(num_first);
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_stepen->setChecked(false);

    }else if( ui->button_cos->isChecked() ){
        
        labelNumber = qCos(num_first);
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_stepen->setChecked(false);

    }else if( ui->button_tg->isChecked() ){
            
        labelNumber = qTan(num_first);
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->butt_stepen->setChecked(false);
    
    }
}




