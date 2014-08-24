#ifndef NODE_H
#define NODE_H

#include <QUuid>
#include <QObject>
#include <QDebug>
#include <QList>

class Node: QObject
{
    Q_OBJECT
public:
    Node(const QString& _name);
    ~Node();
    void connectTo(Node * _node);
private:

    QString name;
    QUuid *id;
    QList<Node *> upHierarchy;
    QList<Node *> downHierarchy;
};

#endif // NODE_H
