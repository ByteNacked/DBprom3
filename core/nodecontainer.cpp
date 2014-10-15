#include "nodecontainer.h"

NodeContainer::NodeContainer(QObject *parent) :
    QObject(parent), level(0)
{



}

void NodeContainer::createNode(const QString &_name)
{
    Node * newnode = new Node(_name, this);
    tree.append(newnode);
}
