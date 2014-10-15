#ifndef ADDATTRIBUTEDIALOG_H
#define ADDATTRIBUTEDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QUuid>
#include <QMessageBox>

#include "core/node.h"
#include "core/storage.h"

namespace Ui {
class AddAttributeDialog;
}

class AddAttributeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAttributeDialog(QWidget *parent = 0);
    ~AddAttributeDialog();

private slots:
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_CloseButton_clicked();

private:
    Ui::AddAttributeDialog *ui;
    QListWidget *lw;
};

#endif // ADDATTRIBUTEDIALOG_H
