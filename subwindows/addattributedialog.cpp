#include "addattributedialog.h"
#include "ui_addattributedialog.h"

AddAttributeDialog::AddAttributeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAttributeDialog)
{
    ui->setupUi(this);
    lw = ui->listWidget;
}

AddAttributeDialog::~AddAttributeDialog()
{
    delete ui;
}

void AddAttributeDialog::on_AddButton_clicked()
{
    QString text = ui->lineEdit->text();
    const Node *newnode = Storage::getInstance().addNode(text);
    QUuid *id = newnode->getUuid();
    QListWidgetItem *item = new QListWidgetItem(text);
    QString stringUuid = id->toString();
    item->setData(Qt::UserRole, QVariant(stringUuid) );
    lw->addItem(item);
}

void AddAttributeDialog::on_DeleteButton_clicked()
{
    if ( lw->currentRow() == -1)    {
        QMessageBox::information(this, tr(""), tr("Для удаления сначала выберите нужный атрибут."));
        return;
    }

    auto result = QMessageBox::question(this, "", tr("Удалить выбранный атрибут?"));
    if ( result == QMessageBox::No) return;

    QListWidgetItem *delItem = lw->takeItem(lw->row(lw->currentItem()));
    QString deletedItemUuid = delItem->data(Qt::UserRole).toString();
    qDebug() << deletedItemUuid;


}

void AddAttributeDialog::on_CloseButton_clicked()
{
    close();
}
