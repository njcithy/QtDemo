#ifndef BATTERY_H
#define BATTERY_H

/**
 *  电池电量控制
 *  1. 可设置电池电量，动态切换电池电量变化。
 *  2. 可设置电池量警戒值。
 *  3. 可设置电池量正常颜色和报警颜色
 *  4. 可设置边框渐变颜色
 *  5. 设置电量变化时每次移动的步长
 *  6. 可设置边框圆角角度/背景进度圆角角度/头部圆角角度
 */

#include <QWidget>
#include <QTimer>

class Battery : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(qreal maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(qreal value READ getValue WRITE setValue)
    Q_PROPERTY(qreal alarmValue READ getAlarmValue WRITE setAlarmValue)

    Q_PROPERTY(qreal step READ getStep WRITE setStep)
    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int bgRadius READ getBgRadius WRITE setBgRadius)
    Q_PROPERTY(int headRadius READ getHeadRadius WRITE setHeadRadius)

    Q_PROPERTY(QColor borderColorStart READ getBorderStart WRITE setBorderStart)
    Q_PROPERTY(QColor borderColorEnd READ getBorderColorEnd WRITE setBorderColorEnd)

    Q_PROPERTY(QColor alarmColorStart READ getAlarmColorStart WRITE setAlarmColorStart)
    Q_PROPERTY(QColor alarmColorEnd READ getAlarmColorEnd WRITE setAlarmColorEnd)

    Q_PROPERTY(QColor normalColorStart READ getNormalColorStart WRITE setNormalColorStart)
    Q_PROPERTY(QColor normalColorEnd READ getNormalColorEnd WRITE setNormalColorEnd)

private:
    qreal minValue;
    qreal maxValue;
    qreal value;
    qreal alarmValue;

    qreal step;
    int borderRadius;
    int bgRadius;
    int headRadius;

    QColor borderColorStart;
    QColor borderColorEnd;

    QColor alarmColorStart;
    QColor alarmColorEnd;

    QColor normalColorStart;
    QColor normalColorEnd;

    bool isForward;
    qreal currentValue;
    QRectF batteryRect;
    QTimer *timer;

public:
    explicit Battery(QWidget *parent = nullptr);


    qreal getMinValue() const;
    qreal getMaxValue() const;
    qreal getValue() const;
    qreal getAlarmValue() const;

    qreal getStep() const;
    int getBorderRadius() const;
    int getBgRadius() const;
    int getHeadRadius() const;

    QColor getBorderColorStart() const;
    QColor getBorderColorEnd() const;

    QColor getAlarmColorStart() const;
    QColor getAlarmColorEnd() const;

    QColor getNormalColorStart() const;
    QColor getNormalColorEnd() const;

public slots:
    void setRange(qreal minValue, qreal maxValue);
    void setRange(int minValue, int maxValue);

    void setMinValue(qreal minValue);
    void setMaxValue(qreal maxValue);

    void setValue(qreal value);
    void setValue(int value);

    void setAlarmValue(qreal alarmValue);
    void setAlarmValue(int alarmValue);

    void setStep(qreal step);
    void setStep(int step);

    void setBorderRadius(int borderRadius);
    void setBgRadius(int bgRadius);
    void setHeadRadius(int headRadius);

    void setBorderColorStart(const QColor &borderColorStart);
    void setBorderColorEnd(const QColor &borderColorEnd);

    void setAlarmColorStart(const QColor &alarmColorStart);
    void setAlarmColorEnd(const QColor &alarmColorEnd);

    void setNormalColorStart(const QColor &normalColorStart);
    void setNormalColorEnd(const QColor &normalColorEnd);


signals:
    void valueChanged(qreal value);

private slots:
    void updateValue();

};

#endif // BATTERY_H
