#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Chat.h"

#include <QDialog>
#include <memory>

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(std::shared_ptr<Chat> chat = nullptr, QWidget *parent = nullptr);
    ~StartScreen();
    void setLoginForm();
    void setRegistrationForm();
    void onLoggedIn();

private:
    Ui::StartScreen *ui;
    std::shared_ptr<Chat> _chat;
};

#endif // STARTSCREEN_H
