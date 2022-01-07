#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include "Figures.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QStyleOptionGraphicsItem>


class Shape : public QGraphicsItem
{
private:
    QPointF point;
    QPointF position;
    QColor color = "Black";

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);
    void MouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void MousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void MouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);

protected:
    QPainterPath path;
    QRectF bounding;
    Figure* Fig;

    Shape(QPoint position);

    void Update();
public:
    virtual ~Shape();
};

class CircleShape : public Shape
{
private:
    void setPaint();
public:
    CircleShape(Circle circle, QPoint position);
    ~CircleShape();
};

class TriangleShape : public Shape
{
private:
    void setPaint();
public:
    TriangleShape(Triangle triangle, QPoint position);
    ~TriangleShape();
};

class RectangleShape : public Shape
{
private:
    void setPaint();
public:
    RectangleShape(Rectangle rect, QPoint position);
    ~RectangleShape();
};

#endif // FIGUREITEM_H
