#ifndef EDITDETAILS_HPP
#define EDITDETAILS_HPP

#include "core/WinsockWrapper.h"
#include "core/ExportWrapper.h"

#include <gui/widgets/detailedit.hpp>

#include <QVariant>

namespace Ui {
class MTEditDetails;
}

class MTDetailEdit;
class Moneychanger;

// -----------------------------------------

template <class T> class VPtr
{
public:
    static T* asPtr(QVariant v)
    {
    return  (T *) v.value<void *>();
    }

    static QVariant asQVariant(T* ptr)
    {
    return qVariantFromValue((void *) ptr);
    }
};

// -----------------------------------------

class MTEditDetails : public QWidget
{
    Q_OBJECT

public:
    explicit MTEditDetails(QWidget *parent, MTDetailEdit & theOwner);
    virtual ~MTEditDetails();

    virtual void refresh(QString strID, QString strName)=0;
    virtual void AddButtonClicked()=0;
    virtual void DeleteButtonClicked()=0;

    virtual void ClearContents()=0;

    static QWidget * CreateDetailHeaderWidget(MTDetailEdit::DetailEditType theType,
                                              QString strID, QString strName,
                                              QString strAmount=QString(""),
                                              QString strStatus=QString(""),
                                              QString strPixmap=QString(""),
                                              bool bExternal=true);

    void SetOwnerPointer(MTDetailEdit & theOwner);

    // ----------------------------------
    // Only used on construction (aka when dialog() is called for first time.)
    //
    virtual int       GetCustomTabCount();
    virtual QWidget * CreateCustomTab (int nTab);
    virtual QString   GetCustomTabName(int nTab);
    // ----------------------------------
    void SetEditType(MTDetailEdit::DetailEditType theType) { m_Type = theType; }
    // ----------------------------------
signals:
    void NeedToUpdateMenu();
    void RefreshRecordsAndUpdateMenu();
    void DefaultAccountChanged(QString qstrID, QString qstrName);

    void ShowNym(QString);
    void ShowAsset(QString);
    void ShowServer(QString);
    void ShowAccount(QString);

    void SendFromAcct (QString qstrAcct);
    void RequestToAcct(QString qstrAcct);

    void newServerAdded(QString qstrID);
    void newAssetAdded(QString qstrID);
    void newNymAdded(QString qstrID);
    void newAccountAdded(QString qstrID);
    // OR:
    void serversChanged();
    void assetsChanged();
    void nymsChanged();
    void accountsChanged();

    void runSmartContract(QString qstrTemplate, QString qstrLawyer, int32_t index);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
//    void on_contactButton_clicked(bool checked = false);
//    void on_deleteButton_clicked(bool checked = false);
//    void on_acceptButton_clicked(bool checked = false);

protected:    
    QPointer<MTDetailEdit> m_pOwner;

    MTDetailEdit::DetailEditType m_Type;

private:
//    Ui::MTEditDetails *ui;
};

#endif // EDITDETAILS_HPP
