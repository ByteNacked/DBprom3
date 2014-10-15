#include "storage.h"

Storage::Storage(QObject *parent) :
    QObject(parent)
{
    nf1 = new QVector<Node*>();
    nf2 = new QVector<Node*>();
    nf3 = new QVector<Node*>();
}

Storage &Storage::getInstance()
{
    static Storage theSingleInstance;
    return theSingleInstance;
}

Storage::~Storage()
{
    foreach (Node * n1, *nf1) {
        delete n1;
    }
    foreach (Node * n2, *nf2) {
        delete n2;
    }
    foreach (Node * n3, *nf3) {
        delete n3;
    }
    delete nf1;
    delete nf2;
    delete nf3;
}

const Node *Storage::addNode(const QString &name)
{
    Node * newnode = new Node(name);
    nf1->append(newnode);

    return newnode;
}

void Storage::deleteNode(const QString &uuid)
{
    //delete all links on him



    //delete node itself

}

void Storage::addConnection(const QUuid *masterNode, const QUuid *slaveNode)
{

}

void Storage::showAll() const
{
    foreach (Node *n1, *nf1) {
        n1->show();
    }
}




