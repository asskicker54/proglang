#include "shapes.h"

Shape::Shape(QPoint position)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->position = position;
    setPos(position);
}

void Shape::Update()
{
    QString InfoCoor = QString("\nCoordinates: %1, %2").arg(position.x()).arg((position.y()));
    QString InfoFigure = QString("S = %1\nP = %2").arg(Fig->CalcArea()).arg(Fig->CalcPerimetr());
    setToolTip(InfoFigure + InfoCoor);
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawPath(path);
    if(isSelected() == true)
    {
        painter->restore();
        painter->setPen(QPen(Qt::DashLine));
        painter->drawRect(bounding);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Shape::boundingRect() const
{
    return QRectF(bounding);
}

Shape::~Shape(){}

void Shape::MousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    point = mouseEvent->pos();
    if (mouseEvent->button() == Qt::RightButton)
    {
        setSelected(!isSelected());
    }
    else
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
}

void Shape::MouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    setPos(QPoint(mouseEvent->scenePos().x()- point.x(),mouseEvent->scenePos().y()-point.y()));
    position = mouseEvent->scenePos();
}

void Shape::MouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Update();
    Q_UNUSED(mouseEvent);
}

CircleShape::CircleShape(Circle circle, QPoint position) : Shape(position)
{
    Fig = new Circle(circle);
    setPaint();
    Update();
}

void CircleShape::setPaint()
{
    path = QPainterPath();
    int r = ((Circle*)Fig)->GetR();
    path.addEllipse(0, 0, r, r);
    bounding = QRectF(QGraphicsEllipseItem(0, 0, r, r).boundingRect());
}

CircleShape::~CircleShape()
{
    delete (Circle*)Fig;
}

TriangleShape::TriangleShape(Triangle triangle, QPoint position) : Shape(position)
{
    Fig = new Triangle(triangle);
    setPaint();
    Update();
}

void TriangleShape::setPaint()
{
    path = QPainterPath();
    int x1, y1, x2, y2, x3, y3;
    ((Triangle*)Fig)->GetCoordinates(x1, y1, x2, y2, x3, y3);
    path.addPolygon(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3)}));
    bounding = QRectF(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3)}).boundingRect());
}

TriangleShape::~TriangleShape()
{
    delete (Triangle*)Fig;
}

RectangleShape::RectangleShape(Rectangle rect, QPoint position) : Shape(position)
{
    Fig = new Rectangle(rect);
    setPaint();
    Update();
}

void RectangleShape::setPaint()
{
    path = QPainterPath();
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    ((Rectangle*)Fig)->GetCoordinates(x1, y1, x2, y2, x3, y3, x4, y4);
    path.addPolygon(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3), QPoint(x4, y4)}));
    bounding = QRectF(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3), QPoint(x4, y4)}).boundingRect());
}

RectangleShape::~RectangleShape()
{
    delete (Rectangle*)Fig;
}
