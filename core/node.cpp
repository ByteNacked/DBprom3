#include "node.h"

Node::Node(const QString& _name):
    QObject(0), name(_name)
{
    id = new QUuid();
    id->createUuid();

//    qDebug() << name;
//    qDebug() << id;
}

Node::~Node()
{
    delete id;
}

void Node::connectTo(Node *_node)
{

}
