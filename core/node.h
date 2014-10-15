#ifndef NODE_H
#define NODE_H

#include <QUuid>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QSharedPointer>

class Node: QObject
{
    Q_OBJECT
public:
    explicit Node(const QString& _name, QObject *parent = 0);
    ~Node();
    void connectTo(Node * masterNode);
    static void deleteConnections(Node * lNode, Node * rNode);
    void show() const;
    void showParrents() const;
    void showChildren() const;
    QUuid *getUuid() const; // Хз как это работает, по-моему неправильно

private:
    static bool deleteSingleConnection(Node * lNode, Node * rNode);
    static bool isConnectionUnique(Node * lNode, Node * rNode);
    QString name;
    QSharedPointer<QUuid> id;
    unsigned int lvl = 0;
    unsigned int graphN = 0;
    QList<Node *> parrentHierarchyList; // Детерминанты для связей с этим атрибутом
    QList<Node *> childHierarchyList;
};

#endif // NODE_H
