#ifndef PARAMSSIMANN_H
#define PARAMSSIMANN_H

#include <QWidget>

namespace Ui {
class ParamsSimAnn;
}

class ParamsSimAnn : public QWidget
{
    Q_OBJECT

public:
    explicit ParamsSimAnn(QWidget *parent = 0);
    ~ParamsSimAnn();

private:
    Ui::ParamsSimAnn *ui;
};

#endif // PARAMSSIMANN_H