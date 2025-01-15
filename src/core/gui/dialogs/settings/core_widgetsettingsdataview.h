#ifndef CORE_WIDGETSETTINGSDATAVIEW_H
#define CORE_WIDGETSETTINGSDATAVIEW_H

#include <QWidget>

#include <mbcore.h>

namespace Ui {
class mbCoreWidgetSettingsDataView;
}

class mbCoreWidgetSettingsDataView : public QWidget
{
    Q_OBJECT

public:
    explicit mbCoreWidgetSettingsDataView(QWidget *parent = nullptr);
    ~mbCoreWidgetSettingsDataView();

public: // properties
    mb::AddressNotation addressNotation() const;
    void setAddressNotation(mb::AddressNotation notation);
    QStringList getColumns() const;
    void setColumns(const QStringList &columns);

private Q_SLOTS:
    void slotEditColumns();

private:
    Ui::mbCoreWidgetSettingsDataView *ui;
};

#endif // CORE_WIDGETSETTINGSDATAVIEW_H
