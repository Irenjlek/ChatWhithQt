#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Chat.h"

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<Chat> chat = nullptr, QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* createClient(std::shared_ptr<Chat> chat);

private slots:
    void on_lineEditMessage_returnPressed();
    void on_sendAllBut_clicked();
    void on_sendPrivateBut_clicked();
    void on_actionOpen_another_client_triggered();
    void on_actionClose_this_client_triggered();

    void on_usersBox_currentTextChanged(const QString &arg1);

private:
    void fillComboBox();
    void fillMessagesForAll();
    void fillPrivateMessages();

    Ui::MainWindow *ui;
    std::shared_ptr<Chat> _chat;
};
#endif // MAINWINDOW_H
