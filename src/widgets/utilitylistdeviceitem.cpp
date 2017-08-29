#include "utilitylistdeviceitem.h"
#include "helper.h"

#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>

UtilityListDeviceItem::UtilityListDeviceItem(QWidget *parent)
    : UtilityListItem(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);

    m_progressBar = new QProgressBar(widget);
    m_progressBar->setRange(0, 100);
    m_progressBar->setTextVisible(false);
    m_sizeLabel = new QLabel(widget);

    layout->addWidget(m_sizeLabel, 0, Qt::AlignRight);
    layout->addWidget(m_progressBar, 0, Qt::AlignRight);

    addWidget(widget, 0, Qt::AlignRight);
}

void UtilityListDeviceItem::setSize(qint64 used, qint64 total)
{
    m_sizeLabel->setText(QString("%1/%2").arg(Helper::sizeDisplay(used)).arg(Helper::sizeDisplay(total)));
    m_progressBar->setValue(100 * ((used / 1000.0) / (total / 1000.0)));
}