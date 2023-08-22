#include "mainwindow.h"
#include "startscreen.h"
#include "ui_mainwindow.h"
#include "Chat.h"
#include "User.h"

MainWindow::MainWindow(std::shared_ptr<Chat> chat, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _chat(chat)
{
    ui->setupUi(this);
    fillComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::createClient(std::shared_ptr<Chat> chat = nullptr)
{
    StartScreen s(chat);
    auto result = s.exec();
    if (result == QDialog::Rejected)
        return nullptr;
    return new MainWindow(chat);
}


void MainWindow::on_lineEditMessage_returnPressed()
{
    on_sendAllBut_clicked();
}


void MainWindow::on_sendAllBut_clicked()
{
    _chat->writeToAll(ui->lineEditMessage->text().toStdString());
}


void MainWindow::on_sendPrivateBut_clicked()
{
    std::string text = ui->lineEditMessage->text().toStdString();
    std::shared_ptr<User> user = _chat->getUser(ui->usersBox->currentText().toStdString());
    _chat->writeToOne(text, user);
}


void MainWindow::on_usersBox_currentTextChanged(const QString &arg1)
{

}


void MainWindow::on_actionOpen_another_client_triggered()
{
    auto w = createClient();
    w->show();
}


void MainWindow::on_actionClose_this_client_triggered()
{

}

void MainWindow::fillComboBox()
{
    ui->usersBox->addItems(_chat->getAllLogins());
}

