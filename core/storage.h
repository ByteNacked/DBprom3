#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QVector>
#include <QDebug>


#include <core/node.h>
#include <core/nodecontainer.h>

class Storage : public QObject
{
    Q_OBJECT
public:
    static Storage& getInstance();
    ~Storage();
    const Node *addNode(const QString & name);
    void deleteNode(const QString & uuid);
    //void addConnection(const QList<Node *> masterNodes, const QList<Node *> slaveNodes);
    void addConnection(const QUuid *masterNode, const QUuid *slaveNode);
    void showAll() const ;

private:
    explicit Storage(QObject *parent = 0);
    QVector<Node*> *nf1;
    QVector<Node*> *nf2;
    QVector<Node*> *nf3;

signals:

public slots:

};

#endif // STORAGE_H
