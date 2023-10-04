#include <QWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[ ])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    window->setWindowTitle("Enter Your Name and Age");

    QLabel *label = new QLabel("<font color = red > Name </font>");
    QLineEdit *lineEdit = new QLineEdit;
    QLabel *label2 = new QLabel("<font color = yellow > Age </font>");
    QLabel *label3 = new QLabel("<font color = red > Greetings, my Overlord!</font>");
    QPushButton *button = new QPushButton("Send");

    QObject::connect(button, &QPushButton::clicked, [=]() {
        QString text = lineEdit->text();
        label3->setText("Greetings, " + text + "!");
    });

    QSpinBox *spinBox = new QSpinBox;
    spinBox->setValue(35);
    spinBox->setRange(0, 130);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int)));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(label);
    topLayout->addWidget(lineEdit);

    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralLayout->addWidget(label2);
    centralLayout->addWidget(spinBox);
    centralLayout->addWidget(slider);

    QHBoxLayout *downLayout = new QHBoxLayout;
    downLayout->addWidget(label3);

    QHBoxLayout *outLayout = new QHBoxLayout;
    outLayout->addWidget(button);

    QVBoxLayout *Layout = new QVBoxLayout;
    Layout->addLayout(topLayout);
    Layout->addLayout(centralLayout);
    Layout->addLayout(downLayout);
    Layout->addLayout(outLayout);

    window->setLayout(Layout);
    window->resize(400,100);

    window->show( );

    return app.exec( );
}

//QApplication app(argc, argv);

//QPushButton *button = new QPushButton("Quit");

//button->setCheckable(true);

//QObject::connect(button, &QPushButton::clicked, [&app, button]{
//    button->setChecked(true);
//    QTimer::singleShot(3000, &app, &QApplication::quit);
//});

//auto shortcutCtrlQ= new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), button);
//QObject::connect(shortcutCtrlQ, &QShortcut::activated,[&app]{app.quit();});

//auto shortcutEnter= new QShortcut(QKeySequence(Qt::Key_Return), button);
//QObject::connect(shortcutEnter, &QShortcut::activated,[&app]{app.quit();});

//button->resize(200, 60);
//button->show( );

//return app.exec( );

