#include "node.h"

Node::Node(const QString& _name, QObject *parent):
    QObject(parent), name(_name)
{
    id = QSharedPointer<QUuid> (new QUuid( QUuid::createUuid()));
}

Node::~Node()
{
    //qDebug() << "&&NODEINFO: DELETED" << this << "this node deleted";
}

void Node::connectTo(Node * masterNode)
{
    bool flag = Node::isConnectionUnique(this, masterNode);
    if (!flag) {
        this->parrentHierarchyList.append(masterNode);
        masterNode->childHierarchyList.append(this);
        qDebug() << "&&NODEINFO: Node" << this->name << *(this->id) << " connected to "<< masterNode->name << *(masterNode->id);
    }
    else qDebug() << "&&NODEINFO: Warining! Node" << this->name << *(this->id) << " ALREADY connected to "<< masterNode->name << *(masterNode->id);

}

void Node::deleteConnections(Node *lNode, Node *rNode)
{
    bool flag;
    flag = deleteSingleConnection(lNode, rNode);
    if (!flag) deleteSingleConnection(rNode, lNode);
    if (flag) {
        qDebug() << "&&NODEINFO: Deleted connection between" << lNode->name << *(lNode->id) << rNode->name << *(rNode->id);
    }
    else qDebug() << "&&NODEINFO: Nothing to delete, no connection between"
                                       << lNode->name << *(lNode->id) << rNode->name << *(rNode->id);

}

void Node::showParrents() const
{
    qDebug() << "*********************************";
    qDebug() << "&&NODEINFO: PARRENTS of " << this->name << " " << *id;
    foreach (Node * n1, parrentHierarchyList) {
        qDebug() << "&&NODEINFO: " << n1->name << " " << *id;

    }
    qDebug() << "*********************************";
}

void Node::showChildren() const
{
    qDebug() << "*********************************";
    qDebug() << "&&NODEINFO: CHILDREN of " << this->name << " " << *id;
    foreach (Node * n1, childHierarchyList) {
        qDebug() << "&&NODEINFO: " << n1->name << " " << *id;
    }
    qDebug() << "*********************************";
}

QUuid *Node::getUuid() const
{
    return id.data();
}

bool Node::deleteSingleConnection(Node *lNode, Node *rNode)
{
    QList<Node *>::iterator iterator_1 = std::find(lNode->parrentHierarchyList.begin(),
                                                   lNode->parrentHierarchyList.end(), rNode);
    if (iterator_1 == lNode->parrentHierarchyList.end() )
    {
        return false;
    }
    else
    {
        lNode->parrentHierarchyList.erase(iterator_1);
        iterator_1 = std::find(rNode->childHierarchyList.begin(), rNode->childHierarchyList.end(), lNode);
        if (iterator_1 != rNode->childHierarchyList.end() ) rNode->childHierarchyList.erase(iterator_1);
    }
    return true;
}

//Hope no broken connection and this gonna be enough
bool Node::isConnectionUnique(Node *lNode, Node *rNode)
{
    QList<Node *>::iterator iterator_1 = std::find(lNode->parrentHierarchyList.begin(),
                                                   lNode->parrentHierarchyList.end(), rNode);
    if (iterator_1 == lNode->parrentHierarchyList.end() )
    {
        return false;
    }

    return true;
}

void Node::show() const
{
    qDebug() << name;
    qDebug() << *id;
    qDebug() << "***";
}
