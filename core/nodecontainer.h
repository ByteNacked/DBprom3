#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QObject>
#include <QVector>
#include <QList>
#include <QDebug>

#include "core/node.h"

class NodeContainer : public QObject
{
    Q_OBJECT
public:
    explicit NodeContainer(QObject *parent = 0);
    void createNode(const QString& _name);
    void deleteNode(Node * _nodePtr);
//    void addNode()
//    deleteNode


private:
    unsigned int level;
    QVector<Node *> tree;
    QList<Node *> masterkey;

signals:

public slots:

};

#endif // NODECONTAINER_H
