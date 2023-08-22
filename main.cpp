#include "mainwindow.h"
#include "Chat.h"

#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<Chat> chat = std::make_shared<Chat>();

    auto w = MainWindow::createClient(chat);
    w->show();

    return a.exec();
}
