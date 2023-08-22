#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(std::shared_ptr<Chat> chat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    if (chat)
        _chat = chat;
    else
        _chat = std::make_shared<Chat>();

    ui->loginWgt->setChat(chat);
    ui->registrationWgt->setChat(chat);

    connect(ui->loginWgt, &LoginForm::registrationRequested, this, &StartScreen::setRegistrationForm);
    connect(ui->loginWgt, &LoginForm::accept, this, &StartScreen::accept);
    connect(ui->loginWgt, &LoginForm::reject, this, &StartScreen::reject);
    connect(ui->registrationWgt, &RegistrationForm::loginRequested, this, &StartScreen::setLoginForm);
    connect(ui->registrationWgt, &RegistrationForm::accept, this, &StartScreen::accept);
    connect(ui->registrationWgt, &RegistrationForm::reject, this, &StartScreen::reject);
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::setLoginForm()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void StartScreen::setRegistrationForm()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void StartScreen::onLoggedIn()
{
    //accept();
}
